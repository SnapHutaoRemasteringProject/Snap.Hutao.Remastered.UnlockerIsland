// ============================================================================
// HookCore.cpp —— 日志落盘、过滤表、统计、MinHook 安装。
//
// 设计取向：
//   * 每个 detour 只做「格式化到栈缓冲 + 一次 fwrite」；不加锁的部分全是无锁的
//     原子/线程局部量，避免把 434 个钩子变成串行瓶颈；
//   * 落盘走全局递归锁（日志函数自己也可能被钩子触发，递归锁防自锁）；
//   * 逐行 fflush：游戏崩了也能拿到死前的最后几行 —— 这是排查 hook 现场的关键。
// ============================================================================
#include "HookCore.h"

#include <Windows.h>
#include <MinHook.h>

#include <cstdio>
#include <cstdarg>
#include <cstring>
#include <mutex>
#include <string>
#include <vector>

namespace jk {

// ---------------------------------------------------------------------------
//  常量 / 全局状态
// ---------------------------------------------------------------------------
constexpr int kJkMaxHooks   = 1024;   // 生成表最多能装多少条
constexpr int kJkMaxDepth   = 16;     // 超过这个嵌套深度的调用不再打日志（每层 detour 占 8 KB 栈）
constexpr int kJkStrLimit   = 400;    // 单个字符串参数最多打多少字节

static const HookDef* g_defs  = nullptr;
static int            g_count = 0;

static std::atomic<uint32_t> g_calls[kJkMaxHooks];   // 调用次数（永远统计）
static std::atomic<uint32_t> g_lines[kJkMaxHooks];   // 实际打出日志的次数
static uint8_t               g_enabled[kJkMaxHooks]; // 1 = 打日志

static std::atomic<bool>     g_on{false};
static std::atomic<uint64_t> g_seq{0};
static std::atomic<uint64_t> g_emitted{0};   // 已写出的行数（决定刷盘策略）
static std::recursive_mutex  g_mu;
static FILE*                 g_fp = nullptr;
static bool                  g_echo = false;
static ULONGLONG             g_startMs = 0;
static std::string           g_dir;

static thread_local int t_depth = 0;

// ---------------------------------------------------------------------------
//  LineBuf
// ---------------------------------------------------------------------------
void LineBuf::flt(double v, int prec) {
    char t[64];
    int n = snprintf(t, sizeof t, "%.*g", prec, v);
    if (n > 0) write(t, (size_t)n < sizeof t ? (size_t)n : sizeof t - 1);
}

// ---------------------------------------------------------------------------
//  托管字符串 -> 带转义的 UTF-8
// ---------------------------------------------------------------------------
namespace {

// 只碰裸指针，所以可以安全地用 __try（绝不允许在这里引入带析构的局部量）。
void put_escaped(LineBuf& b, const char* s, int n, bool truncated) {
    b.put('"');
    for (int i = 0; i < n; ++i) {
        unsigned char c = (unsigned char)s[i];
        switch (c) {
        case '"':  b.puts("\\\""); break;
        case '\\': b.puts("\\\\"); break;
        case '\n': b.puts("\\n");  break;
        case '\r': b.puts("\\r");  break;
        case '\t': b.puts("\\t");  break;
        default:
            if (c < 0x20 || c == 0x7f) {
                static const char kHex[] = "0123456789abcdef";
                b.puts("\\x");
                b.put(kHex[c >> 4]);
                b.put(kHex[c & 0xF]);
            } else {
                b.put((char)c);
            }
        }
    }
    if (truncated) b.puts("...");
    b.put('"');
}

}  // namespace

void fmt_string(LineBuf& b, const Il2CppString* s) {
    if (!s) { b.puts("null"); return; }

    wchar_t wbuf[256];
    int     wlen = 0;
    bool    truncated = false;

    __try {
        int len = s->length;
        if (len < 0) len = 0;
        if (len > (int)(sizeof(wbuf) / sizeof(wbuf[0]) - 1)) {
            len = (int)(sizeof(wbuf) / sizeof(wbuf[0]) - 1);
            truncated = true;
        }
        wlen = len;
        for (int i = 0; i < len; ++i) wbuf[i] = (wchar_t)s->chars[i];
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        b.puts("<bad-string>");
        return;
    }

    if (wlen <= 0) { b.puts("\"\""); return; }

    char u8[1024];
    int  need = WideCharToMultiByte(CP_UTF8, 0, wbuf, wlen, u8, (int)sizeof(u8), nullptr, nullptr);
    if (need < 0) need = 0;
    if (need > (int)sizeof(u8)) need = (int)sizeof(u8);

    int n = need;
    if (n > kJkStrLimit) { n = kJkStrLimit; truncated = true; }
    put_escaped(b, u8, n, truncated);
}

// ---------------------------------------------------------------------------
//  调用深度
// ---------------------------------------------------------------------------
DepthGuard::DepthGuard()  { ++t_depth; }
DepthGuard::~DepthGuard() { --t_depth; }

const FnDesc* DescOf(int id) {
    if (id < 0 || id >= g_count) return nullptr;
    return g_defs[id].desc;
}

// ---------------------------------------------------------------------------
//  初始化 / 关闭
// ---------------------------------------------------------------------------
static std::string path_join(const char* dir, const char* leaf) {
    std::string s(dir ? dir : "");
    if (!s.empty() && s.back() != '\\' && s.back() != '/') s.push_back('\\');
    s += leaf;
    return s;
}

// 把函数表写成人类可读清单：id / RVA / 原始 C# 签名
static void write_signature_table() {
    std::string p = path_join(g_dir.c_str(), "signatures.txt");
    FILE* fp = nullptr;
    fopen_s(&fp, p.c_str(), "wb");
    if (!fp) return;

    if (g_count <= 0) {
        // 顺序错了（钩子表还没登记）就会走到这里：写出来的是空表，filter 也会失效。
        fprintf(fp, "# [ERROR] 钩子表还没登记（g_count = 0）——必须先 RegisterHookTable/Register*Hooks\n");
        fclose(fp);
        printf("[ERROR] 钩子表还没登记，signatures.txt 只能是空表\n");
        return;
    }

    SYSTEMTIME st;
    GetLocalTime(&st);
    fprintf(fp, "# JKKBGKIAFCO hook table — %04d-%02d-%02d %02d:%02d:%02d\n",
            st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
    fprintf(fp, "# 共 %d 个方法；RVA 是 imagebase=0 时的地址（== IDA 地址），\n", g_count);
    fprintf(fp, "# 运行期真实地址 = 主模块基址 + RVA。\n");
    fprintf(fp, "#\n# id     RVA         方法 / 原始签名\n");
    for (int i = 0; i < g_count; ++i) {
        const FnDesc* d = g_defs[i].desc;
        if (!d) continue;
        fprintf(fp, "#%03d  0x%08x  %s\n", i, d->rva, d->sig ? d->sig : d->name);
    }
    fclose(fp);
    printf("[INFO] hook 表已写出：%s（%d 条）\n", p.c_str(), g_count);
}

// ---------------------------------------------------------------------------
//  filter.txt：白名单 + 黑名单
//
//    NAME            只记录这些（写了一条白名单，其余全部关掉）
//    NAM*            前缀通配
//    #012            按 id
//    !NAME / -NAME   排除（黑名单里命中的一律不记录）
//    !#012           按 id 排除
//    ; 或 // 或 # 后面不是数字  -> 注释；行尾也可以跟 ; , # 注释
//
//  只有黑名单时：默认全开，再把黑名单关掉（"排除掉高频方法"就是这个用法）。
//  白名单和黑名单混用：先按白名单开，再按黑名单关 —— 黑名单优先。
// ---------------------------------------------------------------------------
enum RuleKind { RULE_SKIP, RULE_INCLUDE, RULE_EXCLUDE };

static RuleKind parse_rule(const char* raw, std::string* out) {
    std::string s(raw ? raw : "");
    size_t b = s.find_first_not_of(" \t\r\n");
    if (b == std::string::npos) return RULE_SKIP;
    s = s.substr(b);
    while (!s.empty() && (s.back() == '\r' || s.back() == '\n' ||
                          s.back() == ' '  || s.back() == '\t')) {
        s.pop_back();
    }
    if (s.empty()) return RULE_SKIP;
    if (s[0] == ';' || (s.size() > 1 && s[0] == '/' && s[1] == '/')) return RULE_SKIP;
    if (s[0] == '#') {
        // `#012` 是 id；`# 说明` 是注释
        if (s.size() > 1 && s[1] >= '0' && s[1] <= '9') { *out = s; return RULE_INCLUDE; }
        return RULE_SKIP;
    }
    // 去掉行尾注释
    size_t cut = s.find_first_of(";,#");
    size_t sl = s.find("//");
    if (sl != std::string::npos && (cut == std::string::npos || sl < cut)) cut = sl;
    if (cut != std::string::npos) s = s.substr(0, cut);
    while (!s.empty() && (s.back() == ' ' || s.back() == '\t')) s.pop_back();
    if (s.empty()) return RULE_SKIP;

    bool exclude = false;
    if (s[0] == '!' || s[0] == '-') {
        exclude = true;
        s = s.substr(1);
        if (s.empty()) return RULE_SKIP;
    }
    *out = s;
    return exclude ? RULE_EXCLUDE : RULE_INCLUDE;
}

// 把一条规则作用到开关表上，返回命中条数
static int apply_rule(const std::string& r, bool enable) {
    int hits = 0;
    if (!r.empty() && r[0] == '#') {
        int id = atoi(r.c_str() + 1);
        if (id >= 0 && id < g_count) { g_enabled[id] = enable ? 1 : 0; ++hits; }
        return hits;
    }
    const bool wildcard = r.size() > 1 && r.back() == '*';
    for (int i = 0; i < g_count; ++i) {
        const char* n = g_defs[i].desc ? g_defs[i].desc->name : nullptr;
        if (!n) continue;
        const bool hit = wildcard ? (strncmp(n, r.c_str(), r.size() - 1) == 0)
                                  : (strcmp(n, r.c_str()) == 0);
        if (hit) { g_enabled[i] = enable ? 1 : 0; ++hits; }
    }
    return hits;
}

void ReloadHookFilter() {
    for (int i = 0; i < kJkMaxHooks; ++i) g_enabled[i] = 1;

    std::string p = path_join(g_dir.c_str(), "filter.txt");
    FILE* fp = nullptr;
    fopen_s(&fp, p.c_str(), "rb");
    if (!fp) {
        printf("[INFO] 没有 filter.txt，全部 %d 个钩子都打日志\n", g_count);
        return;
    }

    std::vector<std::string> includes, excludes;
    char line[512];
    while (fgets(line, sizeof line, fp)) {
        std::string rule;
        switch (parse_rule(line, &rule)) {
        case RULE_INCLUDE: includes.push_back(rule); break;
        case RULE_EXCLUDE: excludes.push_back(rule); break;
        default: break;
        }
    }
    fclose(fp);

    if (includes.empty() && excludes.empty()) {
        printf("[INFO] filter.txt 里没有有效规则，按全开处理\n");
        return;
    }

    // 有白名单：默认全关，先开白名单；否则默认全开。最后统一按黑名单关。
    if (!includes.empty()) {
        for (int i = 0; i < kJkMaxHooks; ++i) g_enabled[i] = 0;
    }
    int incHits = 0;
    for (const std::string& r : includes) incHits += apply_rule(r, true);
    int excHits = 0;
    for (const std::string& r : excludes) excHits += apply_rule(r, false);

    // 报一下最终开关数，顺便把排除掉的名字在前几条里点出来
    int enabled = 0;
    for (int i = 0; i < g_count; ++i) enabled += g_enabled[i];
    printf("[INFO] filter.txt 生效：白名单 %d 条命中 %d 个，黑名单 %d 条命中 %d 个；"
           "最终 %d/%d 个钩子打日志\n",
           (int)includes.size(), incHits, (int)excludes.size(), excHits, enabled, g_count);
    if (excHits) {
        int shown = 0;
        for (int i = 0; i < g_count && shown < 6; ++i) {
            if (g_enabled[i]) continue;
            const FnDesc* d = g_defs[i].desc;
            if (d) { printf("        已排除 #%03d %s\n", i, d->name); ++shown; }
        }
    }
}

void InitHookLog(const char* outDir) {
    g_dir = outDir ? outDir : "D:\\dump\\JKKBGKIAFCO";
    CreateDirectoryA(g_dir.c_str(), nullptr);

    g_startMs = GetTickCount64();
    g_seq.store(0);

    std::string lp = path_join(g_dir.c_str(), "hooks.log");
    fopen_s(&g_fp, lp.c_str(), "ab");
    if (g_fp) {
        SYSTEMTIME st;
        GetLocalTime(&st);
        fprintf(g_fp, "\n==== JKKBGKIAFCO hook log — %04d-%02d-%02d %02d:%02d:%02d ====\n",
                st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
        fflush(g_fp);
    }

    write_signature_table();
    ReloadHookFilter();

    g_on.store(true);
    printf("[INFO] 日志：%s\n", lp.c_str());
}

void RemoveHookLog() {
    g_on.store(false);
    std::lock_guard<std::recursive_mutex> lk(g_mu);
    if (g_fp) { fclose(g_fp); g_fp = nullptr; }
}

void ToggleHookLog() {
    bool now = !g_on.load();
    g_on.store(now);
    printf("[INFO] 日志开关 -> %s\n", now ? "ON" : "OFF");
}

bool HookLogEnabled() { return g_on.load(); }

// ---------------------------------------------------------------------------
//  每行日志
// ---------------------------------------------------------------------------
bool BeginCall(int id, LineBuf& b) {
    if (id < 0 || id >= g_count) return false;

    g_calls[id].fetch_add(1, std::memory_order_relaxed);

    if (!g_on.load(std::memory_order_relaxed)) return false;
    if (!g_enabled[id]) return false;
    if (t_depth > kJkMaxDepth) return false;
    if (!g_fp) return false;

    const FnDesc* d = g_defs[id].desc;
    if (!d) return false;

    const ULONGLONG ms  = GetTickCount64() - g_startMs;
    const uint64_t  seq = g_seq.fetch_add(1, std::memory_order_relaxed) + 1;

    char t[96];
    snprintf(t, sizeof t, "[%9llu.%03llu][T%05lu][d%02d][#%06llu] ",
             (unsigned long long)(ms / 1000), (unsigned long long)(ms % 1000),
             (unsigned long)GetCurrentThreadId(), t_depth > 0 ? t_depth - 1 : 0, (unsigned long long)seq);
    b.puts(t);
    b.puts(d->name);
    b.put('(');

    g_lines[id].fetch_add(1, std::memory_order_relaxed);
    return true;
}

void EndCallTail(LineBuf& b) {
    b.put(')');
}

void EmitLine(LineBuf& b) {
    if (!b.p || b.len == 0) return;
    if (b.len + 1 < b.cap) {
        b.p[b.len] = '\n';
        ++b.len;
    } else {
        b.len = b.cap - 2;
        b.p[b.len] = '\n';
        b.len = b.cap - 1;
    }

    // 前 5000 行逐行刷盘（崩溃时能精确到"最后一条调用"），之后每 64 行刷一次：
    // 434 个 UI 工具函数全开时每秒可能上万行，逐行 fflush 会把时间全花在磁盘 I/O 上。
    const uint64_t n = g_emitted.fetch_add(1, std::memory_order_relaxed);
    const bool flush = (n < 5000) || ((n & 63) == 0);

    std::lock_guard<std::recursive_mutex> lk(g_mu);
    if (g_fp) {
        fwrite(b.p, 1, b.len, g_fp);
        if (flush) fflush(g_fp);
    }
    if (g_echo) {
        fwrite(b.p, 1, b.len, stdout);
        fflush(stdout);
    }
}

// ---------------------------------------------------------------------------
//  统计
// ---------------------------------------------------------------------------
void DumpHookStats() {
    std::string p = path_join(g_dir.c_str(), "stats.txt");
    FILE* fp = nullptr;
    fopen_s(&fp, p.c_str(), "wb");
    if (!fp) { printf("[ERROR] 打不开 %s\n", p.c_str()); return; }

    // 按调用次数插入排序（条数少，O(n^2) 足够）
    int order[kJkMaxHooks];
    for (int i = 0; i < g_count; ++i) order[i] = i;
    for (int i = 1; i < g_count; ++i) {
        int k = order[i], j = i - 1;
        uint32_t kv = g_calls[k].load();
        while (j >= 0 && g_calls[order[j]].load() < kv) { order[j + 1] = order[j]; --j; }
        order[j + 1] = k;
    }

    fprintf(fp, "# id     calls      logged     RVA         方法\n");
    uint64_t total = 0;
    for (int i = 0; i < g_count; ++i) {
        int idx = order[i];
        const FnDesc* d = g_defs[idx].desc;
        uint32_t c = g_calls[idx].load();
        total += c;
        fprintf(fp, "#%03d  %10u %10u  0x%08x  %s\n",
                idx, c, g_lines[idx].load(), d ? d->rva : 0u, d ? d->name : "?");
    }
    fprintf(fp, "# 合计 %llu 次调用 / %d 个钩子\n", (unsigned long long)total, g_count);
    fclose(fp);
    printf("[INFO] 统计已写出：%s（合计 %llu 次调用）\n", p.c_str(), (unsigned long long)total);
}

// ---------------------------------------------------------------------------
//  安装 / 卸载
// ---------------------------------------------------------------------------
namespace {

// MinHook 会直接改写目标函数的机器码；万一那块内存不可写/被保护，异常必须在这里吃掉，
// 否则整条安装线程连同游戏一起挂。__try 里不能有需要析构的局部量 —— 所以单独拎出来，
// 只碰裸指针和 POD。
bool sehd_create_hook(void* target, void* detour, void** orig, MH_STATUS* st) {
    __try {
        *st = MH_CreateHook(target, detour, orig);
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        return false;
    }
    return true;
}

bool sehd_enable_all(MH_STATUS* st) {
    __try {
        *st = MH_EnableHook(MH_ALL_HOOKS);
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        return false;
    }
    return true;
}

}  // namespace

void RegisterHookTable(const HookDef* defs, int count) {
    g_defs  = defs;
    g_count = (count > kJkMaxHooks) ? kJkMaxHooks : count;
    for (int i = 0; i < kJkMaxHooks; ++i) {
        g_calls[i].store(0);
        g_lines[i].store(0);
        g_enabled[i] = 1;
    }
}

bool HasHookTable() { return g_defs != nullptr && g_count > 0; }

// 安装进度也写一份进日志文件：控制台输出可能被游戏自己的日志冲掉，
// 更糟的情况是进程直接挂在安装过程中 —— 那时日志里的最后一条进度就是现场。
static void install_log_line(const char* text) {
    if (!g_fp || !text) return;
    std::lock_guard<std::recursive_mutex> lk(g_mu);
    fprintf(g_fp, "%s\n", text);
    fflush(g_fp);
}

int InstallAllHooks(uint64_t base) {
    if (!g_defs || g_count <= 0) {
        printf("[ERROR] 钩子表是空的（RegisterHookTable 没调用？）\n");
        return 0;
    }

    MH_STATUS st = MH_Initialize();
    if (st != MH_OK && st != MH_ERROR_ALREADY_INITIALIZED) {
        printf("[ERROR] MH_Initialize failed: %d\n", (int)st);
        return 0;
    }

    const int kProgress = 32;
    int created = 0, ok = 0, failed = 0, notExec = 0, crashed = 0;
    int enabled = 0;

    printf("[INFO] 开始挂钩 %d 个目标（基址 0x%p）…\n", g_count, (void*)(uintptr_t)base);
    fflush(stdout);
    {
        char mark[160];
        snprintf(mark, sizeof mark, "# 开始挂钩 %d 个目标（基址 0x%p）",
                 g_count, (void*)(uintptr_t)base);
        install_log_line(mark);
    }

    // ---- 阶段 1：建钩子 ----
    // MH_CreateHook 只复制原指令、搭跳板，**不改目标代码**，所以不需要冻结线程，
    // 可以放心逐个建；建完再一次性启用（见阶段 2）。
    for (int i = 0; i < g_count; ++i) {
        const HookDef& d = g_defs[i];
        void* target = (void*)(uintptr_t)(base + d.rva);
        const char* name = d.desc ? d.desc->name : "?";

        // 先确认目标确实是可执行内存：版本对不上 / 注入到别的进程时，
        // 盲写会直接崩在 MinHook 里，这里提前拦住并给出明确提示。
        MEMORY_BASIC_INFORMATION mbi{};
        const bool exec = VirtualQuery(target, &mbi, sizeof mbi) == sizeof mbi &&
                          mbi.State == MEM_COMMIT &&
                          (mbi.Protect & (PAGE_EXECUTE | PAGE_EXECUTE_READ |
                                          PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY));
        if (!exec) {
            if (notExec < 8) {
                printf("[ERROR] #%03d %s @ 0x%p (RVA 0x%08x) 不是可执行内存 —— dump 和游戏版本对不上？\n",
                       i, name, target, d.rva);
            }
            ++failed;
            ++notExec;
            continue;
        }

        MH_STATUS cs = MH_OK;
        if (!sehd_create_hook(target, d.detour, d.orig, &cs)) {
            printf("[ERROR] #%03d MH_CreateHook(%s @ 0x%p) 抛异常，跳过\n", i, name, target);
            ++failed;
            ++crashed;
            continue;
        }
        if (cs != MH_OK) {
            printf("[ERROR] #%03d MH_CreateHook(%s @ 0x%p RVA 0x%08x) = %d\n",
                   i, name, target, d.rva, (int)cs);
            ++failed;
            continue;
        }
        ++created;

        if ((i + 1) % kProgress == 0 || i + 1 == g_count) {
            printf("[INFO] 建钩子 %d/%d（成功 %d，失败 %d）\n", i + 1, g_count, created, failed);
            fflush(stdout);
            char mark[160];
            snprintf(mark, sizeof mark, "# 建钩子 %d/%d（成功 %d，失败 %d）",
                     i + 1, g_count, created, failed);
            install_log_line(mark);
        }
    }

    // ---- 阶段 2：一次性启用 ----
    // MH_EnableHook(MH_ALL_HOOKS) 只冻结/恢复线程**一次**；逐个 Enable 会冻结 434 次
    // （每次都要 SuspendedThread 全进程线程），在跑着的游戏里又慢又容易和看门狗线程起冲突。
    if (created > 0) {
        MH_STATUS es = MH_OK;
        if (!sehd_enable_all(&es)) {
            printf("[ERROR] MH_EnableHook(MH_ALL_HOOKS) 抛异常\n");
        } else if (es != MH_OK) {
            printf("[ERROR] MH_EnableHook(MH_ALL_HOOKS) = %d\n", (int)es);
        } else {
            enabled = created;
        }
        ok = enabled;
    }

    printf("[INFO] JKKBGKIAFCO 挂钩完成：建好 %d，启用 %d，失败 %d，共 %d\n",
           created, enabled, failed, g_count);
    if (notExec == g_count) {
        printf("[ERROR] 全部目标都不是可执行内存：RVA 表对应的不是这个游戏版本，"
               "或者 dll 被注入到了错误的进程\n");
    } else if (failed) {
        printf("[WARN] 失败的多半是函数体太短（< 5 字节）或已被别的 DLL 改过\n");
    }
    if (crashed) {
        printf("[WARN] 有 %d 个目标在挂钩时抛异常（已跳过，其余钩子不受影响）\n", crashed);
    }
    fflush(stdout);

    // 结论也落到日志文件里：控制台输出有可能被游戏的日志冲掉
    {
        char mark[220];
        snprintf(mark, sizeof mark,
                 "# 挂钩结果：建好 %d / 启用 %d / 失败 %d / 共 %d（基址 0x%p）",
                 created, enabled, failed, g_count, (void*)(uintptr_t)base);
        install_log_line(mark);
    }
    return ok;
}

void RemoveAllHooks() {
    MH_DisableHook(MH_ALL_HOOKS);
    MH_Uninitialize();
}

}  // namespace jk
