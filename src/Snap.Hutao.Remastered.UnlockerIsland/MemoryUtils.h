#pragma once

#include <Windows.h>

typedef void(__fastcall* VoidFunc)();

VoidFunc GetFunctionAddress(DWORD offset);
INT64 GetVirtualAddress(INT64 offset);
void InitializeModuleHandle();

extern HMODULE g_hModule;
