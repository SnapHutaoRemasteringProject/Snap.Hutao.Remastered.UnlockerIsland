#include "DisablePlayerPerspective.h"
#include "../framework.h"
#include "../dllmain.h"
#include "../Cache.h"
#include "../Logger.h"
#include "HooksShared.h"

typedef void (*PlayerPerspectiveFn)(void*, bool);
typedef void (*PlayerDiveMosaicFn)(void*, float);

const char playerDiveMosaicPatchBytes[] = { 0xB8, 0x00, 0x00, 0x00, 0x00 };

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

    if (g_pEnv->Offsets.PlayerDiveMosaic)
    {
        LPVOID playerPerspectiveAddr = GetFunctionAddress(g_pEnv->Offsets.PlayerDiveMosaic);
        if (playerPerspectiveAddr)
        {
            if (!IsCallOpcode((BYTE*)playerPerspectiveAddr))
            {
                MH_CreateHook(playerPerspectiveAddr, &DisablePlayerPerspective::HookPlayerDiveMosaic, &originalPlayerDiveMosaic);
            }
            else 
            {
                this->patch = new Patch(playerPerspectiveAddr, playerDiveMosaicPatchBytes, 5);
				Log("DisablePlayerPerspective: Patched PlayerDiveMosaic call to prevent player perspective change.");
            }
        }
    }
}

void DisablePlayerPerspective::OnUpdate()
{
    if (this->patch != nullptr)
    {
        this->patch->SetIsPatched(g_pEnv->DisablePlayerPerspective);
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

void DisablePlayerPerspective::HookPlayerDiveMosaic(void* a1, float a2)
{
    if (g_pEnv->DisablePlayerPerspective)
    {
        return;
    }

    if (originalPlayerDiveMosaic)
    {
        PlayerDiveMosaicFn original = (PlayerDiveMosaicFn)originalPlayerDiveMosaic;
        original(a1, a2);
    }
}
