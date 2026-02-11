#include "Cache.h"
#include "Hooks.h"
#include "Logger.h"
#include "Constants.h"

void* g_cachedUidGameObject = nullptr;
bool g_cachedIsResisted = false;
bool g_cacheInitialized = false;

void* g_cachedPaimonGameObject = nullptr;
void* g_cachedBeydPaimonGameObject = nullptr;
void* g_cachedProfileLayerGameObject = nullptr;
void* g_cachedTextComponent = nullptr;

HANDLE g_cacheThreadHandle = nullptr;

extern LPVOID findString;
extern LPVOID findGameObject;
extern LPVOID getComponent;
extern LPVOID getText;

typedef Il2CppString*(* FindStringFn)(const char*);
typedef void*(* FindGameObjectFn)(void*);
typedef void*(* GetComponentFn)(void*, Il2CppString*);
typedef Il2CppString* (*GetTextFn)(void*);

void* GetCachedUidGameObject() {
    if (g_cachedUidGameObject) {
		Log("Returning cached UID GameObject");
        return g_cachedUidGameObject;
	}

    if (findGameObject && findString) {
        FindStringFn findStringFunc = (FindStringFn)findString;
        void* uidStr = findStringFunc(UID_PATH);
        if (uidStr) {
            FindGameObjectFn findGameObjectFunc = (FindGameObjectFn)findGameObject;
            g_cachedUidGameObject = findGameObjectFunc(uidStr);
        }
    }

	Log("Cached UID GameObject initialized");
    return g_cachedUidGameObject;
}

void* GetCachedTextComponent() {
	if (g_cachedTextComponent) {
        Log("Returning cached Text Component");
        return g_cachedTextComponent;
    }

    if (getComponent && findString) {
        FindStringFn findStringFunc = (FindStringFn)findString;
        void* uidObj = g_cachedUidGameObject;
        Il2CppString* textStr = findStringFunc("Text");
        if (uidObj && textStr) {
            GetComponentFn getComponentFunc = (GetComponentFn)getComponent;
            g_cachedTextComponent = getComponentFunc(uidObj, textStr);
        }
    }

	Log("Cached Text Component initialized");
    return g_cachedTextComponent;
}

void* GetCachedPaimonGameObject() {
	if (g_cachedPaimonGameObject) {
        Log("Returning cached Paimon GameObject");
		return g_cachedPaimonGameObject;
	}

    if (findGameObject && findString) {
        FindStringFn findStringFunc = (FindStringFn)findString;
        void* paimonStr = findStringFunc(PAIMON_PATH);
        if (paimonStr) {
            FindGameObjectFn findGameObjectFunc = (FindGameObjectFn)findGameObject;
            g_cachedPaimonGameObject = findGameObjectFunc(paimonStr);
        }
    }

	Log("Cached Paimon GameObject initialized");
    return g_cachedPaimonGameObject;
}

void* GetCachedBeydPaimonGameObject() {
    if (g_cachedBeydPaimonGameObject) {
        Log("Returning cached Beyd Paimon GameObject");
        return g_cachedBeydPaimonGameObject;
	}

    if (findGameObject && findString) {
        FindStringFn findStringFunc = (FindStringFn)findString;
        void* beydPaimonStr = findStringFunc(BEYD_PAIMON_PATH);
        if (beydPaimonStr) {
            FindGameObjectFn findGameObjectFunc = (FindGameObjectFn)findGameObject;
            g_cachedBeydPaimonGameObject = findGameObjectFunc(beydPaimonStr);
        }
    }

	Log("Cached Beyd Paimon GameObject initialized");
    return g_cachedBeydPaimonGameObject;
}

void* GetCachedProfileLayerGameObject() {
    if (g_cachedProfileLayerGameObject) {
        Log("Returning cached Profile Layer GameObject");
		return g_cachedProfileLayerGameObject;
	}

    if (findGameObject && findString) {
        FindStringFn findStringFunc = (FindStringFn)findString;
        void* profileLayerStr = findStringFunc(PROFILE_LAYER_PATH);
        if (profileLayerStr) {
            FindGameObjectFn findGameObjectFunc = (FindGameObjectFn)findGameObject;
            g_cachedProfileLayerGameObject = findGameObjectFunc(profileLayerStr);
        }
    }

	Log("Cached Profile Layer GameObject initialized");
    return g_cachedProfileLayerGameObject;
}

void Cache_Init() {
    if (g_cacheInitialized) {
        return;
    }

    g_cacheThreadHandle = CreateThread(nullptr, 0, [](LPVOID) -> DWORD {
        while (true) {
            Sleep(100);
			CacheResistState();
        }
        return 0;
		}, nullptr, 0, nullptr);
    g_cacheInitialized = true;
}

void Cache_Cleanup() {
	TerminateThread(g_cacheThreadHandle, 0);

    ClearAllCache();
    g_cacheInitialized = false;
}

bool CacheResistState() {
    if (!g_cacheInitialized) {
        return false;
    }

    if (findString && findGameObject && getComponent && getText) {
        void* textComp = g_cachedTextComponent;

        if (textComp) {
            GetTextFn getTextFunc = (GetTextFn)getText;
            Il2CppString* textStr = getTextFunc(textComp);

            if (textStr) {
                g_cachedIsResisted = wcsstr(textStr->chars, L"GUID") != nullptr;
                return g_cachedIsResisted;
            }
        }
    }

    g_cachedIsResisted = false;
    return false;
}

void ClearAllCache() {
    g_cachedUidGameObject = nullptr;
    g_cachedIsResisted = false;
    
    g_cachedPaimonGameObject = nullptr;
    g_cachedBeydPaimonGameObject = nullptr;
    g_cachedProfileLayerGameObject = nullptr;
}
