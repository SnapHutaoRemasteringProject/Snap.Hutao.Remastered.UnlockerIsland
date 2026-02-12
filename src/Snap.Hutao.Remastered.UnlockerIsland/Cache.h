#pragma once

#include <Windows.h>

// 不再使用缓存变量，所有查找都实时进行
// 保留线程用于CacheResistState检查
// 抵抗状态保存在全局变量中供Hooks使用

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
