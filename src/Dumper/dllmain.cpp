#include "framework.h"
#include "HookCore.h"
#include "EKHBADNLJKF.hooks.generated.h"   // UI context 基类的 517 个实例方法全量钩子
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <mutex>
#include <atomic>
#include <chrono>
#include "MinHook.h"
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <cstring>


// 7.1 国服 (YuanShen.exe) 偏移, 统一相对于模块基址。
// 注意: full dump 7.1.cs 里 UnityEngine 引擎内部方法 (Object / GameObject / Transform /
// Component) 的 RVA 大多只是 il2cpp 代码段里的跳板 (`jmp xxx` 桩), 直接 hook 跳板会漏钩
// 直接调用真实实现的路径。下面填的是经 IDA (localhost:13337, YuanShen.exe.i64) 顺着
// 跳板解引用后得到的**真实内部函数** RVA; 注释中的 "dump:" 是 dump.cs 里的跳板 RVA,
// 方便下次游戏更新时核对。
namespace GameOffsets {
    // UnityEngine.Object::get_name           dump: 0x19cb2e60 -> jmp 0x14389f0
    const uint64_t GetName = 0x14389f0;

    // UnityEngine.GameObject::get_transform  dump: 0x19c9b7b0 -> jmp 0x1452da0
    const uint64_t GetTransform = 0x1452da0;

    // UnityEngine.GameObject::.ctor(System.String)  dump: 0x19c9ba10 -> jmp 0x1453690
    // (无参 .ctor() 的跳板 0x19c9ba30 是 `xor edx,edx; jmp 0x1453690`, 一并被覆盖)
    const uint64_t GameObject_Constructor = 0x1453690;
    // UnityEngine.GameObject::SetActive(System.Boolean)  dump: 0x19c9b800 -> jmp 0x1452ee0
    const uint64_t GameObject_SetActive = 0x1452ee0;

    // UnityEngine.Transform::get_parent      dump: 0x19cb4a40 -> jmp 0x14374b0
    const uint64_t Transform_GetParent = 0x14374b0;

    // UnityEngine.Component::get_gameObject  dump: 0x19cbc880 -> jmp 0x1453c60
    const uint64_t Component_GetGameObject = 0x1453c60;

    // UnityEngine.UI.Text::set_text (Slot 81)  dump: 0x19d9abd0
    // 该 RVA 本身就是真实实现 (不是跳板), 无需再解引用。
    const uint64_t Text_SetText = 0x19d9abd0;

    // ------------------------------------------------------------------
    // 地图链路（追查“冒险之证 -> 开地图 -> 导航到某点”时加的）
    //
    // 更正：这里曾经把 0x134C0180 误标成 JKKBGKIAFCO::DLHBBAFDBGN。
    //   DLHBBAFDBGN 的真实 RVA 是 0x8f15600（il2cpp 代码段里的正则替换工具）。
    //   0x134C0180 实际是 AKBPMKJEIDJ::PLCPFNFNJML，地图加载/激活核心。
    // ------------------------------------------------------------------

    // AKBPMKJEIDJ::PLCPFNFNJML(UnityAction onReady) -> void   dump: 0x134c0180
    // 地图管理器（AKBPMKJEIDJ : InLevelManager）的“打开/激活地图”核心：
    //   取 MapScriptData.MapContainerPath -> 按 SceneScriptData.stageType(3/4) 换图
    //   -> 已加载就直接 MIKECAENIJL 激活，否则异步加载后回调 KKHMELBKHDL。
    const uint64_t AKBPMKJEIDJ_PLCPFNFNJML = 0x134C0180;

    // HHDNOGHMIOC::IOGOAAMKENJ(uint32 markId, Vector3 worldPos) -> void   dump: 0x11cd0040
    // 地图 context 的“定位到指定点并打开地图”：
    //   EECAIPKCMIP(this, markId) 校验 -> 存坐标到 FALLECEHCIJ / JNENNLKDODO
    //   -> PDDAINOAFMB() 打开地图。
    // markId 校验不过会直接 return（等于什么都不发生）；r8 指向 Vector3 世界坐标。
    // hook 它就能拿到“前往/导航”时的真实目标参数。
    const uint64_t HHDNOGHMIOC_IOGOAAMKENJ = 0x11CD0040;

    // DAEMCCNOCPF::OLNKJJKDBDM(OINFPJNKEPE* ctx, MIEKEGOGCPP layer) -> bool   dump: 0xba5ed20
    // UI 总管“打开任意 UI context”的同步入口（所有界面都走它）。
    // 抓“谁在什么时候打开某个界面”要 hook 这里 —— 这一刻还在点击的同步栈上，比 hook
    // 界面内部（SetupView / 开地图）早好几帧，不会被异步加载或事件派发断链。
    const uint64_t DAEMCCNOCPF_OLNKJJKDBDM = 0xBA5ED20;

    // HHDNOGHMIOC::SetupView()   dump: 0x11d69500
    // 只当“地图 context”的指纹用：在 klass 的 vtable(+0x138, 每项 16 字节) 里找它。
    const uint64_t HHDNOGHMIOC_SetupView = 0x11D69500;

    // HHDNOGHMIOC::GMCFODMKJBC() -> void   dump: 0x11d3d960
    // 另一条“定位”路径：用 context 当前绑定的 mark（this+0x4b8）算坐标并开图。
    // 如果“前往/追踪”走的不是 IOGOAAMKENJ，就会走这里，所以两个都 hook。
    const uint64_t HHDNOGHMIOC_GMCFODMKJBC = 0x11D3D960;

    // HHDNOGHMIOC 当前绑定 mark 的字段偏移（MonoMapMark*）
    const uint32_t OFF_HHDNO_CURRENT_MARK = 0x4b8;

    // MonoMapMark 上几个疑似 id 的 uint32 字段，先原样打出来靠对比认
    const uint32_t OFF_MARK_U32_A = 0xb4;
    const uint32_t OFF_MARK_U32_B = 0xb8;
    const uint32_t OFF_MARK_U32_C = 0xd8;
    const uint32_t OFF_MARK_U32_D = 0xe8;
}

// UI context / 方法表 dump 用的地址（不属于“函数偏移”，单独放）
namespace ContextDump {
    constexpr uint64_t RVA_META_BASE = 0x5783DE8;   // IL2CPP metadata 基指针
    constexpr uint64_t OFF_UI_OPEN_LIST = 0xE8;     // DAEMCCNOCPF::PHKGOOIHAMN (List<OINFPJNKEPE>)
    constexpr uint64_t OFF_LIST_ITEMS = 0x10;       // List<T>._items
    constexpr uint64_t OFF_LIST_SIZE = 0x18;        // List<T>._size
    constexpr uint64_t OFF_ARRAY_DATA = 0x20;       // Il2CppArray 元素起始
    constexpr uint64_t OFF_KLASS_METHODS = 0x98;    // Il2CppClass::methods (MethodInfo**)
    constexpr uint64_t OFF_KLASS_METHOD_COUNT = 0x11C; // Il2CppClass_2::method_count
    constexpr uint64_t OFF_METHOD_POINTER = 0x00;   // MethodInfo::methodPointer

