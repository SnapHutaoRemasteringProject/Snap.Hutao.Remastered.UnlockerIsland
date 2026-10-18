#pragma once

#include "framework.h"
#include <string>

void Log(const char* msg);
void Log(const wchar_t* msg);
void Log(std::string msg);
void Log(Il2CppString* msg);

// printf 风格的日志（受 DebugMode 门控，和 Log 一致）
void Logf(const char* format, ...);
