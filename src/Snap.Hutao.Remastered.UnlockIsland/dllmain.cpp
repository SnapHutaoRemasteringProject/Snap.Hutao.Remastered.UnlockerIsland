#include "dllmain.h"
#include "include/MinHook.h"
#include "Hooks.h"
#include <Windows.h>

// 全局变量
HookEnvironment* g_pEnv = nullptr;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        if (MH_Initialize() != MH_OK) {
            return FALSE;
        }
        
        InitializeHookEnvironment();
        SetupHooks();
        
        if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK) {
            MH_Uninitialize();
            return FALSE;
        }
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

void InitializeHookEnvironment()
{
    HANDLE hMapFile = OpenFileMappingW(FILE_MAP_READ | FILE_MAP_WRITE, FALSE, L"4F3E8543-40F7-4808-82DC-21E48A6037A7");
    if (hMapFile != NULL) {
        g_pEnv = (HookEnvironment*)MapViewOfFile(hMapFile, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, 0);
    }
}

