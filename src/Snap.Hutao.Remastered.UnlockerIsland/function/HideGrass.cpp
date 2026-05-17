#include "HideGrass.h"
#include "../framework.h"
#include "../dllmain.h"
#include "../Cache.h"
#include "../Logger.h"
#include "../Constants.h"
#include "HooksShared.h"

#include <string>

typedef void(*SetActiveFn)(void*, bool);
typedef Il2CppString* (*GetNameFn)(void*);

void HideGrass::Initialize()
{
    if (g_pEnv->Offsets.ObjectActive)
    {
        LPVOID setActiveAddr = GetFunctionAddress(g_pEnv->Offsets.ObjectActive);
        if (setActiveAddr)
        {
            setActive = setActiveAddr;
            MH_CreateHook(setActiveAddr, &HideGrass::HookSetActive, &originalSetActive);
        }
    }

    if (g_pEnv->Offsets.GetName)
    {
        getName = GetFunctionAddress(g_pEnv->Offsets.GetName);
    }
}

void* HideGrass::GetHookFunction()
{
    return (void*)&HideGrass::HookSetActive;
}

bool HideGrass::IsEnabled()
{
    return g_pEnv->HideGrass != FALSE;
}

void HideGrass::HookSetActive(void* pThis, bool active)
{
    if (g_pEnv->HideGrass && !CheckResistInBeyd() && active && getName)
    {
        GetNameFn getNameFunc = (GetNameFn)getName;
        Il2CppString* name = getNameFunc(pThis);
        if (name)
        {
            if (wcsstr(name->chars, L"_Grass_"))
            {
                for (std::wstring prefix : GrassPrefix)
                {
                    if (wcsstr(name->chars, prefix.c_str()))
                    {
                        Log(name);
                        return;
                    }
                }
            }
        }
    }

    SetActiveFn original = (SetActiveFn)originalSetActive;
    original(pThis, active);
}