    // 两个“按钮点击跳板闭包”（它们只是把捕获到的 UnityAction 转调）
    //   EKHBADNLJKF.HMODIOPKHLJ::CHLPPNHBDJN   0x14058e10
    //   EKHBADNLJKF.JBEINFOMBIC::CHLPPNHBDJN   0x14058e50
    // 闭包对象布局: +0x10 = 捕获的 UnityAction*
    constexpr uint64_t RVA_CLOSURE_HMODIOPKHLJ = 0x14058E10;
    constexpr uint64_t RVA_CLOSURE_JBEINFOMBIC = 0x14058E50;
    constexpr uint64_t OFF_CLOSURE_ACTION = 0x10;

    // UnityEngine.Events.UnityAction::Invoke (Slot 10)
    constexpr uint64_t RVA_UNITY_ACTION_INVOKE = 0x19C99830;

    // UnityEngine.Events.UnityEvent::Invoke   0x19c99a40
    // ★ 按钮点击的真正必经之路：Button.Press() -> m_OnClick.Invoke()
    constexpr uint64_t RVA_UNITY_EVENT_INVOKE = 0x19C99A40;

    // MoleMole.MonoUIContainer::OnClick()   0xd737b70
    // ★ 游戏自己封装的按钮点击入口。冒证的“前往”不走 UnityEvent，走的是这里。
    constexpr uint64_t RVA_MONO_UI_CONTAINER_ONCLICK = 0xD737B70;
}
// =============================================================

// 全局变量
HMODULE hUnityModule = nullptr;
HANDLE hLogThread = nullptr;
HANDLE hHotkeyThread = nullptr;
std::atomic<bool> bRunning = true;
std::atomic<bool> bInitialized = false;
std::mutex logMutex;
std::vector<std::wstring> logBuffer;
std::wofstream logFile;
std::wstring currentLogFile;

// 缓存已经记录的GameObject，避免重复记录
std::unordered_set<uintptr_t> recordedGameObjects;
std::mutex cacheMutex;

// Unity函数指针类型定义
using Fn_GetName = void* (__fastcall*)(void*);
using Fn_GetParent = void* (__fastcall*)(void*);
using Fn_GetTransform = void* (__fastcall*)(void*);
using Fn_GetGameObject = void* (__fastcall*)(void*);
using Fn_GameObject_ctor = void* (__fastcall*)(void*, void*);
using Fn_GameObject_SetActive = void(__fastcall*)(void*, bool);
using Fn_Text_set_Text = void(__fastcall*)(void*, void*);
// AKBPMKJEIDJ::PLCPFNFNJML(UnityAction) —— rcx=this, rdx=UnityAction, r8=MethodInfo*
using Fn_MapOpen = void(__fastcall*)(void*, void*, void*);
// HHDNOGHMIOC::IOGOAAMKENJ(uint32, Vector3) —— rcx=this, edx=markId, r8=Vector3*, r9=MethodInfo*
using Fn_MapNavigate = void(__fastcall*)(void*, unsigned int, float*, void*);
// DAEMCCNOCPF::OLNKJJKDBDM(ctx, layer) -> bool —— rcx=uiMgr, rdx=ctx, r8d=layer, r9=MethodInfo*
using Fn_UIOpen = bool(__fastcall*)(void*, void*, int, void*);
// HHDNOGHMIOC::GMCFODMKJBC() —— rcx=this, rdx=MethodInfo*
using Fn_MapFocus = void(__fastcall*)(void*, void*);
// UnityEngine.Events.UnityAction::Invoke —— rcx = 委托对象
using Fn_UnityActionInvoke = void(__fastcall*)(void* action);
// UnityEngine.Events.UnityEvent::Invoke —— rcx = UnityEvent 实例
using Fn_UnityEventInvoke = void(__fastcall*)(void* evt);
// MoleMole.MonoUIContainer::OnClick —— rcx = MonoUIContainer 实例
using Fn_MonoUIContainerOnClick = void(__fastcall*)(void* self);
// 点击跳板闭包 —— rcx = 闭包对象
using Fn_ClickClosure = void(__fastcall*)(void* self);

// 原始函数指针
Fn_GetName Original_GetName = nullptr;
Fn_GetParent Original_Transform_GetParent = nullptr;
Fn_GetTransform Original_GetTransform = nullptr;
Fn_GetGameObject Original_Component_GetGameObject = nullptr;
Fn_GameObject_ctor Original_GameObject_ctor = nullptr;
Fn_GameObject_SetActive Original_GameObject_SetActive = nullptr;
Fn_Text_set_Text Original_Text_set_Text = nullptr;
Fn_MapOpen Original_PLCPFNFNJML = nullptr;
Fn_MapNavigate Original_IOGOAAMKENJ = nullptr;
Fn_UIOpen Original_UIOpen = nullptr;
Fn_MapFocus Original_GMCFODMKJBC = nullptr;
Fn_UnityActionInvoke Original_UnityActionInvoke = nullptr;
Fn_UnityEventInvoke Original_UnityEventInvoke = nullptr;
Fn_MonoUIContainerOnClick Original_MonoUIContainerOnClick = nullptr;
Fn_ClickClosure Original_Closure0 = nullptr;
Fn_ClickClosure Original_Closure1 = nullptr;

// Hook函数声明
void* __fastcall Hooked_GameObject_ctor(void* thisptr, void* name);
void __fastcall Hooked_GameObject_SetActive(void* thisptr, bool active);
void __fastcall Hooked_Text_set_Text(void* thisptr, void* value);
void __fastcall Hooked_PLCPFNFNJML(void* self, void* callback, void* method);
void __fastcall Hooked_IOGOAAMKENJ(void* self, unsigned int markId, float* pos, void* method);
bool __fastcall Hooked_UIOpen(void* uiMgr, void* ctx, int layer, void* method);
void __fastcall Hooked_GMCFODMKJBC(void* self, void* method);

// ==================== 工具函数 ====================

std::wstring ReadUnityString(void* str) {
    if (!str) {
        return L"";
    }

    try {
        uintptr_t ptr = reinterpret_cast<uintptr_t>(str);
        wchar_t* stringPtr = reinterpret_cast<wchar_t*>(ptr + 0x14);

        std::wstring result = stringPtr;

        if (result.empty()) {
            return L"";
        }

        std::wstring lowerResult = result;
        std::transform(lowerResult.begin(), lowerResult.end(), lowerResult.begin(), ::towlower);

        if (lowerResult == L"none") {
            return L"";
        }

        return result;
    }
    catch (...) {

    }

    return L"";
}

