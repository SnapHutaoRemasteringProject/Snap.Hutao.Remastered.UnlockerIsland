#pragma once

#include <Windows.h>

extern void* g_cachedUidString;
extern void* g_cachedTextString;
extern void* g_cachedUidGameObject;
extern void* g_cachedTextComponent;
extern bool g_cachedIsResisted;
extern bool g_cacheInitialized;

extern void* g_cachedPaimonString;
extern void* g_cachedBeydPaimonString;
extern void* g_cachedProfileLayerString;
extern void* g_cachedPaimonGameObject;
extern void* g_cachedBeydPaimonGameObject;
extern void* g_cachedProfileLayerGameObject;

void Cache_Init();

void Cache_Cleanup();

void* GetCachedUidString();

void* GetCachedTextString();

void* GetCachedUidGameObject();

void* GetCachedTextComponent();

bool GetCachedResistState();

void* GetCachedPaimonString();
void* GetCachedBeydPaimonString();
void* GetCachedProfileLayerString();
void* GetCachedPaimonGameObject();
void* GetCachedBeydPaimonGameObject();
void* GetCachedProfileLayerGameObject();

void ClearAllCache();
