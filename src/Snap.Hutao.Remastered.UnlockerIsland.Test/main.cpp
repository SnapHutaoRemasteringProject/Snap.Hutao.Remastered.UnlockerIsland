#include "pch.h"
#include <iostream>
#include <iomanip>
#include <filesystem>
#include <Windows.h>
#include <TlHelp32.h>

#include "../Snap.Hutao.Remastered.UnlockerIsland/HookEnvironment.h"


const wchar_t* SHARED_MEM_NAME = L"4F3E8543-40F7-4808-82DC-21E48A6037A7";

bool CreateSharedMemoryForHookEnvironment(HookEnvironment*& pEnv, HANDLE& hMapFile);
static bool InjectDLL(HANDLE hProcess, const std::wstring& dllPath);

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
    std::filesystem::path dllPath = std::filesystem::path(exePath).parent_path() / L"Snap.Hutao.Remastered.UnlockerIsland.dll";

    if (std::filesystem::exists(dllPath))
    {
        return dllPath.wstring();
    }

    std::wcerr << L"DLL not found in current directory: " << dllPath.wstring() << std::endl;
    std::wcerr << L"Please place Snap.Hutao.Remastered.UnlockerIsland.dll in the current directory." << std::endl;
    return L"";
}

std::wstring GetDumpDLLPath()
{
    wchar_t exePath[MAX_PATH];
    GetModuleFileNameW(nullptr, exePath, MAX_PATH);
    std::filesystem::path dllPath = std::filesystem::path(exePath).parent_path() / L"Dumper.dll";

    if (std::filesystem::exists(dllPath))
    {
        return dllPath.wstring();
    }

    std::wcerr << L"DLL not found in current directory: " << dllPath.wstring() << std::endl;
    std::wcerr << L"Please place Dumper.dll in the current directory." << std::endl;
    return L"";
}

bool StartGameAndSuspend(const std::wstring& gamePath, HANDLE& hProcess, HANDLE& hMainThread, DWORD& pid)
{
    // 启动游戏
    STARTUPINFOW si = { sizeof(si) };
    PROCESS_INFORMATION pi = { 0 };
    
    std::wstring commandLine = L"\"" + gamePath + L"\"";
    
    if (!CreateProcessW(
        gamePath.c_str(),
        &commandLine[0],
        nullptr,
        nullptr,
        FALSE,
        CREATE_SUSPENDED, // 创建时挂起
        0,
        nullptr,
        &si,
        &pi))
    {
        std::wcerr << L"Failed to start game: " << GetLastError() << std::endl;
        return false;
    }
    
    hProcess = pi.hProcess;
    hMainThread = pi.hThread; // 保存主线程句柄
    pid = pi.dwProcessId;
    
    std::wcout << L"Game started with PID: " << pid << L" (suspended)" << std::endl;
    return true;
}

