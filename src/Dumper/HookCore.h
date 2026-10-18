// ============================================================================
// HookCore.h —— JKKBGKIAFCODumper 的通用挂钩 / 日志内核。
//
// 目标：把「一个 il2cpp 静态方法的每个参数」在运行期打出来。难点在 x64 MS ABI：
//   * 参数按位置进 rcx/rdx/r8/r9（整型类）或 xmm0..xmm3（浮点类），第 5 个起走栈；
//   * 大于 8 字节的**值类型**按引用传递（调用方在栈上开临时量，传它的地址）；
//   * 大于 8 字节的**返回值**走「隐藏指针」：rcx 变成本函数外挂的返回缓冲地址，
//     真正的第 1 个参数顺移到 rdx。
// 所以 detour 的签名必须和真实函数**逐位等价**，否则一旦转发就传错寄存器。
// 本文件提供模板 HookSlot<签名, Id>：签名由 tools/jkkbgkiafco_hook_gen.py 从
// full dump 里按上面三条规则翻译成 C++ 类型，编译器据此生成和原函数完全一致的
// 传参/返回序列 —— 于是转发天然正确，我们只负责在旁边把参数格式化成文本。
//
// 约定（生成代码只依赖这些）：
//   * LineBuf             —— 栈上固定缓冲，格式化不分配内存；
//   * fmt(LineBuf&, T)    —— 基础类型 / 字符串 / 结构体 / 枚举的格式化重载；
//   * OutRef<T>           —— ref/out 参数：ABI 上就是 T*（8 字节），但打印时
//                            先出地址、调用返回后再解引用打最终值；
//   * ParamDesc / FnDesc  —— 每个函数的参数名、C# 类型名、原始签名（写日志用）；
//   * HookDef             —— RVA + detour + 原始函数指针，安装表的最小单元。
// ============================================================================
#pragma once

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <tuple>
#include <type_traits>
#include <utility>
#include <atomic>

namespace jk {

// ---------------------------------------------------------------------------
//  日志行缓冲
// ---------------------------------------------------------------------------
constexpr size_t kLineCap = 8192;   // 单行上限；超出部分丢弃（不会越界）

struct LineBuf {
    char*  p;
    size_t cap;
    size_t len;

