#include "RemoveTeamProgress.h"
#include "../framework.h"
#include "../dllmain.h"
#include "../Cache.h"
#include "HooksShared.h"

typedef bool(*CheckCanEnterFn)();
typedef void(*OpenTeamFn)();
typedef void(*OpenTeamPageAccordinglyFn)(bool);

void RemoveTeamProgress::Initialize()
{
    if (g_pEnv->Offsets.CheckEnter)
    {
        checkCanEnter = GetFunctionAddress(g_pEnv->Offsets.CheckEnter);
    }

    if (g_pEnv->Offsets.OpenTeamAdvanced)
    {
        openTeamPageAccordingly = GetFunctionAddress(g_pEnv->Offsets.OpenTeamAdvanced);
    }

    if (g_pEnv->Offsets.OpenTeam)
    {
        LPVOID openTeamAddr = GetFunctionAddress(g_pEnv->Offsets.OpenTeam);
        if (openTeamAddr)
        {
            MH_CreateHook(openTeamAddr, &RemoveTeamProgress::HookOpenTeam, &originalOpenTeam);
        }
    }
}

void* RemoveTeamProgress::GetHookFunction()
{
    return (void*)&RemoveTeamProgress::HookOpenTeam;
}

bool RemoveTeamProgress::IsEnabled()
{
    return g_pEnv->RemoveTeamProgress != FALSE;
}

void RemoveTeamProgress::HookOpenTeam()
{
    if (g_pEnv->RemoveTeamProgress && checkCanEnter && !CheckResistInBeyd())
    {
        CheckCanEnterFn checkCanEnterFunc = (CheckCanEnterFn)checkCanEnter;
        if (checkCanEnterFunc())
        {
            if (openTeamPageAccordingly)
            {
                OpenTeamPageAccordinglyFn openTeamPageFunc = (OpenTeamPageAccordinglyFn)openTeamPageAccordingly;
                openTeamPageFunc(false);
                return;
            }
        }
    }

    if (originalOpenTeam)
    {
        OpenTeamFn original = (OpenTeamFn)originalOpenTeam;
        original();
    }
}
