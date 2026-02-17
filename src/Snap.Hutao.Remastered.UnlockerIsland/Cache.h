#pragma once

#include <Windows.h>

extern bool g_cachedIsResisted;

void Cache_Init();

void Cache_Cleanup();

void* GetCachedUidGameObject();

void* GetCachedTextComponent();

bool CacheResistState();

void* GetCachedPaimonGameObject();
void* GetCachedDivePaimonGameObject();
void* GetCachedBeydPaimonGameObject();
void* GetCachedProfileLayerGameObject();

void ClearAllCache();