std::wstring GetCurrentTimeString() {
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm;
    localtime_s(&now_tm, &now_c);

    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
        now.time_since_epoch()) % 1000;

    std::wostringstream oss;
    oss << std::put_time(&now_tm, L"%Y-%m-%d %H:%M:%S");
    oss << L'.' << std::setfill(L'0') << std::setw(3) << ms.count();
    return oss.str();
}

std::string WStringToUtf8(const std::wstring& wstr) {
    if (wstr.empty()) {
        return "";
    }

    int size = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);
    if (size <= 0) {
        return "";
    }

    std::string result(size, '\0');
    WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, &result[0], size, nullptr, nullptr);
    result.pop_back(); // 去掉结尾的 '\0'
    return result;
}

void AddLog(const std::wstring& message, bool toConsole = true) {
    std::lock_guard<std::mutex> lock(logMutex);

    std::wstring formatted = L"[" + GetCurrentTimeString() + L"] " + message;
    logBuffer.push_back(formatted);

    if (toConsole) {
        std::cout << WStringToUtf8(formatted + L"\n");
    }
}

void DumpStack()
{
    const int maxFrames = 32;
    void* stack[maxFrames];
    WORD frames = RtlCaptureStackBackTrace(0, maxFrames, stack, NULL);

    HMODULE hModule = GetModuleHandleA("YuanShen.exe");

    AddLog(L"stack: " + std::to_wstring(frames) + L"");
    for (int i = 0; i < frames; i++)
    {
        uintptr_t addr = (uintptr_t)stack[i];
        std::wstringstream ss;
        if (hModule)
        {
            uintptr_t base = (uintptr_t)hModule;
            uintptr_t rva = addr - base;
            ss << L"stack " << i << L": 0x" << std::hex << addr << L" (RVA: 0x" << std::hex << rva << L")";
        }
        else
        {
            ss << L"stack " << i << L": 0x" << std::hex << addr;
        }
        AddLog(ss.str());
    }
    AddLog(L"============");
}

std::wstring GetGameObjectPath(void* gameObject) {
    if (!gameObject || !Original_GetTransform || !Original_GetName) {
        return L"";
    }

    try {
        void* transform = Original_GetTransform(gameObject);
        if (!transform) return L"NoTransform";

        std::vector<std::wstring> pathParts;
        std::unordered_set<void*> visited;
        void* current = transform;
        int depth = 0;

        while (current && depth < 30) {
            if (visited.find(current) != visited.end()) {
                pathParts.insert(pathParts.begin(), L"[CIRCULAR]");
                break;
            }
            visited.insert(current);

            void* nameStr = Original_GetName(current);
            std::wstring name = ReadUnityString(nameStr);

            if (name.empty()) {
                pathParts.insert(pathParts.begin(), L"Unnamed");
                break;
            }

            pathParts.insert(pathParts.begin(), name);

            void* parent = Original_Transform_GetParent(current);
            if (!parent || parent == current) {
                break;
            }

            current = parent;
            depth++;
        }

        std::wstring fullPath;
        for (size_t i = 0; i < pathParts.size(); i++) {
            fullPath += pathParts[i];
            if (i < pathParts.size() - 1) {
                fullPath += L"/";
            }
        }

        return fullPath;
    }
    catch (...) {
        return L"Error";
    }
}

bool IsImportantGameObject(const std::wstring& path) {
    static const std::vector<std::wstring> importantKeywords = {
        L"LevelMapUIManager(Clone1)"
    };

    for (const auto& keyword : importantKeywords) {
        if (path.find(keyword) != std::wstring::npos) {
            return true;
        }
    }

    return false;
}

// ==================== Hook回调函数 ====================

void* __fastcall Hooked_GameObject_ctor(void* thisptr, void* name) {
    void* result = nullptr;

    if (Original_GameObject_ctor) {
        result = Original_GameObject_ctor(thisptr, name);
    }

    if (bRunning && thisptr) {
        uintptr_t objPtr = reinterpret_cast<uintptr_t>(thisptr);
        {
            std::lock_guard<std::mutex> lock(cacheMutex);
            if (recordedGameObjects.find(objPtr) == recordedGameObjects.end()) {
                recordedGameObjects.insert(objPtr);

                std::wstring nameStr = ReadUnityString(name);
                // AddLog(L"[Constructor] GameObject: " + (nameStr.empty() ? L"Unnamed" : nameStr));
            }
        }
    }
    return result;
}

void __fastcall Hooked_GameObject_SetActive(void* thisptr, bool active) {
    if (bRunning && thisptr) {
        std::wstring path = GetGameObjectPath(thisptr);
        if (!path.empty() && IsImportantGameObject(path)) {
            AddLog(L"[SetActive] " + std::wstring(active ? L"True" : L"False") +
                L" | Path: " + path);
            DumpStack();
        }
    }

    if (Original_GameObject_SetActive) {
        Original_GameObject_SetActive(thisptr, active);
    }
}

void __fastcall Hooked_Text_set_Text(void* thisptr, void* value) {
    if (bRunning && value) {
        std::wstring text = ReadUnityString(value);
        if (text.find(L"1月10日") != std::wstring::npos) {
            std::wstring path;
            if (thisptr && Original_Component_GetGameObject) {
                void* gameObject = Original_Component_GetGameObject(thisptr);
                path = GetGameObjectPath(gameObject);
            }
            AddLog(L"[Text set_Text] Contains 1月10日: " + text +
                (path.empty() ? L"" : L" | Path: " + path));
            DumpStack();
        }
    }

    if (Original_Text_set_Text) {
        Original_Text_set_Text(thisptr, value);
    }
}

// AKBPMKJEIDJ::PLCPFNFNJML(UnityAction) —— 地图打开时机 + 调用栈（低频：只在开/切图时命中）
void __fastcall Hooked_PLCPFNFNJML(void* self, void* callback, void* method) {
    if (bRunning) {
        std::wstringstream ss;
        ss << L"[MapOpen] PLCPFNFNJML self=0x" << std::hex << (uintptr_t)self
           << L" callback=0x" << std::hex << (uintptr_t)callback;
        AddLog(ss.str());
        DumpStack();
    }

    if (Original_PLCPFNFNJML) {
        Original_PLCPFNFNJML(self, callback, method);
    }
}

