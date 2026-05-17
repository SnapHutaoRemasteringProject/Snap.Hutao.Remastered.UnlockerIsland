#include "WeakMapCheck.h"
#include "../framework.h"
#include "../dllmain.h"
#include "HooksShared.h"

typedef bool(*CheckCanOpenMapFn)(void*);

void WeakMapCheck::Initialize()
{
    if (g_pEnv->Offsets.CheckCanOpenMap)
    {
        LPVOID checkCanOpenMapAddr = GetFunctionAddress(g_pEnv->Offsets.CheckCanOpenMap);
        if (checkCanOpenMapAddr)
        {
            MH_CreateHook(checkCanOpenMapAddr, &WeakMapCheck::HookCheckCanOpenMap, &originalCheckCanOpenMap);
        }
    }
}

void* WeakMapCheck::GetHookFunction()
{
    return (void*)&WeakMapCheck::HookCheckCanOpenMap;
}

bool WeakMapCheck::IsEnabled()
{
    return g_pEnv->WeakMapCheck != FALSE;
}

bool WeakMapCheck::HookCheckCanOpenMap(void* pThis)
{
    if (g_pEnv->WeakMapCheck)
    {
        return false;
    }

    CheckCanOpenMapFn original = (CheckCanOpenMapFn)originalCheckCanOpenMap;
    return original(pThis);
}
