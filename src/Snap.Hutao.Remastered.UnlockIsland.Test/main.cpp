#include "pch.h"
#include "PatternScanner.h"
#include <iostream>
#include <iomanip>
#include <filesystem>
#include <Windows.h>
#include <chrono>

// 包含HookEnvironment结构定义
#include "../../Snap.Hutao.Remastered.UnlockIsland/HookEnvironment.h"

using namespace winrt;
using namespace Windows::Foundation;

const wchar_t* SHARED_MEM_NAME = L"4F3E8543-40F7-4808-82DC-21E48A6037A7";

std::string OpenTeamPattern = "48 83 EC 28 80 3D ?? ?? ?? ?? 00 75 23 48 8B 0D ?? ?? ?? ?? 80 B9 ?? ?? ?? ?? 00 74 3A";
std::string OpenTeamPageAccordinglyPattern = "56 57 53 48 83 EC 20 89 CB 80 3D ?? ?? ?? ?? 00 74 7A 80 3D ?? ?? ?? ?? 00 48 8B 05 ?? ?? ?? ?? 0F 85 ?? ?? ?? ?? 48 8B 90 ?? ?? ?? ?? 48 85 D2 0F 84 ?? ?? ?? ?? 80 3D ?? ?? ?? ?? 00 0F 85 ?? ?? ?? ?? 48 8B 88";
std::string SwitchInputDeviceToTouchScreenPattern = "56 57 48 83 EC 28 48 89 CE 80 3D ?? ?? ?? ?? 00 48 8B 05 ?? ?? ?? ?? 0F 85 ?? ?? ?? ?? 48 8B 88 ?? ?? ?? ?? 48 85 C9 0F 84 ?? ?? ?? ?? 48 8B 15 ?? ?? ?? ?? E8 ?? ?? ?? ?? 48 89 C7 48 8B 05 ?? ?? ?? ?? 48 8B 88 ?? ?? ?? ?? 48 85 C9 0F 84";

bool CreateSharedMemoryForHookEnvironment(HookEnvironment*& pEnv, HANDLE& hMapFile);
void InitializeHookEnvironment(HANDLE hProcess, const std::wstring& moduleName, HookEnvironment* pEnv);
void CleanupSharedMemory(HookEnvironment* pEnv, HANDLE hMapFile);

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
    
    std::filesystem::path dllPath(currentDir);
    dllPath /= L"Snap.Hutao.Remastered.UnlockIsland.dll";
    
    if (!std::filesystem::exists(dllPath)) {
		dllPath = std::filesystem::path(currentDir);
        dllPath = dllPath.parent_path();
        dllPath /= L"Snap.Hutao.Remastered.UnlockIsland";
        dllPath /= L"x64";
        dllPath /= L"Debug";
        dllPath /= L"Snap.Hutao.Remastered.UnlockIsland.dll";
    }

    if (!std::filesystem::exists(dllPath))
    {
        std::wcerr << L"DLL not found at: " << dllPath.wstring() << std::endl;
        std::wcerr << L"Please build the main project first." << std::endl;
        return L"";
    }
    
    return dllPath.wstring();
}