// HHDNOGHMIOC::IOGOAAMKENJ(uint32 markId, Vector3 worldPos) —— “前往/导航”的目标参数
// 同一个点会被反复刷新，所以按 (markId, pos) 去重，并限制总条数，避免刷屏。
void __fastcall Hooked_IOGOAAMKENJ(void* self, unsigned int markId, float* pos, void* method) {
    if (bRunning) {
        static unsigned int lastMarkId = 0xFFFFFFFFu;
        static float lastX = 0.f, lastY = 0.f, lastZ = 0.f;
        static int loggedCount = 0;

        const float x = pos ? pos[0] : 0.f;
        const float y = pos ? pos[1] : 0.f;
        const float z = pos ? pos[2] : 0.f;

        const bool same = (markId == lastMarkId) && (x == lastX) && (y == lastY) && (z == lastZ);

        if (!same && loggedCount < 200) {
            lastMarkId = markId;
            lastX = x; lastY = y; lastZ = z;
            ++loggedCount;

            wchar_t buffer[256];
            swprintf(buffer, 256, L"[MapNav] markId=%u pos=(%.2f, %.2f, %.2f) self=0x%llX",
                markId, x, y, z, (unsigned long long)(uintptr_t)self);
            AddLog(buffer);
            DumpStack();
        }
    }

    if (Original_IOGOAAMKENJ) {
        Original_IOGOAAMKENJ(self, markId, pos, method);
    }
}

// 安全读指针（独立函数：__try 里不能有 C++ 对象，否则 C2712）
void* SafeReadPtr(void* address) {
    __try {
        return *(void**)address;
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        return nullptr;
    }
}

// 判断某个 Il2CppClass 的 vtable 里是否含指定方法指针
// Il2CppClass::vtable 在 +0x138，每项 VirtualInvokeData = { methodPtr, method }（16 字节）
bool KlassHasMethod(void* klass, uintptr_t methodPtr) {
    if (!klass || !methodPtr) {
        return false;
    }

    bool found = false;
    __try {
        uintptr_t* vtable = (uintptr_t*)((char*)klass + 0x138);
        for (int i = 0; i < 255; ++i) {
            if (vtable[i * 2] == methodPtr) {
                found = true;
                break;
            }
        }
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        found = false;
    }
    return found;
}

// DAEMCCNOCPF::OLNKJJKDBDM —— UI 总管打开 context 的同步入口
// 只在“打开的是地图 context”时打日志 + 栈，避免被其它界面刷屏。
bool __fastcall Hooked_UIOpen(void* uiMgr, void* ctx, int layer, void* method) {
    if (bRunning && ctx) {
        void* klass = SafeReadPtr(ctx);

        static HMODULE s_mod = GetModuleHandleW(L"YuanShen.exe");
        const uintptr_t mapSetupView =
            (uintptr_t)s_mod + (uintptr_t)GameOffsets::HHDNOGHMIOC_SetupView;

        if (KlassHasMethod(klass, mapSetupView)) {
            std::wstringstream ss;
            ss << L"[MapCtx] UIOpen ctx=0x" << std::hex << (uintptr_t)ctx
               << L" klass=0x" << std::hex << (uintptr_t)klass
               << L" layer=" << std::dec << layer;
            AddLog(ss.str());
            DumpStack();
        }
    }

    if (Original_UIOpen) {
        return Original_UIOpen(uiMgr, ctx, layer, method);
    }
    return false;
}

// 安全读 uint32（同样要独立函数，避免 C2712）
unsigned int SafeReadU32(void* address, unsigned int fallback) {
    __try {
        return *(unsigned int*)address;
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        return fallback;
    }
}

// HHDNOGHMIOC::GMCFODMKJBC —— 用“当前绑定的 mark”定位并开图
// 打印 context 绑定的是哪个 mark，以及 mark 上几个 uint32 字段（靠对比认出真正的 markId）。
void __fastcall Hooked_GMCFODMKJBC(void* self, void* method) {
    if (bRunning && self) {
        void* mark = SafeReadPtr((char*)self + GameOffsets::OFF_HHDNO_CURRENT_MARK);

        static void* s_lastMark = nullptr;
        static int s_count = 0;

        if (mark != s_lastMark && s_count < 100) {
            s_lastMark = mark;
            ++s_count;

            wchar_t buffer[320];
            swprintf(buffer, 320,
                L"[MapFocus] self=0x%llX mark=0x%llX  u32[b4]=%u u32[b8]=%u u32[d8]=%u u32[e8]=%u",
                (unsigned long long)(uintptr_t)self,
                (unsigned long long)(uintptr_t)mark,
                mark ? SafeReadU32((char*)mark + GameOffsets::OFF_MARK_U32_A, 0) : 0,
                mark ? SafeReadU32((char*)mark + GameOffsets::OFF_MARK_U32_B, 0) : 0,
                mark ? SafeReadU32((char*)mark + GameOffsets::OFF_MARK_U32_C, 0) : 0,
                mark ? SafeReadU32((char*)mark + GameOffsets::OFF_MARK_U32_D, 0) : 0);
            AddLog(buffer);
            DumpStack();
        }
    }

    if (Original_GMCFODMKJBC) {
        Original_GMCFODMKJBC(self, method);
    }
}

// ==================== UI context / 方法表 dump（热键 F9）====================
// 目的：不猜类名，直接看“当前开着哪些界面、各自是什么类、这个类有哪些方法”。
// 用法：打开冒险之证 -> 按 F9 -> 日志里会出现每个 context 的 klass 和方法 RVA 列表，
//       拿去和 full dump 7.1.cs 的 // RVA: 对，就能把类和方法叫出名字。
void DumpOpenUIContexts() {
    HMODULE mod = GetModuleHandleW(L"YuanShen.exe");
    if (!mod) {
        AddLog(L"[UIDump] YuanShen.exe not found");
        return;
    }

    const uintptr_t base = (uintptr_t)mod;

    void* metaBase = SafeReadPtr((void*)(base + ContextDump::RVA_META_BASE));
    if (!metaBase) {
        AddLog(L"[UIDump] metaBase null (IL2CPP not ready)");
        return;
    }

    void* list = SafeReadPtr((char*)metaBase + ContextDump::OFF_UI_OPEN_LIST);
    if (!list) {
        AddLog(L"[UIDump] UI open-list null");
        return;
    }

    void* items = SafeReadPtr((char*)list + ContextDump::OFF_LIST_ITEMS);
    const int count = (int)SafeReadU32((char*)list + ContextDump::OFF_LIST_SIZE, 0);

    wchar_t head[192];
    swprintf(head, 192, L"[UIDump] open contexts = %d (items=0x%llX)",
        count, (unsigned long long)(uintptr_t)items);
    AddLog(head);

    if (!items || count <= 0 || count > 64) {
        AddLog(L"[UIDump] list unusable or out of range");
        return;
    }

    for (int i = 0; i < count; ++i) {
        void* ctx = SafeReadPtr((char*)items + ContextDump::OFF_ARRAY_DATA + i * 8);
        if (!ctx) {
            continue;
        }

        void* klass = SafeReadPtr(ctx);
        if (!klass) {
            continue;
        }

        void* methods = SafeReadPtr((char*)klass + ContextDump::OFF_KLASS_METHODS);
        const int methodCount = (int)SafeReadU32((char*)klass + ContextDump::OFF_KLASS_METHOD_COUNT, 0);

        wchar_t line[192];
        swprintf(line, 192, L"[UIDump] ctx[%d] ctx=0x%llX klass=0x%llX methods=%d",
            i, (unsigned long long)(uintptr_t)ctx,
            (unsigned long long)(uintptr_t)klass, methodCount);
        AddLog(line);

        if (!methods || methodCount <= 0 || methodCount > 512) {
            continue;
        }

        std::wstringstream row;
        int inRow = 0;
        for (int j = 0; j < methodCount; ++j) {
            void* mi = SafeReadPtr((char*)methods + j * 8);
            void* fp = mi ? SafeReadPtr((char*)mi + ContextDump::OFF_METHOD_POINTER) : nullptr;
            if (!fp) {
                continue;
            }

            row << L" 0x" << std::hex << ((uintptr_t)fp - base);

            if (++inRow == 8) {
                AddLog(row.str());
                row.str(L"");
                row.clear();
                inRow = 0;
            }
        }

        if (inRow > 0) {
            AddLog(row.str());
        }
    }

    AddLog(L"[UIDump] done");
}

