#pragma once

#include "framework.h"
#include <string>

void Log(const char* msg);
void Log(const wchar_t* msg);
void Log(std::string msg);
void Log(Il2CppString* msg);
