#include "DisablePlayerPerspective.h"
#include "../framework.h"
#include "../dllmain.h"
#include "../Cache.h"
#include "../Logger.h"
#include "HooksShared.h"

typedef void (*PlayerPerspectiveFn)(void*, bool);

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

void DisablePlayerPerspective::OnUpdate()
{
}

void* DisablePlayerPerspective::GetHookFunction()
{
    return (void*)&DisablePlayerPerspective::HookPlayerPerspective;
}

bool DisablePlayerPerspective::IsEnabled()
{
    return g_pEnv->DisablePlayerPerspective != FALSE;
}

void DisablePlayerPerspective::HookPlayerPerspective(void* rcx, bool display)
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