DWORD WINAPI HotkeyThread(LPVOID) {
    AddLog(L"[Hotkey] F9 = dump open UI contexts");

    bool wasDown = false;
    while (bRunning) {
        const bool down = (GetAsyncKeyState(VK_F9) & 0x8000) != 0;
        if (down && !wasDown) {
            AddLog(L"[Hotkey] F9 pressed");
            DumpOpenUIContexts();
        }
        wasDown = down;
        Sleep(80);
    }
    return 0;
}

// 冒险之证 context BJLLHHFDAEM 里“收单个 uint32 参数”的候选方法。
// 它们签名完全一致：void(void* self, uint32 id, MethodInfo*)，所以能用同一个模板
// 生成 12 个互不相同的 detour（MinHook 要求一个 detour 对一个目标）。
// 按按钮时哪个命中，哪个就是“前往/跳转”的处理函数。
namespace Handbook {
    struct Cand {
        uint64_t rva;
        const char* name;   // dump 里的混淆名，方便回查
    };

    const Cand kCands[] = {
        { 0xe437750, "OPABCOOIDMD" },
        { 0xe437b00, "OCMAPDLKHOK" },
        { 0xe448f90, "KCLBIFPBDPH" },
        { 0xe44e350, "LPHGPDJHOAG" },
        { 0xe45f280, "LCHBAJDJOMA" },
        { 0xe4605b0, "JCEBHGDEOAH" },
        { 0xe464060, "PEEJKKJACDH" },
        { 0xe464b20, "PMLAIBGFNCE" },
        { 0xe467310, "OGPANKGJPEM" },
        { 0xe4690f0, "NABPNKHAMDD" },
        { 0xe469ca0, "JMNFBOEHKNN" },
        { 0xe43d830, "FFOCODMCBGK" },
    };

    constexpr int kCount = (int)(sizeof(kCands) / sizeof(kCands[0]));

    using Fn = void(__fastcall*)(void* self, unsigned int id, void* method);

    LPVOID g_original[kCount] = {};
}

template <int I>
void __fastcall Hook_HandbookU32(void* self, unsigned int id, void* method) {
    if (bRunning) {
        // 同一个方法同一个 id 只记一次
        static unsigned int s_lastId = 0xFFFFFFFFu;
        static bool s_loggedAny = false;

        if (!s_loggedAny || s_lastId != id) {
            s_loggedAny = true;
            s_lastId = id;

            wchar_t buffer[256];
            swprintf(buffer, 256, L"[HB] %hs id=%u self=0x%llX",
                Handbook::kCands[I].name, id, (unsigned long long)(uintptr_t)self);
            AddLog(buffer);
            DumpStack();
        }
    }

    if (Handbook::g_original[I]) {
        ((Handbook::Fn)Handbook::g_original[I])(self, id, method);
    }
}

void InstallHandbookHooks(uintptr_t base) {
    LPVOID detours[Handbook::kCount] = {
        (LPVOID)&Hook_HandbookU32<0>,  (LPVOID)&Hook_HandbookU32<1>,
        (LPVOID)&Hook_HandbookU32<2>,  (LPVOID)&Hook_HandbookU32<3>,
        (LPVOID)&Hook_HandbookU32<4>,  (LPVOID)&Hook_HandbookU32<5>,
        (LPVOID)&Hook_HandbookU32<6>,  (LPVOID)&Hook_HandbookU32<7>,
        (LPVOID)&Hook_HandbookU32<8>,  (LPVOID)&Hook_HandbookU32<9>,
        (LPVOID)&Hook_HandbookU32<10>, (LPVOID)&Hook_HandbookU32<11>,
    };

    int ok = 0;
    for (int i = 0; i < Handbook::kCount; ++i) {
        if (MH_CreateHook((LPVOID)(base + Handbook::kCands[i].rva),
                          detours[i], &Handbook::g_original[i]) == MH_OK) {
            ++ok;
        }
    }

    wchar_t buffer[160];
    swprintf(buffer, 160, L"[HB] installed %d/%d handbook candidate hooks", ok, Handbook::kCount);
    AddLog(buffer);
}

// ==================== 按钮点击总网：UnityAction::Invoke ====================
// UnityEngine.Events.UnityAction::Invoke (Slot 10)  rcx = 委托对象本身
// 委托布局: klass(0x0) monitor(0x8) method_ptr(0x10) invoke_impl(0x18) m_target(0x20)
// 任何无参按钮/事件都从这里过，所以不用猜是哪个类的哪个方法 —— 一按就暴露处理函数。
void __fastcall Hooked_UnityActionInvoke(void* action) {
    if (bRunning && action) {
        void* methodPtr = SafeReadPtr((char*)action + 0x10);
        void* target = SafeReadPtr((char*)action + 0x20);

        static void* s_lastMethod = nullptr;
        static int s_count = 0;

        if (methodPtr != s_lastMethod && s_count < 300) {
            s_lastMethod = methodPtr;
            ++s_count;

            HMODULE mod = GetModuleHandleW(L"YuanShen.exe");
            const uintptr_t base = (uintptr_t)mod;
            const uintptr_t rva = methodPtr ? ((uintptr_t)methodPtr - base) : 0;

            wchar_t buffer[256];
            swprintf(buffer, 256, L"[Click] method=0x%llX (rva=0x%llX) target=0x%llX",
                (unsigned long long)(uintptr_t)methodPtr,
                (unsigned long long)rva,
                (unsigned long long)(uintptr_t)target);
            AddLog(buffer);
        }
    }

    if (Original_UnityActionInvoke) {
        Original_UnityActionInvoke(action);
    }
}

