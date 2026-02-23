#include <windows.h>
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
    // GameObject相关函数
    const uint64_t GetName = 0x15B79680; //
    
    const uint64_t GetGameObject = 0x15B626E0; //
    const uint64_t GetTransform = 0x15B622B0; //

    // 关键函数Hook点
    const uint64_t GameObject_Constructor = 0x1063BC0; //
    const uint64_t GameObject_SetActive = 0x1063450; //

    // Transform函数
    const uint64_t Transform_GetChild = 0x15B7F420; //
    const uint64_t Transform_GetChildCount = 0x15B7F2A0; //
    const uint64_t Transform_GetParent = 0x15B7B2A0; //
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
using Fn_GetGameObject = void* (__fastcall*)(void*);
using Fn_GetTransform = void* (__fastcall*)(void*);
using Fn_GameObject_OnEnable = void(__fastcall*)(void*);
using Fn_GameObject_ctor = void* (__fastcall*)(void*, void*);
using Fn_GameObject_SetActive = void(__fastcall*)(void*, bool);

// 原始函数指针
Fn_GetName Original_GetName = nullptr;
Fn_GetParent Original_Transform_GetParent = nullptr;
Fn_GetGameObject Original_GetGameObject = nullptr;
Fn_GetTransform Original_GetTransform = nullptr;
Fn_GameObject_ctor Original_GameObject_ctor = nullptr;
Fn_GameObject_SetActive Original_GameObject_SetActive = nullptr;

// Hook函数声明
void* __fastcall Hooked_GameObject_ctor(void* thisptr, void* name);
void __fastcall Hooked_GameObject_SetActive(void* thisptr, bool active);

// ==================== 工具函数 ====================

std::wstring ReadUnityString(void* str) {
    if (!str) {
        return L"";
    }

    try {
        // 将指针转换为 uintptr_t 并加上 0x14 偏移
        uintptr_t ptr = reinterpret_cast<uintptr_t>(str);
        wchar_t* stringPtr = reinterpret_cast<wchar_t*>(ptr + 0x14);
        
        // 读取字符串
        std::wstring result = stringPtr;
        
        // 检查字符串是否为空或等于 "none"（不区分大小写）
        if (result.empty()) {
            return L"";
        }
        
        // 转换为小写进行比较
        std::wstring lowerResult = result;
        std::transform(lowerResult.begin(), lowerResult.end(), lowerResult.begin(), ::towlower);
        
        if (lowerResult == L"none") {
            return L"";
        }
        
        return result;
    }
    catch (...) {
        // 捕获所有异常，返回空字符串
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
            // 防止循环引用
            if (visited.find(current) != visited.end()) {
                pathParts.insert(pathParts.begin(), L"[CIRCULAR]");
                break;
            }
            visited.insert(current);

            // 获取当前transform的名称
            void* nameStr = Original_GetName(current);
            std::wstring name = ReadUnityString(nameStr);

            if (name.empty()) {
                pathParts.insert(pathParts.begin(), L"Unnamed");
                break;
            }

            pathParts.insert(pathParts.begin(), name);

            // 获取父transform
            void* parent = Original_Transform_GetParent(current);
            if (!parent || parent == current) {
                break;
            }

            current = parent;
            depth++;
        }

        // 构建完整路径
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
    // 只记录重要的GameObject，避免日志过大
    static const std::vector<std::wstring> importantKeywords = {
        L"Grass", L"grass"
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
                AddLog(L"[Constructor] GameObject: " + (nameStr.empty() ? L"Unnamed" : nameStr) +
                    L" | Ptr: 0x" + std::to_wstring(objPtr));
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
                L" | Path: " + path + L" | Ptr: 0x" +
                std::to_wstring(reinterpret_cast<uintptr_t>(thisptr)));
        }
    }

    if (Original_GameObject_SetActive) {
        Original_GameObject_SetActive(thisptr, active);
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
    hUnityModule = GetModuleHandleW(L"YuanShen.exe");
    if (!hUnityModule) {
        AddLog(L"ERROR: YuanShen.exe not found!");
        return false;
    }

    uintptr_t base = reinterpret_cast<uintptr_t>(hUnityModule);

    // 初始化函数指针
    Original_GetName = reinterpret_cast<Fn_GetName>(base + GameOffsets::GetName);
    Original_Transform_GetParent = reinterpret_cast<Fn_GetParent>(base + GameOffsets::Transform_GetParent);
    Original_GetGameObject = reinterpret_cast<Fn_GetGameObject>(base + GameOffsets::GetGameObject);
    Original_GetTransform = reinterpret_cast<Fn_GetTransform>(base + GameOffsets::GetTransform);

    // 验证函数指针
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
