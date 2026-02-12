#include "dllmain.h"
#include "Hooks.h"
#include "AntiAntiDebug.h"
#include "MacroDetector.h"
#include <cstdio>
#include <iostream>

HookEnvironment* g_pEnv = nullptr;

void CreateConsole() {
    if (AllocConsole()) {
        FILE* f;
        freopen_s(&f, "CONOUT$", "w", stdout);
        freopen_s(&f, "CONOUT$", "w", stderr);
        freopen_s(&f, "CONIN$", "r", stdin);
    }
}

DWORD WINAPI WorkerThread(LPVOID lpParam);

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        
        CreateThread(NULL, 0, WorkerThread, hModule, 0, NULL);
        break;
        
    case DLL_THREAD_ATTACH:
        break;
        
    case DLL_THREAD_DETACH:
        break;
        
    case DLL_PROCESS_DETACH:
        MH_DisableHook(MH_ALL_HOOKS);
        MH_Uninitialize();
        
        if (g_pEnv) {
            g_pEnv->State = IslandState::Stopped;
            UnmapViewOfFile(g_pEnv);
        }
        break;
    }
    return TRUE;
}

DWORD WINAPI WorkerThread(LPVOID lpParam)
{
    HMODULE hModule = (HMODULE)lpParam;
    
    if (MH_Initialize() != MH_OK) {
        return 0;
    }
    
    InitializeHookEnvironment();

    if (g_pEnv->DebugMode) {
        CreateConsole();
        //SetupAntiAntiDebugHooks();
        std::cout << "Snap.Hutao.Remastered.UnlockerIsland loaded in debug mode." << std::endl;
        std::cout << "ProvideOffsets = " << g_pEnv->ProvideOffsets << std::endl;
	}
    
    SetupHooks();

    if (g_pEnv->DebugMode) {
        std::cout << "Offset SetUid = 0x" << std::hex << g_pEnv->Offsets.SetUid << std::endl;
        std::cout << "Offset SetFov = 0x" << std::hex << g_pEnv->Offsets.SetFov << std::endl;
        std::cout << "Offset SetFog = 0x" << std::hex << g_pEnv->Offsets.SetFog << std::endl;
        std::cout << "Offset GetFps = 0x" << std::hex << g_pEnv->Offsets.GetFps << std::endl;
        std::cout << "Offset SetFps = 0x" << std::hex << g_pEnv->Offsets.SetFps << std::endl;
        std::cout << "Offset OpenTeam = 0x" << std::hex << g_pEnv->Offsets.OpenTeam << std::endl;
        std::cout << "Offset OpenTeamAdvanced = 0x" << std::hex << g_pEnv->Offsets.OpenTeamAdvanced << std::endl;
        std::cout << "Offset CheckEnter = 0x" << std::hex << g_pEnv->Offsets.CheckEnter << std::endl;
        std::cout << "Offset QuestBanner = 0x" << std::hex << g_pEnv->Offsets.QuestBanner << std::endl;
        std::cout << "Offset FindObject = 0x" << std::hex << g_pEnv->Offsets.FindObject << std::endl;
        std::cout << "Offset ObjectActive = 0x" << std::hex << g_pEnv->Offsets.ObjectActive << std::endl;
        std::cout << "Offset CameraMove = 0x" << std::hex << g_pEnv->Offsets.CameraMove << std::endl;
        std::cout << "Offset DamageText = 0x" << std::hex << g_pEnv->Offsets.DamageText << std::endl;
        std::cout << "Offset TouchInput = 0x" << std::hex << g_pEnv->Offsets.TouchInput << std::endl;
        std::cout << "Offset CombineEntry = 0x" << std::hex << g_pEnv->Offsets.CombineEntry << std::endl;
        std::cout << "Offset CombineEntryPartner = 0x" << std::hex << g_pEnv->Offsets.CombineEntryPartner << std::endl;
        std::cout << "Offset SetupResinList = 0x" << std::hex << g_pEnv->Offsets.SetupResinList << std::endl;
        std::cout << "Offset ResinList = 0x" << std::hex << g_pEnv->Offsets.ResinList << std::endl;
        std::cout << "Offset ResinCount = 0x" << std::hex << g_pEnv->Offsets.ResinCount << std::endl;
        std::cout << "Offset ResinItem = 0x" << std::hex << g_pEnv->Offsets.ResinItem << std::endl;
        std::cout << "Offset ResinRemove = 0x" << std::hex << g_pEnv->Offsets.ResinRemove << std::endl;
        std::cout << "Offset FindString = 0x" << std::hex << g_pEnv->Offsets.FindString << std::endl;
        std::cout << "Offset PlayerPerspective = 0x" << std::hex << g_pEnv->Offsets.PlayerPerspective << std::endl;
        std::cout << "Offset IsObjectActive = 0x" << std::hex << g_pEnv->Offsets.IsObjectActive << std::endl;
        std::cout << "Offset GameUpdate = 0x" << std::hex << g_pEnv->Offsets.GameUpdate << std::endl;
        std::cout << "Offset PtrToStringAnsi = 0x" << std::hex << g_pEnv->Offsets.PtrToStringAnsi << std::endl;
        std::cout << "Offset GetPlayerID = 0x" << std::hex << g_pEnv->Offsets.GetPlayerID << std::endl;
        std::cout << "Offset SetText = 0x" << std::hex << g_pEnv->Offsets.SetText << std::endl;
        std::cout << "Offset MonoInLevelPlayerProfilePageV3Ctor = 0x" << std::hex << g_pEnv->Offsets.MonoInLevelPlayerProfilePageV3Ctor << std::endl;
        std::cout << "Offset GetPlayerName = 0x" << std::hex << g_pEnv->Offsets.GetPlayerName << std::endl;
        std::cout << "Offset ActorManagerCtor = 0x" << std::hex << g_pEnv->Offsets.ActorManagerCtor << std::endl;
        std::cout << "Offset GetGlobalActor = 0x" << std::hex << g_pEnv->Offsets.GetGlobalActor << std::endl;
        std::cout << "Offset AvatarPaimonAppear = 0x" << std::hex << g_pEnv->Offsets.AvatarPaimonAppear << std::endl;
        std::cout << "Offset GetName = 0x" << std::hex << g_pEnv->Offsets.GetName << std::endl;
    }
    
    if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK) {
        MH_Uninitialize();
        return 0;
    }

    g_pEnv->State = IslandState::Started;
    g_pEnv->Size = sizeof(HookEnvironment);
    
    return 0;
}

void InitializeHookEnvironment()
{
    HANDLE hMapFile = OpenFileMappingW(FILE_MAP_READ | FILE_MAP_WRITE, FALSE, L"4F3E8543-40F7-4808-82DC-21E48A6037A7");
    if (hMapFile != NULL) {
        g_pEnv = (HookEnvironment*)MapViewOfFile(hMapFile, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, 0);
    }
}