// UnityEngine.Events.UnityEvent::Invoke —— 按钮点击必经之路
// 顺着 UnityEventBase.m_Calls(+0x10) -> InvokableCallList.m_RuntimeCalls(+0x18)
//   -> List<BaseInvokableCall>._items(+0x10)/_size(+0x18) -> 数组数据(+0x20) 取第 0 项
//   -> InvokableCall.Delegate(+0x10) -> 委托.method_ptr(+0x10) / m_target(+0x20)
// 任一环解不出来就原样放过，绝不乱读。
int ResolveEventDelegate(void* evt, void** outDelegate) {
    if (!evt || !outDelegate) {
        return 0;
    }

    void* calls = SafeReadPtr((char*)evt + 0x10);          // InvokableCallList
    if (!calls) {
        return 0;
    }

    void* list = SafeReadPtr((char*)calls + 0x18);         // List<BaseInvokableCall>
    if (!list) {
        return 0;
    }

    void* items = SafeReadPtr((char*)list + 0x10);         // List._items
    const int count = (int)SafeReadU32((char*)list + 0x18, 0);
    if (!items || count <= 0) {
        return 0;
    }

    void* invokable = SafeReadPtr((char*)items + 0x20);    // 数组数据第 0 项
    if (!invokable) {
        return 0;
    }

    void* del = SafeReadPtr((char*)invokable + 0x10);      // InvokableCall.Delegate
    if (!del) {
        return 0;
    }

    *outDelegate = del;
    return 1;
}

void __fastcall Hooked_UnityEventInvoke(void* evt) {
    if (bRunning && evt) {
        void* del = nullptr;
        if (ResolveEventDelegate(evt, &del)) {
            void* methodPtr = SafeReadPtr((char*)del + 0x10);
            void* target = SafeReadPtr((char*)del + 0x20);

            static void* s_lastMethod = nullptr;
            static int s_count = 0;

            if (methodPtr != s_lastMethod && s_count < 300) {
                s_lastMethod = methodPtr;
                ++s_count;

                HMODULE mod = GetModuleHandleW(L"YuanShen.exe");
                const uintptr_t base2 = (uintptr_t)mod;
                const uintptr_t rva = methodPtr ? ((uintptr_t)methodPtr - base2) : 0;

                wchar_t buffer[256];
                swprintf(buffer, 256, L"[Evt] method=0x%llX (rva=0x%llX) target=0x%llX evt=0x%llX",
                    (unsigned long long)(uintptr_t)methodPtr,
                    (unsigned long long)rva,
                    (unsigned long long)(uintptr_t)target,
                    (unsigned long long)(uintptr_t)evt);
                AddLog(buffer);
            }
        }
    }

    if (Original_UnityEventInvoke) {
        Original_UnityEventInvoke(evt);
    }
}

// MoleMole.MonoUIContainer::OnClick —— 游戏自己封装的按钮点击入口
// 输出：按钮的 GameObject 路径 + 容器里存着的委托（method_ptr 的 RVA）。
// 容器字段布局未知，所以在 0x10~0x100 里扫"看起来像委托"的指针：
//   候选对象 +0x10 若落在模块代码段，就当它是 method_ptr。
void __fastcall Hooked_MonoUIContainerOnClick(void* self) {
    if (bRunning && self) {
        std::wstring path;
        if (Original_Component_GetGameObject) {
            void* go = Original_Component_GetGameObject(self);
            path = GetGameObjectPath(go);
        }

        AddLog(L"[Btn] path=" + (path.empty() ? std::wstring(L"<unknown>") : path));

        HMODULE mod = GetModuleHandleW(L"YuanShen.exe");
        const uintptr_t base2 = (uintptr_t)mod;
        const uintptr_t codeEnd = base2 + 0x1A000000;   // il2cpp 代码段上界（7.1 约 0x19e5b000）

        int found = 0;
        for (int off = 0x10; off < 0x100 && found < 8; off += 8) {
            void* cand = SafeReadPtr((char*)self + off);
            if (!cand || (uintptr_t)cand < 0x10000) {
                continue;
            }

            void* mp = SafeReadPtr((char*)cand + 0x10);
            const uintptr_t p = (uintptr_t)mp;
            if (p <= base2 || p >= codeEnd) {
                continue;
            }

            ++found;
            wchar_t buffer[256];
            swprintf(buffer, 256, L"[Btn]   off=0x%X delegate=0x%llX method=0x%llX rva=0x%llX",
                off,
                (unsigned long long)(uintptr_t)cand,
                (unsigned long long)p,
                (unsigned long long)(p - base2));
            AddLog(buffer);
        }
    }

    if (Original_MonoUIContainerOnClick) {
        Original_MonoUIContainerOnClick(self);
    }
}

// ==================== 按钮跳板闭包：把真正处理函数解出来 ====================
// 这两个闭包本身就是一行转调，真正的“前往”处理函数是它们捕获的 UnityAction。
template <int Which>
void __fastcall Hooked_ClickClosure(void* self) {
    if (bRunning && self) {
        void* action = SafeReadPtr((char*)self + ContextDump::OFF_CLOSURE_ACTION);
        if (action) {
            void* methodPtr = SafeReadPtr((char*)action + 0x10);   // 委托.method_ptr
            void* target = SafeReadPtr((char*)action + 0x20);      // 委托.m_target

            static void* s_last[2] = { nullptr, nullptr };
            static int s_count = 0;

            if (methodPtr && methodPtr != s_last[Which] && s_count < 100) {
                s_last[Which] = methodPtr;
                ++s_count;

                HMODULE mod = GetModuleHandleW(L"YuanShen.exe");
                const uintptr_t base2 = (uintptr_t)mod;

                wchar_t buffer[256];
                swprintf(buffer, 256,
                    L"[Closure%d] handler=0x%llX (rva=0x%llX) target=0x%llX",
                    Which,
                    (unsigned long long)(uintptr_t)methodPtr,
                    (unsigned long long)((uintptr_t)methodPtr - base2),
                    (unsigned long long)(uintptr_t)target);
                AddLog(buffer);
            }
        }
    }

    if (Which == 0) {
        if (Original_Closure0) Original_Closure0(self);
    } else {
        if (Original_Closure1) Original_Closure1(self);
    }
}

// ==================== 日志线程 ====================

