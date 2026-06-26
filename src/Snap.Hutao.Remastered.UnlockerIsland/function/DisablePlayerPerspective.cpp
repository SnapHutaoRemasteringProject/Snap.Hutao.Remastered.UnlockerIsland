#include "DisablePlayerPerspective.h"
#include "../framework.h"
#include "../dllmain.h"
#include "../Cache.h"
#include "HooksShared.h"

typedef void (*PlayerPerspectiveFn)(void*, float);
typedef void (*PlayerPerspectiveFn2)();

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

    if (g_pEnv->Offsets.PlayerPerspective2)
    {
        LPVOID playerPerspectiveAddr = GetFunctionAddress(g_pEnv->Offsets.PlayerPerspective2);
        if (playerPerspectiveAddr)
        {
            MH_CreateHook(playerPerspectiveAddr, &DisablePlayerPerspective::HookPlayerPerspective2, &originalPlayerPerspective2);
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

void DisablePlayerPerspective::HookPlayerPerspective(void* rcx, float display)
{
    if (g_pEnv->DisablePlayerPerspective && !CheckResistInBeyd())
    {
		return;
    }

    if (originalPlayerPerspective)
    {
        PlayerPerspectiveFn original = (PlayerPerspectiveFn)originalPlayerPerspective;
        original(rcx, display);
    }
}

void DisablePlayerPerspective::HookPlayerPerspective2()
{
    if (g_pEnv->DisablePlayerPerspective && !CheckResistInBeyd())
    {
        return;
    }

    if (originalPlayerPerspective2)
    {
        PlayerPerspectiveFn2 original = (PlayerPerspectiveFn2)originalPlayerPerspective2;
        original();
    }
}
