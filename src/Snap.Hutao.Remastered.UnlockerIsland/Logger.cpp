#include "Logger.h"
#include "hook/Hooks.h"
#include <iostream>
#include <cstdarg>
#include <cstdio>

void Log(const char* msg)
{
	if (!g_pEnv->DebugMode)
	{
		return;
	}
	std::cout << msg << std::endl;
}

void Log(const wchar_t* msg)
{
	if (!g_pEnv->DebugMode)
	{
		return;
	}
	std::wcout << msg << std::endl;
}

void Log(std::string msg)
{
	if (!g_pEnv->DebugMode)
	{
		return;
	}
	std::cout << msg << std::endl;
}

void Log(Il2CppString* msg)
{
	if (!g_pEnv->DebugMode)
	{
		return;
	}

	const wchar_t* wstr = (const wchar_t*)&msg->chars;
	int len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, nullptr, 0, nullptr, nullptr);
	std::string str(len - 1, '\0');
	WideCharToMultiByte(CP_ACP, 0, wstr, -1, &str[0], len, nullptr, nullptr);
	std::cout << str << std::endl;
}

void Logf(const char* format, ...)
{
	if (!g_pEnv->DebugMode)
	{
		return;
	}

	char buffer[512];
	va_list args;
	va_start(args, format);
	vsnprintf(buffer, sizeof(buffer), format, args);
	va_end(args);

	Log(buffer);
}
