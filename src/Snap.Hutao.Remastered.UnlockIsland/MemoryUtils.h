#pragma once

#include <Windows.h>

typedef void(__stdcall* VoidFunc)();

VoidFunc GetFunctionAddress(DWORD offset);
void InitializeModuleHandle();

extern HMODULE g_hModule;