    void put(char c) {
        if (len + 1 < cap) p[len++] = c;
    }
    void write(const char* s, size_t n) {
        size_t room = (cap > 0 && len + 1 < cap) ? (cap - 1 - len) : 0;
        if (n > room) n = room;
        if (n) { memcpy(p + len, s, n); len += n; }
    }
    void puts(const char* s) {
        if (s) write(s, strlen(s));
    }
    // 十进制有符号
    void dec(long long v) {
        char t[24];
        int i = 0;
        unsigned long long u = (v < 0) ? (0ULL - (unsigned long long)v) : (unsigned long long)v;
        if (v < 0) put('-');
        do { t[i++] = (char)('0' + (u % 10)); u /= 10; } while (u);
        while (i) put(t[--i]);
    }
    // 十进制无符号
    void udec(unsigned long long v) {
        char t[24];
        int i = 0;
        do { t[i++] = (char)('0' + (v % 10)); v /= 10; } while (v);
        while (i) put(t[--i]);
    }
    // 小写十六进制
    void hex(uint64_t v) {
        static const char kDig[] = "0123456789abcdef";
        char t[16];
        int i = 0;
        do { t[i++] = kDig[v & 0xF]; v >>= 4; } while (v);
        while (i) put(t[--i]);
    }
    // 浮点：用 CRT 的 %.Ng（和游戏自己打的字符串风格一致）
    void flt(double v, int prec);
};

// ---------------------------------------------------------------------------
//  Il2CppString（托管字符串）
//    +0x00 klass  +0x08 monitor  +0x10 length(int32)  +0x14 chars(UTF-16)
//  本布局与 TextMapDump.cpp / DataHook.cpp 实测一致。
// ---------------------------------------------------------------------------
struct Il2CppString {
    void*    klass;
    void*    monitor;
    int32_t  length;
    uint16_t chars[1];
};

// 把托管字符串按 UTF-8 追加进缓冲（含转义与截断）；s 为 null 时打 null。
// 内部用 __try 保护：热路径上故意传进来的指针可能已经失效。
void fmt_string(LineBuf& b, const Il2CppString* s);

// ---------------------------------------------------------------------------
//  ref / out 参数包装
//  ABI：T* —— 8 字节，走整型寄存器，和真实函数要求的「引用」完全一致。
// ---------------------------------------------------------------------------
template <typename T>
struct OutRef {
    T* p;
};

template <typename T>
inline void fmt(LineBuf& b, const OutRef<T>& v) {
    b.puts("&0x");
    b.hex((uint64_t)(uintptr_t)v.p);
}

// ---------------------------------------------------------------------------
//  基础类型格式化
// ---------------------------------------------------------------------------
inline void fmt(LineBuf& b, bool v)              { b.puts(v ? "true" : "false"); }
inline void fmt(LineBuf& b, char v)              { b.puts("'"); b.put((char)((v >= 32 && v < 127) ? v : '?')); b.puts("'"); }
inline void fmt(LineBuf& b, int8_t v)            { b.dec(v); }
inline void fmt(LineBuf& b, uint8_t v)           { b.udec(v); }
inline void fmt(LineBuf& b, int16_t v)           { b.dec(v); }
inline void fmt(LineBuf& b, uint16_t v)          { b.udec(v); }
inline void fmt(LineBuf& b, int32_t v)           { b.dec(v); }
inline void fmt(LineBuf& b, uint32_t v)          { b.udec(v); }
inline void fmt(LineBuf& b, int64_t v)           { b.dec(v); }
inline void fmt(LineBuf& b, uint64_t v)          { b.udec(v); }
inline void fmt(LineBuf& b, float v)             { b.flt((double)v, 9); }
inline void fmt(LineBuf& b, double v)            { b.flt(v, 17); }

// 托管对象 / 数组 / 类实例：只知道地址，打指针。
inline void fmt(LineBuf& b, void* v) {
    if (!v) { b.puts("null"); return; }
    b.puts("0x"); b.hex((uint64_t)(uintptr_t)v);
}
inline void fmt(LineBuf& b, const void* v) {
    fmt(b, const_cast<void*>(v));
}
inline void fmt(LineBuf& b, const Il2CppString* s) { fmt_string(b, s); }

// 按偏移取字段（生成代码用）：结构体一律用原始字节表达布局，字段靠偏移读，
// 这样既不用还原 C# 的字段排布，也不会因为对齐规则不同而改变 sizeof。
template <typename T>
inline T rd(const void* base, size_t off) {
    T t{};
    memcpy(&t, (const uint8_t*)base + off, sizeof(T));
    return t;
}

// 枚举：交给生成代码里的 enum_name()（同 namespace，ADL 找得到）。
template <typename E, std::enable_if_t<std::is_enum_v<E>, int> = 0>
inline void fmt(LineBuf& b, E v) {
    using U = std::underlying_type_t<E>;
    const char* n = enum_name(v);
    if (n) {
        b.puts(n);
        b.put('(');
        fmt(b, (U)v);
        b.put(')');
    } else {
        fmt(b, (U)v);
    }
}

// ---------------------------------------------------------------------------
//  描述表（由生成代码填，运行期只读）
// ---------------------------------------------------------------------------
enum : uint8_t {
    PD_PTR = 1,   // ref / out：结尾要解引用补打一次最终值
};

struct ParamDesc {
    const char* name;    // C# 参数名（混淆名）
    const char* type;    // C# 类型名
    uint8_t     flags;   // PD_*
};

struct FnDesc {
    const char*      name;      // 方法名（不含类名）
    const char*      sig;       // 原始 C# 声明，整行照抄，便于对照 dump
    const char*      retType;   // C# 返回类型名
    uint32_t         rva;       // imagebase=0 时的 RVA（== IDA 地址）
    uint16_t         nParams;
    uint16_t         flags;     // bit0 有返回值；bit1 返回值走隐藏指针
    const ParamDesc* params;
};

enum : uint16_t {
    FN_HAS_RET   = 1,
    FN_RET_MEM   = 2,
};

struct HookDef {
    uint32_t       rva;
    void*          detour;
    void**         orig;
    const FnDesc*  desc;
};

// ---------------------------------------------------------------------------
//  日志 API（HookCore.cpp）
// ---------------------------------------------------------------------------
void InitHookLog(const char* outDir);     // 建目录/开日志/写函数表/读过滤表
void RemoveHookLog();
void ToggleHookLog();                     // F9
void DumpHookStats();                     // F10
void ReloadHookFilter();                  // F11
bool HookLogEnabled();

// 每次调用：先 ++ 计数、判开关/过滤/深度，需要输出时写好行首，返回 true。
bool BeginCall(int id, LineBuf& b);
// 收尾：补 ")"、返回值、ref/out 最终值，然后整行落盘。
void EndCallTail(LineBuf& b);             // 只写 ")"
void EmitLine(LineBuf& b);

// 调用深度（thread_local）：BeginCall 前 ++，detour 退出时 --。
struct DepthGuard {
    DepthGuard();
    ~DepthGuard();
};

// ---------------------------------------------------------------------------
//  参数打印
// ---------------------------------------------------------------------------
template <size_t I, typename T>
inline void fmt_arg(LineBuf& b, const ParamDesc* pd, const T& v) {
    if (I) b.puts(", ");
    if (pd) {
        b.puts(pd[I].name);
        // 结构体参数的格式化器自己会打类型名（Vector3{...}），这里就不重复了
        if (pd[I].type && pd[I].type[0]) { b.put(':'); b.puts(pd[I].type); }
        b.put('=');
    }
    fmt(b, v);
}

template <typename... A, size_t... Is>
inline void fmt_args_impl(LineBuf& b, const ParamDesc* pd, const std::tuple<A...>& t,
                          std::index_sequence<Is...>) {
    (fmt_arg<Is>(b, pd, std::get<Is>(t)), ...);
}

template <typename... A>
inline void fmt_args(LineBuf& b, const ParamDesc* pd, const A&... a) {
    if (sizeof...(A) == 0) return;
    fmt_args_impl(b, pd, std::tuple<A...>(a...), std::index_sequence_for<A...>{});
}

// 实例方法：第 0 个实参是 this，不参与打印，所以描述表索引整体后移一位。
template <typename... A, size_t... Is>
inline void fmt_args_skip1_impl(LineBuf& b, const ParamDesc* pd, const std::tuple<A...>& t,
                                std::index_sequence<Is...>) {
    (fmt_arg<Is>(b, pd, std::get<Is + 1>(t)), ...);
}

template <typename... A>
inline void fmt_args_skip1(LineBuf& b, const ParamDesc* pd, const A&... a) {
    static_assert(sizeof...(A) > 0, "fmt_args_skip1 需要至少一个实参");
    fmt_args_skip1_impl(b, pd, std::tuple<A...>(a...),
                        std::make_index_sequence<sizeof...(A) - 1>{});
}

// ---------------------------------------------------------------------------
//  ref/out 参数的最终值
//  行内格式：NAME(a=1) [out: b->2, c->3] -> ret
// ---------------------------------------------------------------------------
template <typename T>
struct is_outref : std::false_type {};
template <typename T>
struct is_outref<OutRef<T>> : std::true_type {};

template <size_t I, typename T>
inline void fmt_out_one(LineBuf& b, const ParamDesc* pd, const T& v, int& n) {
    if constexpr (is_outref<T>::value) {
        if (pd && (pd[I].flags & PD_PTR)) {
            b.puts(n ? ", " : " [out: ");
            ++n;
            b.puts(pd[I].name);
            b.puts("->");
            if (!v.p) b.puts("null");
            else fmt(b, *v.p);
        }
    }
}

template <typename... A, size_t... Is>
inline void fmt_outs_impl(LineBuf& b, const ParamDesc* pd, const std::tuple<A...>& t,
                          std::index_sequence<Is...>, int& n) {
    (fmt_out_one<Is>(b, pd, std::get<Is>(t), n), ...);
}

template <typename... A>
inline void fmt_outs(LineBuf& b, const ParamDesc* pd, const A&... a) {
    if (sizeof...(A) == 0) return;
    int n = 0;
    fmt_outs_impl(b, pd, std::tuple<A...>(a...), std::index_sequence_for<A...>{}, n);
    if (n) b.put(']');
}

// 实例方法版：跳过第 0 个实参（this）
template <typename... A, size_t... Is>
inline void fmt_outs_skip1_impl(LineBuf& b, const ParamDesc* pd, const std::tuple<A...>& t,
                                std::index_sequence<Is...>, int& n) {
    (fmt_out_one<Is>(b, pd, std::get<Is + 1>(t), n), ...);
}

template <typename... A>
inline void fmt_outs_skip1(LineBuf& b, const ParamDesc* pd, const A&... a) {
    if (sizeof...(A) <= 1) return;
    int n = 0;
    fmt_outs_skip1_impl(b, pd, std::tuple<A...>(a...),
                        std::make_index_sequence<sizeof...(A) - 1>{}, n);
    if (n) b.put(']');
}

// ---------------------------------------------------------------------------
//  返回值
// ---------------------------------------------------------------------------
// 注意：这里**不能**再放一个 `fmt_ret(LineBuf&, const void*)` 的重载 ——
// 它对 `void*` 返回值是「非模板优于模板」的更好匹配，会把指针打成 "void"。
// void 返回值由 detour 里的 `if constexpr` 分支直接写 "void"。
template <typename R>
inline void fmt_ret(LineBuf& b, const R& v) { fmt(b, v); }

// ---------------------------------------------------------------------------
//  HookSlot：一个函数一份（Id 决定用哪条描述）
// ---------------------------------------------------------------------------
// 取 Id 对应的描述（实现见 HookCore.cpp）—— 必须在 HookSlot 之前声明：
// 两阶段查找里 DescOf(Id) 走普通查找，定义点看不到后面的声明会报 C3861。
const FnDesc* DescOf(int id);

template <typename Sig, int Id, bool SkipSelf = false>
struct HookSlot;

template <typename R, typename... A, int Id, bool SkipSelf>
struct HookSlot<R(__fastcall*)(A...), Id, SkipSelf> {
    using fn_t = R(__fastcall*)(A...);

