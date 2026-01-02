#include "pch.h"
#include "PatternScanner.h"
#include <iostream>
#include <iomanip>
#include <filesystem>
#include <Windows.h>

// 包含HookEnvironment结构定义
#include "../../Snap.Hutao.Remastered.UnlockIsland/HookEnvironment.h"

using namespace winrt;
using namespace Windows::Foundation;

bool CreateSharedMemoryForHookEnvironment(HookEnvironment*& pEnv, HANDLE& hMapFile);
void InitializeHookEnvironment(HookEnvironment* pEnv);
void CleanupSharedMemory(HookEnvironment* pEnv, HANDLE hMapFile);

// 辅助函数：获取模块基址
uintptr_t GetModuleBaseAddress(HANDLE hProcess, const std::wstring& moduleName)
{
    MODULEENTRY32W me = { 0 };
    DWORD pid = GetProcessId(hProcess);
    if (pid == 0)
    {
        return 0;
    }

    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, pid);
    if (hSnapshot == INVALID_HANDLE_VALUE)
    {
        return 0;
    }

    me.dwSize = sizeof(MODULEENTRY32W);
    if (Module32FirstW(hSnapshot, &me))
    {
        do
        {
            if (moduleName == me.szModule)
            {
                CloseHandle(hSnapshot);
                return reinterpret_cast<uintptr_t>(me.modBaseAddr);
            }
        } while (Module32NextW(hSnapshot, &me));
    }

    CloseHandle(hSnapshot);
    return 0;
}

std::wstring GetDLLPath()
{
    wchar_t currentDir[MAX_PATH];
    GetCurrentDirectoryW(MAX_PATH, currentDir);
    
    // 构建DLL路径
    std::filesystem::path dllPath(currentDir);
    dllPath /= L"Snap.Hutao.Remastered.UnlockIsland.dll";
    
    if (!std::filesystem::exists(dllPath)) {
		dllPath = std::filesystem::path(currentDir);
        dllPath = dllPath.parent_path();
        dllPath /= L"Snap.Hutao.Remastered.UnlockIsland";
        dllPath /= L"x64";
        dllPath /= L"Debug";
    }

    if (!std::filesystem::exists(dllPath))
    {
        std::wcerr << L"DLL not found at: " << dllPath.wstring() << std::endl;
        std::wcerr << L"Please build the main project first." << std::endl;
        return L"";
    }
    
    return dllPath.wstring();
}

void TestPatternScannerAndInject()
{
    std::wcout << L"=== Automated Pattern Scanner and DLL Injector ===" << std::endl;
    std::wcout << L"Looking for game process..." << std::endl;

    std::wstring dllPath = GetDLLPath();
    if (dllPath.empty())
    {
        return;
    }
    
    std::wcout << L"DLL found at: " << dllPath << std::endl;

    HANDLE hProcess = PatternScanner::OpenProcessHandle(L"YuanShen.exe");

    if (hProcess == nullptr)
    {
        std::wcout << L"Failed to open YuanShen.exe. Trying GenshinImpact.exe..." << std::endl;
        hProcess = PatternScanner::OpenProcessHandle(L"GenshinImpact.exe");
    }

    if (hProcess == nullptr)
    {
        std::wcout << L"No target process found. Please ensure the game is running." << std::endl;
        return;
    }

    std::wcout << L"Process found for scanning." << std::endl;

    // 特征码扫描
    std::string pattern = "48 83 EC 28 80 3D ?? ?? ?? ?? 00 75 23 48 8B 0D ?? ?? ?? ?? 80 B9 ?? ?? ?? ?? 00 74 3A";
    std::wstring moduleName = L"YuanShen.exe";
    DWORD foundAddress = PatternScanner::ScanPatternInModule(hProcess, moduleName, pattern);
    if (foundAddress == 0)
    {
        moduleName = L"GenshinImpact.exe";
        foundAddress = PatternScanner::ScanPatternInModule(hProcess, moduleName, pattern);
    }

    if (hProcess != nullptr)
    {
        std::wcout << L"\n=== Starting DLL Injection ===" << std::endl;
        HookEnvironment* pEnv = nullptr;
        HANDLE hMapFile = NULL;

        std::wcout << L"\n=== Creating Shared Memory for Configuration ===" << std::endl;
        if (CreateSharedMemoryForHookEnvironment(pEnv, hMapFile))
        {
            // 初始化HookEnvironment结构
            InitializeHookEnvironment(pEnv);

            std::wcout << L"Configuration parameters prepared for DLL." << std::endl;

            // 注入DLL
            if (PatternScanner::InjectDLL(hProcess, dllPath))
            {
                std::wcout << L"\n=== Injection Successful ===" << std::endl;
                std::wcout << L"DLL has been injected into the game process." << std::endl;
                std::wcout << L"The game should now have the unlock island functionality." << std::endl;
            }
            else
            {
                std::wcerr << L"\n=== Injection Failed ===" << std::endl;
                std::wcerr << L"Failed to inject DLL into the game process." << std::endl;
            }
        }
        else
        {
            std::wcerr << L"Failed to create shared memory. Injection aborted." << std::endl;
        }

        CloseHandle(hProcess);
    }
    else
    {
        std::wcerr << L"Failed to open process with injection permissions: " << GetLastError() << std::endl;
    }

    std::wcout << L"\n=== Operation Completed ===" << std::endl;
}

