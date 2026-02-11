#include "Logger.h"
#include "Hooks.h"
#include <iostream>

void Log(const char* msg)
{
	if (!g_pEnv->DebugMode) {
		return;
	}
	std::cout << msg << std::endl;
}

void Log(const wchar_t* msg)
{
	if (!g_pEnv->DebugMode) {
		return;
	}
	std::wcout << msg << std::endl;
}

void Log(std::string msg)
{
	if (!g_pEnv->DebugMode) {
		return;
	}
	std::cout << msg << std::endl;
}

void Log(Il2CppString* msg)
{
	if (!g_pEnv->DebugMode) {
		return;
	}
	std::wcout << (const wchar_t*)&msg->chars << std::endl;
}
