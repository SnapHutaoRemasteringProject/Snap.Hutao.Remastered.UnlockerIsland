#pragma once

#include <Windows.h>

extern bool g_cachedIsResisted;

bool CacheResistState();
void ClearAllCache();

bool CheckResistInBeyd();
