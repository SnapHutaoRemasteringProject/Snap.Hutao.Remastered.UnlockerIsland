#include "dllmain.h"
#include "include/MinHook.h"
#include "Hooks.h"
#include "AntiAntiDebug.h"
#include <Windows.h>

// 全局变量
HookEnvironment* g_pEnv = nullptr;

// 工作线程函数声明
DWORD WINAPI WorkerThread(LPVOID lpParam);

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        // 禁用线程库调用以优化
        DisableThreadLibraryCalls(hModule);
        
        // 创建工作线程来处理hook初始化
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
    
    // 初始化MinHook
    if (MH_Initialize() != MH_OK) {
        return 0;
    }
    
    // 初始化共享内存环境
    InitializeHookEnvironment();
    
    // 设置hook
    SetupHooks();
    //SetupAntiAntiDebugHooks(); // 添加反反调试hook
    
    // 启用所有hook
    if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK) {
        MH_Uninitialize();
        return 0;
    }
    
    // 主循环（类似于hutao-minhook-ng的热键监控）
    while (true)
    {
        // 这里可以添加热键监控逻辑
        // 例如：检查配置重新加载热键等
        
        Sleep(100);
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