void Inject()
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

    std::wstring moduleName = L"YuanShen.exe";

    if (hProcess != nullptr)
    {
        std::wcout << L"\n=== Starting DLL Injection ===" << std::endl;
        HookEnvironment* pEnv = nullptr;
        HANDLE hMapFile = NULL;

        std::wcout << L"\n=== Creating Shared Memory for Configuration ===" << std::endl;
        if (CreateSharedMemoryForHookEnvironment(pEnv, hMapFile))
        {
            InitializeHookEnvironment(hProcess, moduleName, pEnv);

            std::wcout << L"Configuration parameters prepared for DLL." << std::endl;

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

bool CreateSharedMemoryForHookEnvironment(HookEnvironment*& pEnv, HANDLE& hMapFile)
{
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

DWORD ScanOffset(HANDLE hProcess, const std::wstring& moduleName, const std::string& pattern, const std::string& name)
{
    auto start = std::chrono::high_resolution_clock::now();
    
    DWORD offset = PatternScanner::ScanPatternInModuleMultiThreaded(hProcess, moduleName, pattern, 16);
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
    std::cout << name << " Offset= 0x" << std::hex << offset << std::dec 
              << " (Time: " << duration.count() << "ms)" << std::endl;
    return offset;
}

DWORD ScanOffsetMultiThreaded(HANDLE hProcess, const std::wstring& moduleName, const std::string& pattern, const std::string& name, int threadCount = 16)
{
    auto start = std::chrono::high_resolution_clock::now();
    
    DWORD offset = PatternScanner::ScanPatternInModuleMultiThreaded(hProcess, moduleName, pattern, threadCount);
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    
    std::cout << name << " Offset= 0x" << std::hex << offset << std::dec 
              << " (Time: " << duration.count() << "ms)" << std::endl;
    return offset;
}

void InitializeHookEnvironment(HANDLE hProcess, const std::wstring& moduleName, HookEnvironment* pEnv)
{
    if (pEnv == nullptr)
        return;
    
    ZeroMemory(pEnv, sizeof(HookEnvironment));
    pEnv->Size = sizeof(HookEnvironment);
    pEnv->State = TRUE;
    pEnv->LastError = 0;
    pEnv->Uid = 123456; // 示例UID
    
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
    pEnv->TouchMode = TRUE;
    pEnv->RedirectCombine = FALSE;
    pEnv->ResinItem000106 = FALSE;
    pEnv->ResinItem000201 = FALSE;
    pEnv->ResinItem107009 = FALSE;
    pEnv->ResinItem107012 = FALSE;
    pEnv->ResinItem220007 = FALSE;

    pEnv->Offsets.MickeyWonderMethod = 0x5e0d680; //
    pEnv->Offsets.MickeyWonderMethodPartner = 0x3e87b0; //
    pEnv->Offsets.MickeyWonderMethodPartner2 = 0x7728b90; //
    pEnv->Offsets.SetFieldOfView = 0x10407c0; //
    pEnv->Offsets.SetEnableFogRendering = 0x14f2cb90; //
    pEnv->Offsets.SetTargetFrameRate = 0x14f18ea0; //
    pEnv->Offsets.OpenTeam = ScanOffset(hProcess, moduleName, OpenTeamPattern, "OpenTeam"); //
    pEnv->Offsets.OpenTeamPageAccordingly = ScanOffset(hProcess, moduleName, OpenTeamPageAccordinglyPattern, "OpenTeamPageAccordingly");
    pEnv->Offsets.CheckCanEnter = 0x954f230; //
    pEnv->Offsets.SetupQuestBanner = 0xdbb1320; //
    pEnv->Offsets.FindGameObject = 0x14f1bf20; //
    pEnv->Offsets.SetActive = 0x14f1bc60; //
    pEnv->Offsets.EventCameraMove = 0xe076e80; //
    pEnv->Offsets.ShowOneDamageTextEx = 0xfea2160; //
    //pEnv->Offsets.SwitchInputDeviceToTouchScreen = 0xab06670;
    pEnv->Offsets.SwitchInputDeviceToTouchScreen = ScanOffset(hProcess, moduleName, SwitchInputDeviceToTouchScreenPattern, "SwitchInputDeviceToTouchScreen"); //
    pEnv->Offsets.MickeyWonderCombineEntryMethod = 0xa0a2d00; //
    pEnv->Offsets.MickeyWonderCombineEntryMethodPartner = 0x84fb720; //
    pEnv->Offsets.GetTargetFrameRate = 0x125a050; //
    pEnv->Offsets.GameManagerAwake = 0xc4007c0; //
    //pEnv->Offsets.SetupResinList = 0xd03a400; //!!!!!!!!!!
    //pEnv->Offsets.ResinListRemove = 0x13CDA8C0;
    //pEnv->Offsets.ResinList = 0x1F0;
    //pEnv->Offsets.ResinListGetItem = 0x13CD8FF0;
    //pEnv->Offsets.ResinListGetCount = 0x13CD8F90;
    //pEnv->Offsets.SetLastUid = 0x0F43BA90;
    
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
    
    std::wcout << L"=== Pattern Scanner and DLL Injector ===" << std::endl;

    Inject();
    
    std::wcout << L"\nPress any key to exit..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    
    return 0;
}