void Inject()
{
	std::wstring moduleName = L"YuanShen.exe";
    std::wstring dllPath = GetDLLPath();
    if (dllPath.empty())
    {
        return;
    }

    // 总是启动新游戏实例
    std::wstring gamePath;
    
    // 尝试查找游戏路径
    std::vector<std::wstring> possiblePaths = {
        L"C:\\Program Files\\Genshin Impact\\Genshin Impact Game\\YuanShen.exe",
        L"C:\\Program Files\\Genshin Impact\\Genshin Impact Game\\GenshinImpact.exe",
        L"D:\\Genshin Impact Game\\YuanShen.exe",
        L"D:\\Genshin Impact Game\\GenshinImpact.exe",
        L"E:\\Genshin Impact Game\\YuanShen.exe"
        L"E:\\Genshin Impact Game\\GenshinImpact.exe"
    };
    
    for (const auto& path : possiblePaths)
    {
        if (std::filesystem::exists(path))
        {
            gamePath = path;
            break;
        }
    }
    
    if (gamePath.empty())
    {
        std::wcerr << L"Game executable not found. Please specify the game path." << std::endl;
        return;
    }
    
    HANDLE hProcess = nullptr;
    HANDLE hMainThread = nullptr;
    DWORD pid = 0;
    if (!StartGameAndSuspend(gamePath, hProcess, hMainThread, pid))
    {
        return;
    }
    
    HookEnvironment* pEnv = nullptr;
    HANDLE hMapFile = NULL;

    if (CreateSharedMemoryForHookEnvironment(pEnv, hMapFile))
    {
        if (pEnv)
        {
            ZeroMemory(pEnv, sizeof(HookEnvironment));
            pEnv->Size = sizeof(HookEnvironment);
            pEnv->State = IslandState::None;
            pEnv->LastError = 0;
            pEnv->Uid = 0;
            pEnv->ProvideOffsets = FALSE;
            pEnv->IsOversea = TRUE;

			pEnv->DebugMode = TRUE;
            pEnv->EnableSetFov = TRUE;
            pEnv->FieldOfView = 90.0f;
            pEnv->DisablePlayerPerspective = TRUE;
            pEnv->DisableFog = TRUE;
            pEnv->EnableSetFps = TRUE;
            pEnv->TargetFps = 2000;
            pEnv->RemoveTeamProgress = TRUE;
            pEnv->HideQuestBanner = TRUE;
            pEnv->DisableCameraMove = TRUE;
            pEnv->DisableDamageText = FALSE;
            pEnv->TouchMode = FALSE;
            pEnv->RedirectCombine = TRUE;
			pEnv->DisplayPaimon = TRUE;
            pEnv->HidePlayerInfo = TRUE;
			pEnv->HideGrass = TRUE;
			pEnv->GamepadHotSwitchEnabled = TRUE;
            
            ZeroMemory(&pEnv->Offsets, sizeof(HookFunctionOffsets));

            pEnv->Offsets.SetUid = 0xAC68570;  //MonoUIWaterMask.SetUID
			pEnv->Offsets.SetFov = 0x1560ec0;  //need pattern scan
            pEnv->Offsets.SetFog = 0x15b73330;  //
            pEnv->Offsets.GetFps = 0x106a3b0;  //
            pEnv->Offsets.SetFps = 0x106a3c0;  //双层跳板, 高 实在是高
            pEnv->Offsets.OpenTeam = 0xe47e1b0;  //JGDDADKMLDL.DDFODLGCHGM  need pattern scan
            pEnv->Offsets.OpenTeamAdvanced = 0xe4851e0;  //JGDDADKMLDL.LBLECKJEGOI  need pattern scan
            pEnv->Offsets.CheckEnter = 0xfeafc10;  //need pattern scan
            pEnv->Offsets.QuestBanner = 0xa98f410;
            pEnv->Offsets.FindObject = 0x15B625B0;  //GameObject.Find
            pEnv->Offsets.ObjectActive = 0x1063450;  //GameObject.set_active
			pEnv->Offsets.IsObjectActive = 0x15B622E0;  //GameObject.get_active
            pEnv->Offsets.CameraMove = 0xfa87490;  //BOFBPKLPKOK.DNIJOJKIOIF need pattern scan
            pEnv->Offsets.DamageText = 0x1084e9e0;  //MonoParticleDamageTextContainer.ShowOneDamageText
            pEnv->Offsets.TouchInput = 0x105c2c10;  //CNGPNBOAIKK.FGKNOKNIIPL need pattern scan
			pEnv->Offsets.KeyboardMouseInput = 0xA2AF880;  // need pattern scan
			pEnv->Offsets.JoypadInput = 0x105AE050;  // need pattern scan
            pEnv->Offsets.CombineEntry = 0x69ea500;  //NBJLAEKBCIM.DNJNIKDKECD need pattern scan
            pEnv->Offsets.CombineEntryPartner = 0x9199950;  //FGPIAOKFJCE.NJCOCBAONEC need pattern scan
            pEnv->Offsets.SetupResinList = 0;
            pEnv->Offsets.ResinList = 0;
            pEnv->Offsets.ResinCount = 0;
            pEnv->Offsets.ResinItem = 0;
            pEnv->Offsets.ResinRemove = 0;
            pEnv->Offsets.FindString = 0x406330;  //internal method need pattern scan
            pEnv->Offsets.PlayerPerspective = 0xd80fb50;
			pEnv->Offsets.GameUpdate = 0x15394C70;  //MainThreadDispatcher.Update
            pEnv->Offsets.GetPlayerID = 0x1082F640;  //MonoInLevelPlayerProfilePageV3.get_playerID
            pEnv->Offsets.SetText = 0x15C451A0; //Text.set_text
            pEnv->Offsets.MonoInLevelPlayerProfilePageV3Ctor = 0x1082F8E0;  //MonoInLevelPlayerProfilePageV3..ctor
            pEnv->Offsets.GetPlayerName = 0x1082F730;  //MonoInLevelPlayerProfilePageV3.get_playerName
			pEnv->Offsets.ActorManagerCtor = 0xD2D4EF0;  //ActorManager..ctor
			pEnv->Offsets.GetGlobalActor = 0xD2CC9E0;  //ActorManager.GetGlobalActor
			//pEnv->Offsets.ResumePaimonInProfilePageAll = 0xD2FA560;  //GlobalActor.ResumePaimonInProfilePageAll
			pEnv->Offsets.AvatarPaimonAppear = 0x107BAC60;  //GlobalActor.AvatarPaimonAppear
			pEnv->Offsets.GetComponent = 0x15B61F60;  //GameObject.GetComponent(String type)
			pEnv->Offsets.GetText = 0x15C45190;  //Text.get_text
			pEnv->Offsets.GetName = 0x15B79680;  //Object.get_name
			pEnv->Offsets.CheckCanOpenMap = 0x69E9DD3;  // need pattern scan
        }

        if (InjectDLL(hProcess, dllPath))
        {
            //InjectDLL(hProcess, GetDumpDLLPath());
            std::wcout << L"DLL injected successfully. Waiting for module initialization..." << std::endl;
            
            // 等待DLL初始化完成
            Sleep(2000);
            
            if (hMainThread)
            {
                ResumeThread(hMainThread);
                CloseHandle(hMainThread);
                std::wcout << L"Game process resumed." << std::endl;
            }
            else
            {
                std::wcerr << L"Failed to resume game: main thread handle is null." << std::endl;
            }
        }
        else
        {
            std::wcerr << L"Failed to inject DLL." << std::endl;
        }
    }

    if (hProcess)
    {
        CloseHandle(hProcess);
    }
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

bool InjectDLL(HANDLE hProcess, const std::wstring& dllPath)
{
    // First check if DLL is already injected
    std::wstring dllName = dllPath.substr(dllPath.find_last_of(L"\\/") + 1);

    // Get LoadLibraryW function address
    LPVOID loadLibraryAddr = reinterpret_cast<LPVOID>(GetProcAddress(GetModuleHandleW(L"kernel32.dll"), "LoadLibraryW"));
    if (loadLibraryAddr == nullptr)
    {
        std::wcerr << L"Failed to get LoadLibraryW address: " << GetLastError() << std::endl;
        return false;
    }

    // Allocate memory in target process for DLL path
    size_t pathSize = (dllPath.length() + 1) * sizeof(wchar_t);
    LPVOID remoteMemory = VirtualAllocEx(hProcess, nullptr, pathSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (remoteMemory == nullptr)
    {
        std::wcerr << L"Failed to allocate memory in target process: " << GetLastError() << std::endl;
        return false;
    }

    // Write DLL path to target process
    if (!WriteProcessMemory(hProcess, remoteMemory, dllPath.c_str(), pathSize, nullptr))
    {
        std::wcerr << L"Failed to write DLL path to target process: " << GetLastError() << std::endl;
        VirtualFreeEx(hProcess, remoteMemory, 0, MEM_RELEASE);
        return false;
    }

    // Create remote thread to call LoadLibraryW
    HANDLE hThread = CreateRemoteThread(hProcess, nullptr, 0,
        reinterpret_cast<LPTHREAD_START_ROUTINE>(loadLibraryAddr),
        remoteMemory, 0, nullptr);

    if (hThread == nullptr)
    {
        std::wcerr << L"Failed to create remote thread: " << GetLastError() << std::endl;
        VirtualFreeEx(hProcess, remoteMemory, 0, MEM_RELEASE);
        return false;
    }
    WaitForSingleObject(hThread, INFINITE);
    DWORD exitCode = 0;
    GetExitCodeThread(hThread, &exitCode);
    CloseHandle(hThread);
    VirtualFreeEx(hProcess, remoteMemory, 0, MEM_RELEASE);

    if (exitCode == 0)
    {
        std::wcerr << L"LoadLibraryW failed in target process" << std::endl;
        return false;
    }

    std::wcout << L"DLL injected successfully: " << dllName << std::endl;
    return true;
}

int main()
{
    Inject();
    
    return 0;
}
