#include "pch.h"
#include "PatternScanner.h"
#include <iostream>
#include <iomanip>
#include <filesystem>
#include <Windows.h>
#include <ShellAPI.h>
#include <chrono>

#include "../../Snap.Hutao.Remastered.UnlockIsland/HookEnvironment.h"

using namespace winrt;
using namespace Windows::Foundation;

const wchar_t* SHARED_MEM_NAME = L"4F3E8543-40F7-4808-82DC-21E48A6037A7";

std::string GetFrameCountPattern = "E8 ? ? ? ? 85 C0 7E 0E E8 ? ? ? ? 0F 57 C0 F3 0F 2A C0 EB 08";
std::string SetFrameCountPattern = "E8 ? ? ? ? E8 ? ? ? ? 83 F8 1F 0F 9C 05 ? ? ? ? 48 8B 05";
std::string SetFovPattern = "40 53 48 83 EC 60 0F 29 74 24 ? 48 8B D9 0F 28 F1 E8 ? ? ? ? 48 85 C0 0F 84 ? ? ? ? E8 ? ? ? ? 48 8B C8 ";
std::string SwitchInputDeviceToTouchScreenPattern = "56 57 48 83 EC ? 48 89 CE 80 3D ? ? ? ? 00 48 8B 05 ? ? ? ? 0F 85 ? ? ? ? 48 8B 88 ? ? ? ? 48 85 C9 0F 84 ? ? ? ? 48 8B 15 ? ? ? ? E8 ? ? ? ? 48 89 C7 48 8B 05 ? ? ? ? 48 8B 88 ? ? ? ? 48 85 C9 0F 84 ? ? ? ? 31 D2";
std::string SetupQuestBannerPattern = "41 57 41 56 56 57 55 53 48 81 EC ? ? ? ? 0F 29 BC 24 ? ? ? ? 0F 29 B4 24 ? ? ? ? 48 89 CE 80 3D ? ? ? ? 00 0F 85 ? ? ? ? 48 8B 96";
std::string FindGameObjectPattern = "E9 ? ? ? ? 66 66 2E 0F 1F 84 00 ? ? ? ? E9 ? ? ? ? 66 66 2E 0F 1F 84 00 ? ? ? ? E9 ? ? ? ? 66 66 2E 0F 1F 84 00 ? ? ? ? 48 83 EC ? C7 44 24 ? 00 00 00 00 48 8D 54 24";
std::string SetActivePattern = "E9 ? ? ? ? 66 66 2E 0F 1F 84 00 ? ? ? ? E9 ? ? ? ? 66 66 2E 0F 1F 84 00 ? ? ? ? E9 ? ? ? ? 66 66 2E 0F 1F 84 00 ? ? ? ? E9 ? ? ? ? 66 66 2E 0F 1F 84 00 ? ? ? ? E9 ? ? ? ? 66 66 2E 0F 1F 84 00 ? ? ? ? E9 ? ? ? ? 66 66 2E 0F 1F 84 00 ? ? ? ? E9 ? ? ? ? 66 66 2E 0F 1F 84 00 ? ? ? ? E9 ? ? ? ? 66 66 2E 0F 1F 84 00 ? ? ? ? E9 ? ? ? ? 66 66 2E 0F 1F 84 00 ? ? ? ? E9 ? ? ? ? 66 66 2E 0F 1F 84 00 ? ? ? ? E9 ? ? ? ? 66 66 2E 0F 1F 84 00 ? ? ? ? E9 ? ? ? ? 66 66 2E 0F 1F 84 00 ? ? ? ? E9 ? ? ? ? 66 66 2E 0F 1F 84 00 ? ? ? ? E9 ? ? ? ? 66 66 2E 0F 1F 84 00 ? ? ? ? E9 ? ? ? ? 66 66 2E 0F 1F 84 00 ? ? ? ? E9 ? ? ? ? 66 66 2E 0F 1F 84 00 ? ? ? ? E9 ? ? ? ? 66 66 2E 0F 1F 84 00 ? ? ? ? E9 ? ? ? ? 66 66 2E 0F 1F 84 00 ? ? ? ? E9 ? ? ? ? 66 66 2E 0F 1F 84 00 ? ? ? ? E9 ? ? ? ? 66 66 2E 0F 1F 84 00 ? ? ? ? 45 31 C9";
std::string EventCameraMovePattern = "41 57 41 56 56 57 55 53 48 83 EC ? 48 89 D7 49 89 CE 80 3D ? ? ? ? 00 0F 85 ? ? ? ? 80 3D ? ? ? ? 00";
std::string ShowOneDamageTextExPattern = "41 57 41 56 41 55 41 54 56 57 55 53 48 81 EC ? ? ? ? 44 0F 29 9C 24 ? ? ? ? 44 0F 29 94 24 ? ? ? ? 44 0F 29 8C 24 ? ? ? ? 44 0F 29 84 24 ? ? ? ? 0F 29 BC 24 ? ? ? ? 0F 29 B4 24 ? ? ? ? 44 89 CF 45 89 C4";
std::string DisplayFogPattern = "0F B6 02 88 01 8B 42 04 89 41 04 F3 0F 10 52 ? F3 0F 10 4A ? F3 0F 10 42 ? 8B 42 08 ";
std::string PlayerPerspectivePattern = "E8 ? ? ? ? 48 8B BE ? ? ? ? 80 3D ? ? ? ? ? 0F 85 ? ? ? ? 80 BE ? ? ? ? ? 74 11";
std::string FindStringPattern = "56 48 83 ec 20 48 89 ce e8 ? ? ? ? 48 89 f1 89 c2 48 83 c4 20 5e e9 ? ? ? ? cc cc cc cc";
std::string CraftEntryPartnerPattern = "41 57 41 56 41 55 41 54 56 57 55 53 48 81 EC ? ? ? ? 4D 89 ? 4C 89 C6 49 89 D4 49 89 CE";
std::string CraftEntryPattern = "41 56 56 57 53 48 83 EC 58 49 89 CE 80 3D ? ? ? ? 00 0F 84 ? ? ? ? 80 3D ? ? ? ? 00 48 8B 0D ? ? ? ? 0F 85";
std::string CheckCanEnterPattern = "56 48 81 ec 80 00 00 00 80 3d ? ? ? ? 00 0f 84 ? ? ? ? 80 3d ? ? ? ? 00";
std::string OpenTeamPageAccordinglyPattern = "56 57 53 48 83 ec 20 89 cb 80 3d ? ? ? ? 00 74 7a 80 3d ? ? ? ? 00 48 8b 05";
std::string OpenTeamPattern = "48 83 EC ? 80 3D ? ? ? ? 00 75 ? 48 8B 0D ? ? ? ? 80 B9 ? ? ? ? 00 0F 84 ? ? ? ? B9 ? ? ? ? E8 ? ? ? ? 84 C0 75";

