#pragma once

#include <Windows.h>

extern void* g_cachedUidGameObject;
extern bool g_cachedIsResisted;
extern bool g_cacheInitialized;

extern void* g_cachedPaimonGameObject;
extern void* g_cachedBeydPaimonGameObject;
extern void* g_cachedProfileLayerGameObject;
extern void* g_cachedTextComponent;

void Cache_Init();

void Cache_Cleanup();

void* GetCachedUidGameObject();

void* GetCachedTextComponent();

bool CacheResistState();

void* GetCachedPaimonGameObject();
void* GetCachedBeydPaimonGameObject();
void* GetCachedProfileLayerGameObject();

void ClearAllCache();
