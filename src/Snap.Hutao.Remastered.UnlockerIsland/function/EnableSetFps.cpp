#include "EnableSetFps.h"
#include "../framework.h"
#include "../dllmain.h"
#include "../Cache.h"
#include "HooksShared.h"

typedef int(*GetFrameCountFn)();
typedef int(*SetFrameCountFn)(int);

void EnableSetFps::Initialize()
{
    if (g_pEnv->Offsets.GetFps)
    {
        LPVOID getFrameCountAddr = GetFunctionAddress(g_pEnv->Offsets.GetFps);
        if (getFrameCountAddr)
        {
            MH_CreateHook(getFrameCountAddr, &EnableSetFps::HookGetFrameCount, &originalGetFrameCount);
        }
    }

    if (g_pEnv->Offsets.SetFps)
    {
        setFrameCount = GetFunctionAddress(g_pEnv->Offsets.SetFps);
    }
}

void EnableSetFps::OnUpdate()
{
    if (setFrameCount && g_pEnv->EnableSetFps && !CheckResistInBeyd())
    {
        SetFrameCountFn setFrameCountFunc = (SetFrameCountFn)setFrameCount;
        setFrameCountFunc(g_pEnv->TargetFps);
    }
}

void* EnableSetFps::GetHookFunction()
{
    return (void*)&EnableSetFps::HookGetFrameCount;
}

bool EnableSetFps::IsEnabled()
{
    return g_pEnv->EnableSetFps != FALSE;
}

int EnableSetFps::HookGetFrameCount()
{
    if (originalGetFrameCount)
    {
        GetFrameCountFn original = (GetFrameCountFn)originalGetFrameCount;
        int ret = original();
        if (ret >= 60) return 60;
        else if (ret >= 45) return 45;
        else if (ret >= 30) return 30;
        else return ret;
    }
    return 60;
}
