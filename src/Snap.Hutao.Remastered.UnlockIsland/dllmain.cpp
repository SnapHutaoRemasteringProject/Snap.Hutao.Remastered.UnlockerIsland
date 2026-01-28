#include "dllmain.h"
#include "Hooks.h"
#include "AntiAntiDebug.h"
#include <cstdio>

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
            UnmapViewOfFile(g_pEnv);
        }
        break;
    }
    return TRUE;
}

// 工作线程函数实现
DWORD WINAPI WorkerThread(LPVOID lpParam)
{
    HMODULE hModule = (HMODULE)lpParam;
    
    if (MH_Initialize() != MH_OK) {
        return 0;
    }
    
    InitializeHookEnvironment();

    if (g_pEnv->DebugMode) {
        CreateConsole();
        //SetupAntiAntiDebugHooks(); // 添加反反调试hook
	}
    
    SetupHooks();
    
    if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK) {
        MH_Uninitialize();
        return 0;
    }
    
    return 0;
}

void InitializeHookEnvironment()
{
    HANDLE hMapFile = OpenFileMappingW(FILE_MAP_READ | FILE_MAP_WRITE, FALSE, L"4F3E8543-40F7-4808-82DC-21E48A6037A7");
    if (hMapFile != NULL) {
        g_pEnv = (HookEnvironment*)MapViewOfFile(hMapFile, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, 0);
    }
}
