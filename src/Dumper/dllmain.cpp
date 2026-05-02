#include "framework.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <mutex>
#include <thread>
#include <atomic>
#include <chrono>
#include <Psapi.h>
#include "MinHook.h"
#include <unordered_set>
#include <iostream>
#include <algorithm>


namespace GameOffsets {
    const uint64_t GetName = 0x16ca0230; //
    
    const uint64_t GetTransform = 0x16c88e00; //

    const uint64_t GameObject_Constructor = 0x10B7380; //
    const uint64_t GameObject_SetActive = 0x10B7D00; //

    const uint64_t Transform_GetParent = 0x16ca1e50; //
    const uint64_t ClosePage = 0x118e0840; //
}
// =============================================================

// 全局变量
HMODULE hUnityModule = nullptr;
HANDLE hLogThread = nullptr;
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
using Fn_GameObject_ctor = void* (__fastcall*)(void*, void*);
using Fn_GameObject_SetActive = void(__fastcall*)(void*, bool);
using Fn_ClosePage = void(__fastcall*)(void*);

// 原始函数指针
Fn_GetName Original_GetName = nullptr;
Fn_GetParent Original_Transform_GetParent = nullptr;
Fn_GetTransform Original_GetTransform = nullptr;
Fn_GameObject_ctor Original_GameObject_ctor = nullptr;
Fn_GameObject_SetActive Original_GameObject_SetActive = nullptr;
Fn_ClosePage Original_ClosePage = nullptr;

// Hook函数声明
void* __fastcall Hooked_GameObject_ctor(void* thisptr, void* name);
void __fastcall Hooked_GameObject_SetActive(void* thisptr, bool active);

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

void AddLog(const std::wstring& message, bool toConsole = true) {
    std::lock_guard<std::mutex> lock(logMutex);

    std::wstring formatted = L"[" + GetCurrentTimeString() + L"] " + message;
    logBuffer.push_back(formatted);

    if (toConsole) {
        std::wcout << ((formatted + L"\n").c_str()) << std::endl;
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
        L"InLevelClockPage"
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
        std::wstring nameStr = ReadUnityString(name);
        if (!nameStr.empty()) {
            std::wcout << nameStr << std::endl;
        }
    }

    if (bRunning && thisptr) {
        uintptr_t objPtr = reinterpret_cast<uintptr_t>(thisptr);
        {
            std::lock_guard<std::mutex> lock(cacheMutex);
            if (recordedGameObjects.find(objPtr) == recordedGameObjects.end()) {
                recordedGameObjects.insert(objPtr);

                std::wstring nameStr = ReadUnityString(name);
                AddLog(L"[Constructor] GameObject: " + (nameStr.empty() ? L"Unnamed" : nameStr));
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

void __fastcall Hooked_ClosePage(void* pThis) {
    DumpStack();
	Original_ClosePage(pThis);
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
    hUnityModule = GetModuleHandleW(L"YuanShen.exe");
    if (!hUnityModule) {
        AddLog(L"ERROR: YuanShen.exe not found!");
        return false;
    }

    uintptr_t base = reinterpret_cast<uintptr_t>(hUnityModule);

    Original_GetName = reinterpret_cast<Fn_GetName>(base + GameOffsets::GetName);
    Original_Transform_GetParent = reinterpret_cast<Fn_GetParent>(base + GameOffsets::Transform_GetParent);
    Original_GetTransform = reinterpret_cast<Fn_GetTransform>(base + GameOffsets::GetTransform);

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

	if (GameOffsets::ClosePage != 0) {
        if (MH_CreateHook(
            reinterpret_cast<LPVOID>(base + GameOffsets::ClosePage),
            reinterpret_cast<LPVOID>(&Hooked_ClosePage),
			reinterpret_cast<LPVOID*>(&Original_ClosePage)
        ) != MH_OK) {
            AddLog(L"WARNING: Failed to create ClosePage hook, continuing...");
        }
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

extern "C" __declspec(dllexport) const wchar_t* GetDumperStatus() {
    static wchar_t status[512];
    swprintf(status, sizeof(status) / sizeof(wchar_t),
        L"Status: %s\n"
        L"Initialized: %s\n"
        L"Cached Objects: %zu\n"
        L"Pending Logs: %zu\n"
        L"Log File: %s",
        bRunning ? L"RUNNING" : L"STOPPED",
        bInitialized ? L"YES" : L"NO",
        recordedGameObjects.size(),
        logBuffer.size(),
        currentLogFile.c_str());

    return status;
}

extern "C" __declspec(dllexport) void SetVerboseMode(bool verbose) {
    // 这里可以添加详细模式的控制逻辑
    AddLog(std::wstring(L"Verbose mode ") + (verbose ? L"enabled" : L"disabled"));
}

extern "C" __declspec(dllexport) void DumpCurrentScene() {
    AddLog(L"Manual scene dump requested");
    // 这里可以添加遍历当前场景所有GameObject的逻辑
}
