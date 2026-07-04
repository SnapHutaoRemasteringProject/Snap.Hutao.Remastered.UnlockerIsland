#include "Cache.h"
#include "function/HooksShared.h"
#include "utils/UnityUtils.h"
#include "Logger.h"
#include "Constants.h"

bool g_cachedIsResisted = false;

typedef Il2CppString* (*FindStringFn)(const char*);
typedef void* (*GetComponentFn)(void*, Il2CppString*);

Il2CppString* GetText(void* pText)
{
    return *(Il2CppString**)((uintptr_t)pText + 0xE0);
}

bool CacheResistState()
{
    if (findString && getComponent)
    {
        FindStringFn findStringFunc = (FindStringFn)findString;
        GetComponentFn getComponentFunc = (GetComponentFn)getComponent;

        void* uidObj = FindGameObject(UID_PATH);
        if (!uidObj)
        {
            Log("Failed to find UID GameObject for resist check");
            g_cachedIsResisted = false;
            return false;
        }

        Log("UID GameObject was found for resist check");

        Il2CppString* textStr = findStringFunc("Text");
        if (textStr)
        {
            void* textComp = getComponentFunc(uidObj, textStr);

            if (textComp)
            {
                Log("Text component was found for resist check");
                Il2CppString* textContent = GetText(textComp);
                if (textContent)
                {
                    bool isResisted = wcsstr(textContent->chars, L"GUID") != nullptr;
                    if (isResisted)
                    {
						for (auto& whiteListItem : BeyondWhiteList)
						{
							if (wcsstr(textContent->chars, whiteListItem.c_str()) != nullptr)
							{
								isResisted = false;
								Log(("GUID whitelist match found"));
								break;
							}
						}
                    }

                    g_cachedIsResisted = isResisted;

                    if (isResisted)
                    {
                        Log("Resist state detected: GUID found in text");
                    }
                    return isResisted;
                }
            } 
            else 
            {
                Log("Text component was not found for resist check");
            }
        }
    }

    g_cachedIsResisted = false;
    return false;
}

bool CheckResistInBeyd()
{
    return g_cachedIsResisted;
}
