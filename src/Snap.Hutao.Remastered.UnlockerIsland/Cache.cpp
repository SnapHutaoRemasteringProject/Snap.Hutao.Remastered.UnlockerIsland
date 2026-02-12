#include "Cache.h"
#include "Hooks.h"
#include "Logger.h"
#include "Constants.h"

static bool g_cacheInitialized = false;

bool g_cachedIsResisted = false;

extern LPVOID findString;
extern LPVOID findGameObject;
extern LPVOID getComponent;
extern LPVOID getText;

typedef Il2CppString*(* FindStringFn)(const char*);
typedef void*(* FindGameObjectFn)(void*);
typedef void*(* GetComponentFn)(void*, Il2CppString*);
typedef Il2CppString* (*GetTextFn)(void*);

void* GetCachedUidGameObject() {
    if (findGameObject && findString) {
        FindStringFn findStringFunc = (FindStringFn)findString;
        void* uidStr = findStringFunc(UID_PATH);
        if (uidStr) {
            FindGameObjectFn findGameObjectFunc = (FindGameObjectFn)findGameObject;
            Log("Finding UID GameObject (no cache)");
            return findGameObjectFunc(uidStr);
        }
    }
    
    Log("Failed to find UID GameObject");
    return nullptr;
}

void* GetCachedTextComponent() {
    if (getComponent && findString) {
        FindStringFn findStringFunc = (FindStringFn)findString;
        
        void* uidObj = GetCachedUidGameObject();
        if (!uidObj) {
            Log("Cannot find Text Component: UID GameObject not found");
            return nullptr;
        }
        
        Il2CppString* textStr = findStringFunc("Text");
        if (textStr) {
            GetComponentFn getComponentFunc = (GetComponentFn)getComponent;
            Log("Finding Text Component (no cache)");
            return getComponentFunc(uidObj, textStr);
        }
    }
    
    Log("Failed to find Text Component");
    return nullptr;
}

void* GetCachedPaimonGameObject() {
    if (findGameObject && findString) {
        FindStringFn findStringFunc = (FindStringFn)findString;
        void* paimonStr = findStringFunc(PAIMON_PATH);
        if (paimonStr) {
            FindGameObjectFn findGameObjectFunc = (FindGameObjectFn)findGameObject;
            Log("Finding Paimon GameObject (no cache)");
            return findGameObjectFunc(paimonStr);
        }
    }
    
    Log("Failed to find Paimon GameObject");
    return nullptr;
}

void* GetCachedDivePaimonGameObject() {
    if (findGameObject && findString) {
        FindStringFn findStringFunc = (FindStringFn)findString;
        void* paimonStr = findStringFunc(DIVE_PAIMON_PATH);
        if (paimonStr) {
            FindGameObjectFn findGameObjectFunc = (FindGameObjectFn)findGameObject;
            Log("Finding Dive Paimon GameObject (no cache)");
            return findGameObjectFunc(paimonStr);
        }
    }
    
    Log("Failed to find Dive Paimon GameObject");
    return nullptr;
}

void* GetCachedBeydPaimonGameObject() {
    if (findGameObject && findString) {
        FindStringFn findStringFunc = (FindStringFn)findString;
        void* beydPaimonStr = findStringFunc(BEYD_PAIMON_PATH);
        if (beydPaimonStr) {
            FindGameObjectFn findGameObjectFunc = (FindGameObjectFn)findGameObject;
            Log("Finding Beyd Paimon GameObject (no cache)");
            return findGameObjectFunc(beydPaimonStr);
        }
    }
    
    Log("Failed to find Beyd Paimon GameObject");
    return nullptr;
}

void* GetCachedProfileLayerGameObject() {
    if (findGameObject && findString) {
        FindStringFn findStringFunc = (FindStringFn)findString;
        void* profileLayerStr = findStringFunc(PROFILE_LAYER_PATH);
        if (profileLayerStr) {
            FindGameObjectFn findGameObjectFunc = (FindGameObjectFn)findGameObject;
            Log("Finding Profile Layer GameObject (no cache)");
            return findGameObjectFunc(profileLayerStr);
        }
    }
    
    Log("Failed to find Profile Layer GameObject");
    return nullptr;
}

void Cache_Init() {
    if (g_cacheInitialized) {
        return;
    }
    
    g_cacheInitialized = true;
    Log("Cache system initialized (CacheResistState will run on main thread every 60 frames)");
}

void Cache_Cleanup() {
    g_cacheInitialized = false;
    Log("Cache system cleaned up");
}

bool CacheResistState() {
    if (!g_cacheInitialized) {
        g_cachedIsResisted = false;
        return false;
    }

    if (findString && findGameObject && getComponent && getText) {
        void* textComp = GetCachedTextComponent();
        
        if (textComp) {
            GetTextFn getTextFunc = (GetTextFn)getText;
            Il2CppString* textStr = getTextFunc(textComp);
            
            if (textStr) {
                bool isResisted = wcsstr(textStr->chars, L"GUID") != nullptr;
                g_cachedIsResisted = isResisted;
                
                if (isResisted) {
                    Log("Resist state detected: GUID found in text");
                }
                return isResisted;
            }
        }
    }
    
    g_cachedIsResisted = false;
    return false;
}

void ClearAllCache() {
    Log("ClearAllCache called (no cache to clear)");
}