    static inline fn_t orig = nullptr;   // MinHook 交回的原始函数（跳板）

    static R __fastcall detour(A... a) {
        DepthGuard depth;
        char      raw[kLineCap];
        LineBuf   b{raw, kLineCap, 0};
        const bool on = BeginCall(Id, b);

        if constexpr (std::is_void_v<R>) {
            // 先放行原函数，再补尾巴：ref/out 的最终值要等它写完。
            if (on) {
                if constexpr (SkipSelf) fmt_args_skip1(b, TheParams(), a...);
                else                    fmt_args(b, TheParams(), a...);
                EndCallTail(b);
            }
            orig(a...);
            if (on) {
                if constexpr (SkipSelf) fmt_outs_skip1(b, TheParams(), a...);
                else                    fmt_outs(b, TheParams(), a...);
                b.puts(" -> void");
                EmitLine(b);
            }
            return;
        } else {
            if (on) {
                if constexpr (SkipSelf) fmt_args_skip1(b, TheParams(), a...);
                else                    fmt_args(b, TheParams(), a...);
                EndCallTail(b);
            }
            R r = orig(a...);
            if (on) {
                if constexpr (SkipSelf) fmt_outs_skip1(b, TheParams(), a...);
                else                    fmt_outs(b, TheParams(), a...);
                b.puts(" -> ");
                fmt_ret(b, r);
                EmitLine(b);
            }
            return r;
        }
    }

private:
    static const ParamDesc* TheParams() {
        const FnDesc* d = DescOf(Id);
        return d ? d->params : nullptr;
    }
};

// ---------------------------------------------------------------------------
//  安装
//  顺序：RegisterHookTable（登记描述表）→ InitHookLog（写签名表/读过滤表）→ InstallAllHooks
//  反过来就会写出空签名表、filter 规则全落空。
// ---------------------------------------------------------------------------
void RegisterHookTable(const HookDef* defs, int count);
bool HasHookTable();

// 按登记表逐个 MH_CreateHook + MH_EnableHook，返回成功条数。
int  InstallAllHooks(uint64_t base);
void RemoveAllHooks();

}  // namespace jk
