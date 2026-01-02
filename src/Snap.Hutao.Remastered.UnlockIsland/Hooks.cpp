#include "Hooks.h"
#include "HookEnvironment.h"
#include "HookFunctionOffsets.h"
#include "MemoryUtils.h"
#include "include/MinHook.h"


void SetupHooks()
{
	SetupOpenTeamHook();
}

void SetupOpenTeamHook()
{
	MH_CreateHook(GetFunctionAddress(g_pEnv->Offsets.OpenTeam), NewOpenTeam, (LPVOID*) &originalOpenTeamFunction);
}

void NewOpenTeam()
{
	if (g_pEnv->State && g_pEnv->RemoveTeamProgress) {
		VoidFunc openTeamAddr = GetFunctionAddress(g_pEnv->Offsets.OpenTeamPageAccordingly);
		openTeamAddr();
		return;
	}

	originalOpenTeamFunction();
}

VoidFunc originalOpenTeamFunction = nullptr;