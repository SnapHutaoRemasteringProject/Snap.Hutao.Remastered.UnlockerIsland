#include "DisablePlayerDiveMosaic.h"
#include "../framework.h"
#include "../dllmain.h"
#include "../Logger.h"
#include "HooksShared.h"

typedef void (*PlayerDiveMosaicFn)(void*, float);

const char playerDiveMosaicPatchBytes[] = { 0xB8, 0x00, 0x00, 0x00, 0x00 };

void DisablePlayerDiveMosaic::Initialize()
{
    if (g_pEnv->Offsets.PlayerDiveMosaic)
    {
        LPVOID playerDiveMosaicAddr = GetFunctionAddress(g_pEnv->Offsets.PlayerDiveMosaic);
        if (playerDiveMosaicAddr)
        {
            if (!IsCallOpcode((BYTE*)playerDiveMosaicAddr))
            {
                MH_CreateHook(playerDiveMosaicAddr, &DisablePlayerDiveMosaic::HookPlayerDiveMosaic, &originalPlayerDiveMosaic);
            }
            else
            {
                this->patch = new Patch(playerDiveMosaicAddr, playerDiveMosaicPatchBytes, 5);
                Log("DisablePlayerDiveMosaic: Patched PlayerDiveMosaic call.");
            }
        }
    }
}

void DisablePlayerDiveMosaic::OnUpdate()
{
    if (this->patch != nullptr)
    {
        this->patch->SetIsPatched(g_pEnv->DisablePlayerDiveMosaic);
    }
}

void* DisablePlayerDiveMosaic::GetHookFunction()
{
    return (void*)&DisablePlayerDiveMosaic::HookPlayerDiveMosaic;
}

bool DisablePlayerDiveMosaic::IsEnabled()
{
    return g_pEnv->DisablePlayerDiveMosaic != FALSE;
}

void DisablePlayerDiveMosaic::HookPlayerDiveMosaic(void* a1, float a2)
{
    if (g_pEnv->DisablePlayerDiveMosaic)
    {
        return;
    }

    if (originalPlayerDiveMosaic)
    {
        PlayerDiveMosaicFn original = (PlayerDiveMosaicFn)originalPlayerDiveMosaic;
        original(a1, a2);
    }
}
