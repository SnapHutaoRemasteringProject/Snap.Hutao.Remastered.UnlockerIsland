#pragma once

#include <Windows.h>

typedef void(__fastcall* VoidFunc)();

VoidFunc GetFunctionAddress(DWORD offset);
INT64 GetVirtualAddress(INT64 offset);
void InitializeModuleHandle();
bool IsCallOpcode(BYTE* address);

extern HMODULE g_hModule;