bool CreateSharedMemoryForHookEnvironment(HookEnvironment*& pEnv, HANDLE& hMapFile);
void InitializeHookEnvironment(HANDLE hProcess, const std::wstring& moduleName, HookEnvironment* pEnv);

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
    wchar_t exePath[MAX_PATH];
    GetModuleFileNameW(nullptr, exePath, MAX_PATH);
    std::filesystem::path dllPath = std::filesystem::path(exePath).parent_path() / L"Snap.Hutao.Remastered.UnlockIsland.dll";

    if (std::filesystem::exists(dllPath))
    {
        return dllPath.wstring();
    }

    std::wcerr << L"DLL not found in current directory: " << dllPath.wstring() << std::endl;
    std::wcerr << L"Please place Snap.Hutao.Remastered.UnlockIsland.dll in the current directory." << std::endl;
    return L"";
}

void Inject()
{
    std::wstring dllPath = GetDLLPath();
    if (dllPath.empty())
    {
        return;
    }

    HANDLE hProcess = PatternScanner::OpenProcessHandle(L"YuanShen.exe");

    if (hProcess == nullptr)
    {
        hProcess = PatternScanner::OpenProcessHandle(L"GenshinImpact.exe");
    }

    if (hProcess == nullptr)
    {
        return;
    }
    HookEnvironment* pEnv = nullptr;
    HANDLE hMapFile = NULL;

    if (CreateSharedMemoryForHookEnvironment(pEnv, hMapFile))
    {
        InitializeHookEnvironment(hProcess, L"YuanShen.exe", pEnv);

        PatternScanner::InjectDLL(hProcess, dllPath);
    }

    CloseHandle(hProcess);
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

    return true;
}

