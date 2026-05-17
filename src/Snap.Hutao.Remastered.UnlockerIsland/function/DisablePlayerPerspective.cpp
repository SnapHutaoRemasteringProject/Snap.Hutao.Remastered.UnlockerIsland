#include "DisablePlayerPerspective.h"
#include "../framework.h"
#include "../dllmain.h"
#include "../Cache.h"
#include "HooksShared.h"

typedef void* (*PlayerPerspectiveFn)(void*, float, void*);

void DisablePlayerPerspective::Initialize()
{
    if (g_pEnv->Offsets.PlayerPerspective)
    {
        LPVOID playerPerspectiveAddr = GetFunctionAddress(g_pEnv->Offsets.PlayerPerspective);
        if (playerPerspectiveAddr)
        {
            MH_CreateHook(playerPerspectiveAddr, &DisablePlayerPerspective::HookPlayerPerspective, &originalPlayerPerspective);
        }
    }
}

void* DisablePlayerPerspective::GetHookFunction()
{
    return (void*)&DisablePlayerPerspective::HookPlayerPerspective;
}

bool DisablePlayerPerspective::IsEnabled()
{
    return g_pEnv->DisablePlayerPerspective != FALSE;
}

void* DisablePlayerPerspective::HookPlayerPerspective(void* rcx, float display, void* r8)
{
    if (g_pEnv->DisablePlayerPerspective && !CheckResistInBeyd())
    {
        display = 1.0f;
    }

    if (originalPlayerPerspective)
    {
        PlayerPerspectiveFn original = (PlayerPerspectiveFn)originalPlayerPerspective;
        return original(rcx, display, r8);
    }
    return nullptr;
}
