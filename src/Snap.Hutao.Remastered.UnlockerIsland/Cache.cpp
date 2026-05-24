#include "Cache.h"
#include "function/HooksShared.h"
#include "utils/UnityUtils.h"
#include "Logger.h"
#include "Constants.h"

bool g_cachedIsResisted = false;

typedef Il2CppString* (*FindStringFn)(const char*);
typedef void* (*GetComponentFn)(void*, Il2CppString*);
typedef Il2CppString* (*GetTextFn)(void*);

bool CacheResistState()
{
    if (findString && getComponent && getText)
    {
        FindStringFn findStringFunc = (FindStringFn)findString;
        GetComponentFn getComponentFunc = (GetComponentFn)getComponent;
        GetTextFn getTextFunc = (GetTextFn)getText;

        void* uidObj = FindGameObject(UID_PATH);
        if (!uidObj)
        {
            Log("Failed to find UID GameObject for resist check");
            g_cachedIsResisted = false;
            return false;
        }

        Il2CppString* textStr = findStringFunc("Text");
        if (textStr)
        {
            void* textComp = getComponentFunc(uidObj, textStr);
            if (textComp)
            {
                Il2CppString* textContent = getTextFunc(textComp);
                if (textContent)
                {
                    bool isResisted = wcsstr(textContent->chars, L"GUID") != nullptr;
                    g_cachedIsResisted = isResisted;

                    if (isResisted)
                    {
                        Log("Resist state detected: GUID found in text");
                    }
                    return isResisted;
                }
            }
        }
    }

    g_cachedIsResisted = false;
    return false;
}

void ClearAllCache()
{
    Log("ClearAllCache called (no cache to clear)");
}

bool CheckResistInBeyd()
{
    return g_cachedIsResisted;
}