DWORD ScanOffset(HANDLE hProcess, const std::wstring& moduleName, const std::string& pattern, const std::string& name)
{
    DWORD offset = PatternScanner::ScanPatternInModule(hProcess, moduleName, pattern);
    
    if (offset != 0) {
        std::cout << name << " Offset = 0x" << offset << std::hex << std::endl;
    } else {
        std::cout << name << " Offset not found" << std::endl;
    }
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
    
    pEnv->EnableSetFov = TRUE;
    pEnv->FieldOfView = 90.0f;
    pEnv->FixLowFov = FALSE;
    pEnv->DisableFog = TRUE;
    pEnv->EnableSetFps = TRUE;
    pEnv->TargetFps = 240;
    pEnv->RemoveTeamProgress = TRUE;
    pEnv->HideQuestBanner = TRUE;
    pEnv->DisableCameraMove = FALSE;
    pEnv->DisableDamageText = TRUE;
    pEnv->TouchMode = FALSE;
    pEnv->RedirectCombine = TRUE;
    pEnv->ResinItem000106 = FALSE;
    pEnv->ResinItem000201 = FALSE;
    pEnv->ResinItem107009 = FALSE;
    pEnv->ResinItem107012 = FALSE;
    pEnv->ResinItem220007 = FALSE;

    // 扫描所有需要的函数偏移量
    std::cout << "=== 开始扫描函数偏移量 ===" << std::endl;
    
    pEnv->Offsets.GameManagerAwake = 0;
    pEnv->Offsets.MainEntryPoint = 0;
    pEnv->Offsets.MainEntryPartner1 = 0;
    pEnv->Offsets.MainEntryPartner2 = 0;
    pEnv->Offsets.SetUid = 0;
    pEnv->Offsets.SetFov = ScanOffset(hProcess, moduleName, SetFovPattern, "SetFov");
    pEnv->Offsets.SetFog = ScanOffset(hProcess, moduleName, DisplayFogPattern, "SetFog");
    pEnv->Offsets.GetFps = ScanOffset(hProcess, moduleName, GetFrameCountPattern, "GetFps");
    pEnv->Offsets.SetFps = ScanOffset(hProcess, moduleName, SetFrameCountPattern, "SetFps");
    pEnv->Offsets.OpenTeam = ScanOffset(hProcess, moduleName, OpenTeamPattern, "OpenTeam");
    pEnv->Offsets.OpenTeamAdvanced = ScanOffset(hProcess, moduleName, OpenTeamPageAccordinglyPattern, "OpenTeamAdvanced");
    pEnv->Offsets.CheckEnter = ScanOffset(hProcess, moduleName, CheckCanEnterPattern, "CheckEnter");
    pEnv->Offsets.QuestBanner = ScanOffset(hProcess, moduleName, SetupQuestBannerPattern, "QuestBanner");
    pEnv->Offsets.FindObject = ScanOffset(hProcess, moduleName, FindGameObjectPattern, "FindObject");
    pEnv->Offsets.ObjectActive = ScanOffset(hProcess, moduleName, SetActivePattern, "ObjectActive");
    pEnv->Offsets.CameraMove = ScanOffset(hProcess, moduleName, EventCameraMovePattern, "CameraMove");
    pEnv->Offsets.DamageText = ScanOffset(hProcess, moduleName, ShowOneDamageTextExPattern, "DamageText");
    pEnv->Offsets.TouchInput = ScanOffset(hProcess, moduleName, SwitchInputDeviceToTouchScreenPattern, "TouchInput");
    pEnv->Offsets.CombineEntry = ScanOffset(hProcess, moduleName, CraftEntryPattern, "CombineEntry");
    pEnv->Offsets.CombineEntryPartner = ScanOffset(hProcess, moduleName, CraftEntryPartnerPattern, "CombineEntryPartner");
    pEnv->Offsets.SetupResin = 0;
    pEnv->Offsets.ResinList = 0;
    pEnv->Offsets.ResinCount = 0;
    pEnv->Offsets.ResinItem = 0;
    pEnv->Offsets.ResinRemove = 0;
    pEnv->Offsets.FindString = ScanOffset(hProcess, moduleName, FindStringPattern, "FindString");
    pEnv->Offsets.PlayerPerspective = ScanOffset(hProcess, moduleName, PlayerPerspectivePattern, "PlayerPerspective");
    
    std::cout << "=== 扫描完成 ===" << std::endl;
}

int main()
{
    init_apartment();

    Inject();
    
    std::wcout << L"\nPress any key to exit..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    
    return 0;
}
