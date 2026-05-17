#include "DisableFog.h"
#include "../framework.h"
#include "../dllmain.h"
#include "../Cache.h"
#include "HooksShared.h"

typedef void(*SetEnableFogRenderingFn)(bool);

void DisableFog::Initialize()
{
    if (g_pEnv->Offsets.SetFog)
    {
        fnDisplayFog = GetFunctionAddress(g_pEnv->Offsets.SetFog);
    }
}

void DisableFog::OnUpdate()
{
    if (fnDisplayFog)
    {
        SetEnableFogRenderingFn setFog = (SetEnableFogRenderingFn)fnDisplayFog;
        setFog(!g_pEnv->DisableFog);
    }
}

bool DisableFog::IsEnabled()
{
    return g_pEnv->DisableFog != FALSE;
}