DWORD WINAPI LogWriterThread(LPVOID) {
    // 创建日志目录
    std::wstring logDir = L"E:\\GameDumps\\";
    CreateDirectoryW(logDir.c_str(), nullptr);

    // 生成唯一的日志文件名
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    std::tm local_tm;
    localtime_s(&local_tm, &now_c);

    wchar_t filename[MAX_PATH];
    swprintf(filename, MAX_PATH,
        L"%sGameObject_Dump_%04d%02d%02d_%02d%02d%02d.log",
        logDir.c_str(),
        1900 + local_tm.tm_year, 1 + local_tm.tm_mon, local_tm.tm_mday,
        local_tm.tm_hour, local_tm.tm_min, local_tm.tm_sec);

    currentLogFile = filename;

    // 打开日志文件
    logFile.open(filename, std::ios::out | std::ios::app);
    if (!logFile.is_open()) {
        AddLog(L"ERROR: Failed to open log file: " + std::wstring(filename));
        return 1;
    }

    AddLog(L"GameObject Dumper initialized successfully");
    AddLog(L"YuanShen.exe handle: 0x" + std::to_wstring(reinterpret_cast<uintptr_t>(hUnityModule)));
    AddLog(L"Log file: " + currentLogFile);

    // 主循环：定期写入日志
    while (bRunning) {
        std::vector<std::wstring> logsToWrite;

        {
            std::lock_guard<std::mutex> lock(logMutex);
            if (!logBuffer.empty()) {
                logsToWrite.swap(logBuffer);
            }
        }

        if (!logsToWrite.empty()) {
            for (const auto& log : logsToWrite) {
                logFile << log << std::endl;
            }
            logFile.flush();
        }

        // 每2秒写入一次
        Sleep(2000);
    }

    // 清理
    logFile.close();
    AddLog(L"Log writer thread stopped", false);

    return 0;
}

// ==================== Hook管理 ====================

bool InitializeUnityFunctions() {
	Sleep(3000); // 等待游戏加载完成
    hUnityModule = GetModuleHandleW(L"YuanShen.exe");
    if (!hUnityModule) {
        AddLog(L"ERROR: YuanShen.exe not found!");
        return false;
    }

    uintptr_t base = reinterpret_cast<uintptr_t>(hUnityModule);

    Original_GetName = reinterpret_cast<Fn_GetName>(base + GameOffsets::GetName);
    Original_Transform_GetParent = reinterpret_cast<Fn_GetParent>(base + GameOffsets::Transform_GetParent);
    Original_GetTransform = reinterpret_cast<Fn_GetTransform>(base + GameOffsets::GetTransform);
    Original_Component_GetGameObject = reinterpret_cast<Fn_GetGameObject>(base + GameOffsets::Component_GetGameObject);

    if (!Original_GetName || !Original_Transform_GetParent) {
        AddLog(L"ERROR: Failed to initialize Unity function pointers");
        return false;
    }

    AddLog(L"Unity functions initialized successfully");
    return true;
}

