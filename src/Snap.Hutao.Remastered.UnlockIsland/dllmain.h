#pragma once

#include "HookEnvironment.h"
#include <Windows.h>

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
);

void InitializeHookEnvironment();

extern HookEnvironment* g_pEnv;
