#pragma once

#include "dllmain.h"
#include "MemoryUtils.h"

void SetupHooks();
void SetupOpenTeamHook();

void NewOpenTeam();

extern VoidFunc originalOpenTeamFunction;