bool InstallGameObjectHooks() {
    if (MH_Initialize() != MH_OK) {
        AddLog(L"ERROR: Failed to initialize MinHook");
        return false;
    }

    uintptr_t base = (uintptr_t)GetModuleHandleW(L"YuanShen.exe");

    // 冒险之证 context 全量钩子（409 个实例方法，日志落在 D:\dump\BJLLHHFDAEM\hooks.log）
    jk::InitHookLog("D:\\dump\\EKHBADNLJKF");
    RegisterEKHBADNLJKFHooks();
    const int bjInstalled = InstallEKHBADNLJKFHooks(base);
    {
        wchar_t buf[160];
        swprintf(buf, 160, L"[HBJ] installed %d/%d base-class hooks", bjInstalled, EKHBADNLJKFHookCount());
        AddLog(buf);
    }

    // Hook GameObject构造函数
    if (MH_CreateHook(
        reinterpret_cast<LPVOID>(base + GameOffsets::GameObject_Constructor),
        reinterpret_cast<LPVOID>(&Hooked_GameObject_ctor),
        reinterpret_cast<LPVOID*>(&Original_GameObject_ctor)
    ) != MH_OK) {
        AddLog(L"ERROR: Failed to create GameObject constructor hook");
        return false;
    }

    // Hook GameObject::SetActive
    if (GameOffsets::GameObject_SetActive != 0) {
        if (MH_CreateHook(
            reinterpret_cast<LPVOID>(base + GameOffsets::GameObject_SetActive),
            reinterpret_cast<LPVOID>(&Hooked_GameObject_SetActive),
            reinterpret_cast<LPVOID*>(&Original_GameObject_SetActive)
        ) != MH_OK) {
            AddLog(L"WARNING: Failed to create SetActive hook, continuing...");
        }
    }

    // Hook Text::set_Text (Slot 81)
    if (GameOffsets::Text_SetText != 0) {
        if (MH_CreateHook(
            reinterpret_cast<LPVOID>(base + GameOffsets::Text_SetText),
            reinterpret_cast<LPVOID>(&Hooked_Text_set_Text),
            reinterpret_cast<LPVOID*>(&Original_Text_set_Text)
        ) != MH_OK) {
            AddLog(L"WARNING: Failed to create Text::set_Text hook, continuing...");
        }
    }

    // Hook AKBPMKJEIDJ::PLCPFNFNJML —— 记录“谁在什么时候打开地图” + 调用栈
    if (GameOffsets::AKBPMKJEIDJ_PLCPFNFNJML != 0) {
        if (MH_CreateHook(
            reinterpret_cast<LPVOID>(base + GameOffsets::AKBPMKJEIDJ_PLCPFNFNJML),
            reinterpret_cast<LPVOID>(&Hooked_PLCPFNFNJML),
            reinterpret_cast<LPVOID*>(&Original_PLCPFNFNJML)
        ) != MH_OK) {
            AddLog(L"WARNING: Failed to create PLCPFNFNJML hook, continuing...");
        }
    }

    // Hook HHDNOGHMIOC::IOGOAAMKENJ —— 打印“前往/导航”的 markId + 世界坐标 + 调用栈
    if (GameOffsets::HHDNOGHMIOC_IOGOAAMKENJ != 0) {
        if (MH_CreateHook(
            reinterpret_cast<LPVOID>(base + GameOffsets::HHDNOGHMIOC_IOGOAAMKENJ),
            reinterpret_cast<LPVOID>(&Hooked_IOGOAAMKENJ),
            reinterpret_cast<LPVOID*>(&Original_IOGOAAMKENJ)
        ) != MH_OK) {
            AddLog(L"WARNING: Failed to create IOGOAAMKENJ hook, continuing...");
        }
    }

    // Hook DAEMCCNOCPF::OLNKJJKDBDM —— 打开 UI context 的同步入口，
    // 只在打开“地图 context”时记栈（比 SetupView 早好几帧，能抓到点击方）
    if (GameOffsets::DAEMCCNOCPF_OLNKJJKDBDM != 0) {
        if (MH_CreateHook(
            reinterpret_cast<LPVOID>(base + GameOffsets::DAEMCCNOCPF_OLNKJJKDBDM),
            reinterpret_cast<LPVOID>(&Hooked_UIOpen),
            reinterpret_cast<LPVOID*>(&Original_UIOpen)
        ) != MH_OK) {
            AddLog(L"WARNING: Failed to create OLNKJJKDBDM hook, continuing...");
        }
    }

    // Hook HHDNOGHMIOC::GMCFODMKJBC —— 另一条“定位”路径（用当前绑定的 mark）
    if (GameOffsets::HHDNOGHMIOC_GMCFODMKJBC != 0) {
        if (MH_CreateHook(
            reinterpret_cast<LPVOID>(base + GameOffsets::HHDNOGHMIOC_GMCFODMKJBC),
            reinterpret_cast<LPVOID>(&Hooked_GMCFODMKJBC),
            reinterpret_cast<LPVOID*>(&Original_GMCFODMKJBC)
        ) != MH_OK) {
            AddLog(L"WARNING: Failed to create GMCFODMKJBC hook, continuing...");
        }
    }

    // 冒险之证 context 的 12 个 uint32 候选方法（一个一个 hook）
    InstallHandbookHooks(base);

    // 按钮点击总网：UnityAction::Invoke（属于 UnityEngine.Events，不在 YuanShen 的偏移表里）
    if (MH_CreateHook(
        (LPVOID)(base + ContextDump::RVA_UNITY_ACTION_INVOKE),
        (LPVOID)&Hooked_UnityActionInvoke,
        (LPVOID*)&Original_UnityActionInvoke
    ) != MH_OK) {
        AddLog(L"WARNING: Failed to create UnityAction::Invoke hook, continuing...");
    }

    // 按钮点击总网：UnityEvent::Invoke（真正被 Button.Press 调用的那个）
    if (MH_CreateHook(
        (LPVOID)(base + ContextDump::RVA_UNITY_EVENT_INVOKE),
        (LPVOID)&Hooked_UnityEventInvoke,
        (LPVOID*)&Original_UnityEventInvoke
    ) != MH_OK) {
        AddLog(L"WARNING: Failed to create UnityEvent::Invoke hook, continuing...");
    }

    // 按钮点击入口：MonoUIContainer::OnClick（冒证“前往”走的是这条）
    if (MH_CreateHook(
        (LPVOID)(base + ContextDump::RVA_MONO_UI_CONTAINER_ONCLICK),
        (LPVOID)&Hooked_MonoUIContainerOnClick,
        (LPVOID*)&Original_MonoUIContainerOnClick
    ) != MH_OK) {
        AddLog(L"WARNING: Failed to create MonoUIContainer::OnClick hook, continuing...");
    }

    // 两个点击跳板闭包：解出它们捕获的真正处理函数
    if (MH_CreateHook((LPVOID)(base + ContextDump::RVA_CLOSURE_HMODIOPKHLJ),
                      (LPVOID)&Hooked_ClickClosure<0>,
                      (LPVOID*)&Original_Closure0) != MH_OK) {
        AddLog(L"WARNING: Failed to create closure0 hook");
    }
    if (MH_CreateHook((LPVOID)(base + ContextDump::RVA_CLOSURE_JBEINFOMBIC),
                      (LPVOID)&Hooked_ClickClosure<1>,
                      (LPVOID*)&Original_Closure1) != MH_OK) {
        AddLog(L"WARNING: Failed to create closure1 hook");
    }

    // 启用所有Hook
    if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK) {
        AddLog(L"ERROR: Failed to enable hooks");
        return false;
    }

    AddLog(L"GameObject hooks installed successfully");
    return true;
}

void UninstallHooks() {
    bRunning = false;

    // 等待日志线程结束
    if (hLogThread) {
        WaitForSingleObject(hLogThread, 3000);
        CloseHandle(hLogThread);
        hLogThread = nullptr;
    }

    // 禁用并移除Hook
    MH_DisableHook(MH_ALL_HOOKS);
    MH_Uninitialize();

    AddLog(L"All hooks uninstalled", false);

    // 写入最后一条日志
    if (logFile.is_open()) {
        logFile << L"[" << GetCurrentTimeString() << L"] GameObject Dumper stopped" << std::endl;
        logFile.close();
    }
}

// ==================== DLL入口点 ====================

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    UNREFERENCED_PARAMETER(lpReserved);

    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH: {
        // 防止重复初始化
        if (bInitialized) return TRUE;

        DisableThreadLibraryCalls(hModule);

        if (AllocConsole()) {
            FILE* f;
            freopen_s(&f, "CONOUT$", "w", stdout);
            freopen_s(&f, "CONOUT$", "w", stderr);
            freopen_s(&f, "CONIN$", "r", stdin);
        }

        SetConsoleTitleW(L"GameObject Dumper Debug Console");

        AddLog(L"=== GameObject Dumper DLL Loaded ===");

        // 初始化Unity函数
        if (!InitializeUnityFunctions()) {
            MessageBoxW(NULL,
                L"Failed to initialize Unity functions!\n"
                L"Please check the offset values in the code.",
                L"GameObject Dumper Error",
                MB_ICONERROR | MB_OK);
            return FALSE;
        }

        // 安装Hook
        if (!InstallGameObjectHooks()) {
            MessageBoxW(NULL,
                L"Failed to install hooks!\n"
                L"The game might crash or the dumper won't work.",
                L"GameObject Dumper Error",
                MB_ICONWARNING | MB_OK);
            return FALSE;
        }

        // 启动日志线程
        hLogThread = CreateThread(nullptr, 0, LogWriterThread, nullptr, 0, nullptr);
        if (!hLogThread) {
            AddLog(L"ERROR: Failed to create log writer thread");
            return FALSE;
        }

        bInitialized = true;

        // 启动热键线程（F9 = dump 当前打开的 UI context 及其方法表）
        hHotkeyThread = CreateThread(nullptr, 0, HotkeyThread, nullptr, 0, nullptr);
        if (!hHotkeyThread) {
            AddLog(L"WARNING: Failed to create hotkey thread (F9 dump unavailable)");
        }

        AddLog(L"GameObject Dumper fully initialized and running");
        bRunning = true;
        break;
    }

    case DLL_PROCESS_DETACH:
        if (bInitialized) {
            UninstallHooks();
            FreeConsole();
            bInitialized = false;
        }
        break;

    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        break;
    }

    return TRUE;
}
