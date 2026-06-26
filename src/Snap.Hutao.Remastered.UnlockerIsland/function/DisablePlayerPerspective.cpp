#include "DisablePlayerPerspective.h"
#include "../framework.h"
#include "../dllmain.h"
#include "../Cache.h"
#include "../Logger.h"
#include "HooksShared.h"

typedef void (*PlayerPerspectiveFn)(void*, bool);
typedef void (*PlayerPerspectiveFn2)(void*, float);

const char playerPerspectivePatchBytes[] = { 0xB8, 0x00, 0x00, 0x00, 0x00 };

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
            if (!IsCallOpcode((BYTE*)playerPerspectiveAddr))
            {
                MH_CreateHook(playerPerspectiveAddr, &DisablePlayerPerspective::HookPlayerPerspective2, &originalPlayerPerspective2);
            }
            else 
            {
                this->patch = new Patch(playerPerspectiveAddr, playerPerspectivePatchBytes, 5);
				Log("DisablePlayerPerspective: Patched PlayerPerspective2 call to prevent player perspective change.");
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

void DisablePlayerPerspective::HookPlayerPerspective2(void* a1, float a2)
{
    if (g_pEnv->DisablePlayerPerspective)
    {
        return;
    }

    if (originalPlayerPerspective2)
    {
        PlayerPerspectiveFn2 original = (PlayerPerspectiveFn2)originalPlayerPerspective2;
        original(a1, a2);
    }
}