// 创建共享内存用于HookEnvironment
bool CreateSharedMemoryForHookEnvironment(HookEnvironment*& pEnv, HANDLE& hMapFile)
{
    // 共享内存名称（必须与dllmain.cpp中的名称匹配）
    const wchar_t* SHARED_MEM_NAME = L"4F3E8543-40F7-4808-82DC-21E48A6037A7";
    
    // 创建文件映射对象
    hMapFile = CreateFileMappingW(
        INVALID_HANDLE_VALUE,
        NULL,
        PAGE_READWRITE,
        0,
        sizeof(HookEnvironment),
        SHARED_MEM_NAME
    );
    
    if (hMapFile == NULL)
    {
        std::wcerr << L"Failed to create shared memory: " << GetLastError() << std::endl;
        return false;
    }
    
    // 映射共享内存的视图
    pEnv = (HookEnvironment*)MapViewOfFile(
        hMapFile,
        FILE_MAP_ALL_ACCESS,
        0,
        0,
        sizeof(HookEnvironment)
    );
    
    if (pEnv == NULL)
    {
        std::wcerr << L"Failed to map view of shared memory: " << GetLastError() << std::endl;
        CloseHandle(hMapFile);
        return false;
    }
    
    std::wcout << L"Shared memory created successfully." << std::endl;
    return true;
}

// 初始化HookEnvironment结构
void InitializeHookEnvironment(HookEnvironment* pEnv)
{
    if (pEnv == nullptr)
        return;
    
    // 初始化结构体
    ZeroMemory(pEnv, sizeof(HookEnvironment));
    pEnv->Size = sizeof(HookEnvironment);
    pEnv->State = TRUE;
    pEnv->LastError = 0;
    pEnv->Uid = 123456; // 示例UID
    
    // 设置各种功能选项（示例配置）
    pEnv->EnableSetFov = FALSE;
    pEnv->FieldOfView = 90.0f;
    pEnv->FixLowFov = FALSE;
    pEnv->DisableFog = FALSE;
    pEnv->EnableSetFps = FALSE;
    pEnv->TargetFps = 120;
    pEnv->RemoveTeamProgress = TRUE;
    pEnv->HideQuestBanner = FALSE;
    pEnv->DisableCameraMove = FALSE;
    pEnv->DisableDamageText = FALSE;
    pEnv->TouchMode = FALSE;
    pEnv->RedirectCombine = FALSE;
    pEnv->ResinItem000106 = FALSE;
    pEnv->ResinItem000201 = FALSE;
    pEnv->ResinItem107009 = FALSE;
    pEnv->ResinItem107012 = FALSE;
    pEnv->ResinItem220007 = FALSE;
    
    std::wcout << L"HookEnvironment initialized with configuration." << std::endl;
}

// 清理共享内存
void CleanupSharedMemory(HookEnvironment* pEnv, HANDLE hMapFile)
{
    if (pEnv != nullptr)
    {
        UnmapViewOfFile(pEnv);
    }
    
    if (hMapFile != NULL)
    {
        CloseHandle(hMapFile);
    }
    
    std::wcout << L"Shared memory cleaned up." << std::endl;
}

int main()
{
    init_apartment();
    
    TestPatternScannerAndInject();
    
    std::wcout << L"\nPress any key to exit..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    
    return 0;
}
