#pragma once

#include <Windows.h>

typedef void(__fastcall* VoidFunc)();

VoidFunc GetFunctionAddress(DWORD offset);
void InitializeModuleHandle();

extern HMODULE g_hModule;
