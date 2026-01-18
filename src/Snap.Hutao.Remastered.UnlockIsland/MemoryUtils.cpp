#include "MemoryUtils.h"

VoidFunc GetFunctionAddress(DWORD offset)
{
	if (g_hModule == NULL) {
		InitializeModuleHandle();
	}

	return (VoidFunc)((DWORD_PTR)g_hModule + offset);
}

INT64 GetRealAddress(INT64 offset)
{
	if (g_hModule == NULL) {
		InitializeModuleHandle();
	}

	return (INT64)((DWORD_PTR)g_hModule + offset);
}

void InitializeModuleHandle()
{
	g_hModule = GetModuleHandleW(L"YuanShen.exe");
	if (g_hModule == NULL) {
		g_hModule = GetModuleHandleW(L"GenshinImpact.exe");
	}
}

HMODULE g_hModule = NULL;
