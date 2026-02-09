#include "Cache.h"
#include "Hooks.h"
#include "Constants.h"
#include <atomic>

void* g_cachedUidString = nullptr;
void* g_cachedTextString = nullptr;
void* g_cachedUidGameObject = nullptr;
void* g_cachedTextComponent = nullptr;
bool g_cachedIsResisted = false;
bool g_cacheInitialized = false;

void* g_cachedPaimonString = nullptr;
void* g_cachedBeydPaimonString = nullptr;
void* g_cachedProfileLayerString = nullptr;
void* g_cachedPaimonGameObject = nullptr;
void* g_cachedBeydPaimonGameObject = nullptr;
void* g_cachedProfileLayerGameObject = nullptr;

extern LPVOID findString;
extern LPVOID findGameObject;
extern LPVOID getComponent;
extern LPVOID getText;

typedef Il2CppString*(* FindStringFn)(const char*);
typedef void*(* FindGameObjectFn)(void*);
typedef void*(* GetComponentFn)(void*, Il2CppString*);
typedef Il2CppString* (*GetTextFn)(void*);

void* GetCachedUidString() {
    if (findString) {
        FindStringFn findStringFunc = (FindStringFn)findString;
        g_cachedUidString = findStringFunc(UID_PATH);
    }
    return g_cachedUidString;
}

void* GetCachedTextString() {
    if (findString) {
        FindStringFn findStringFunc = (FindStringFn)findString;
        g_cachedTextString = findStringFunc("Text");
    }
    return g_cachedTextString;
}

void* GetCachedUidGameObject() {
    if (findGameObject) {
        void* uidStr = GetCachedUidString();
        if (uidStr) {
            FindGameObjectFn findGameObjectFunc = (FindGameObjectFn)findGameObject;
            g_cachedUidGameObject = findGameObjectFunc(uidStr);
        }
    }
    return g_cachedUidGameObject;
}

void* GetCachedTextComponent() {
    if (getComponent) {
        void* uidObj = GetCachedUidGameObject();
        void* textStr = GetCachedTextString();
        if (uidObj && textStr) {
            GetComponentFn getComponentFunc = (GetComponentFn)getComponent;
            g_cachedTextComponent = getComponentFunc(uidObj, (Il2CppString*)textStr);
        }
    }
    return g_cachedTextComponent;
}

void* GetCachedPaimonString() {
    if (findString) {
        FindStringFn findStringFunc = (FindStringFn)findString;
        g_cachedPaimonString = findStringFunc(PAIMON_PATH);
    }
    return g_cachedPaimonString;
}

void* GetCachedBeydPaimonString() {
    if (findString) {
        FindStringFn findStringFunc = (FindStringFn)findString;
        g_cachedBeydPaimonString = findStringFunc(BEYD_PAIMON_PATH);
    }
    return g_cachedBeydPaimonString;
}

void* GetCachedProfileLayerString() {
    if (findString) {
        FindStringFn findStringFunc = (FindStringFn)findString;
        g_cachedProfileLayerString = findStringFunc(PROFILE_LAYER_PATH);
    }
    return g_cachedProfileLayerString;
}

void* GetCachedPaimonGameObject() {
    if (findGameObject) {
        void* paimonStr = GetCachedPaimonString();
        if (paimonStr) {
            FindGameObjectFn findGameObjectFunc = (FindGameObjectFn)findGameObject;
            g_cachedPaimonGameObject = findGameObjectFunc(paimonStr);
        }
    }
    return g_cachedPaimonGameObject;
}

void* GetCachedBeydPaimonGameObject() {
    if (findGameObject) {
        void* beydPaimonStr = GetCachedBeydPaimonString();
        if (beydPaimonStr) {
            FindGameObjectFn findGameObjectFunc = (FindGameObjectFn)findGameObject;
            g_cachedBeydPaimonGameObject = findGameObjectFunc(beydPaimonStr);
        }
    }
    return g_cachedBeydPaimonGameObject;
}

void* GetCachedProfileLayerGameObject() {
    if (findGameObject) {
        void* profileLayerStr = GetCachedProfileLayerString();
        if (profileLayerStr) {
            FindGameObjectFn findGameObjectFunc = (FindGameObjectFn)findGameObject;
            g_cachedProfileLayerGameObject = findGameObjectFunc(profileLayerStr);
        }
    }
    return g_cachedProfileLayerGameObject;
}

void Cache_Init() {
    g_cacheInitialized = true;
}

void Cache_Cleanup() {
    ClearAllCache();
    g_cacheInitialized = false;
}

bool GetCachedResistState() {
    if (!g_cacheInitialized) {
        return false;
    }
    
    if (findString && findGameObject && getComponent && getText) {
        __try {
            void* textComp = GetCachedTextComponent();
            
            if (textComp) {
                GetTextFn getTextFunc = (GetTextFn)getText;
                Il2CppString* textStr = getTextFunc(textComp);
                
                if (textStr && textStr->chars) {
                    const wchar_t* resistText = L"GUID";
                    g_cachedIsResisted = wcsstr(textStr->chars, resistText) != nullptr;
                    return g_cachedIsResisted;
                }
            }
        } __except (EXCEPTION_EXECUTE_HANDLER) {
            g_cachedIsResisted = false;
        }
    }
    
    g_cachedIsResisted = false;
    return false;
}

void ClearAllCache() {
    g_cachedUidString = nullptr;
    g_cachedTextString = nullptr;
    g_cachedUidGameObject = nullptr;
    g_cachedTextComponent = nullptr;
    g_cachedIsResisted = false;
    
    g_cachedPaimonString = nullptr;
    g_cachedBeydPaimonString = nullptr;
    g_cachedProfileLayerString = nullptr;
    g_cachedPaimonGameObject = nullptr;
    g_cachedBeydPaimonGameObject = nullptr;
    g_cachedProfileLayerGameObject = nullptr;
}
