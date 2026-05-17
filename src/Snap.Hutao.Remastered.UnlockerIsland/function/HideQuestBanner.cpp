#include "HideQuestBanner.h"
#include "../framework.h"
#include "../dllmain.h"
#include "../Constants.h"
#include "HooksShared.h"

typedef Il2CppString* (*FindStringFn)(const char*);
typedef void* (*FindGameObjectFn)(void*);
typedef void(*SetActiveFn)(void*, bool);
typedef void(*SetupQuestBannerFn)(void*);

void HideQuestBanner::Initialize()
{
    if (g_pEnv->Offsets.FindString)
    {
        findString = GetFunctionAddress(g_pEnv->Offsets.FindString);
    }

    if (g_pEnv->Offsets.FindObject)
    {
        findGameObject = GetFunctionAddress(g_pEnv->Offsets.FindObject);
    }

    if (g_pEnv->Offsets.ObjectActive)
    {
        // Only resolve, SetActive hook is managed by HideGrass if needed
        if (!setActive)
        {
            setActive = GetFunctionAddress(g_pEnv->Offsets.ObjectActive);
        }
    }

    if (g_pEnv->Offsets.QuestBanner)
    {
        LPVOID setupQuestBannerAddr = GetFunctionAddress(g_pEnv->Offsets.QuestBanner);
        if (setupQuestBannerAddr)
        {
            MH_CreateHook(setupQuestBannerAddr, &HideQuestBanner::HookSetupQuestBanner, &originalSetupQuestBanner);
        }
    }
}

void* HideQuestBanner::GetHookFunction()
{
    return (void*)&HideQuestBanner::HookSetupQuestBanner;
}

bool HideQuestBanner::IsEnabled()
{
    return g_pEnv->HideQuestBanner != FALSE;
}

void HideQuestBanner::HookSetupQuestBanner(void* pThis)
{
    if (findString && findGameObject && setActive)
    {
        FindStringFn findStringFunc = (FindStringFn)findString;
        FindGameObjectFn findGameObjectFunc = (FindGameObjectFn)findGameObject;
        SetActiveFn setActiveFunc = (SetActiveFn)setActive;

        if (g_pEnv->HideQuestBanner)
        {
            Il2CppString* strObj = findStringFunc(QUEST_BANNER_PATH);
            if (strObj)
            {
                void* banner = findGameObjectFunc(strObj);
                if (banner)
                {
                    setActiveFunc(banner, false);
                    return;
                }
            }
        }
    }

    if (originalSetupQuestBanner)
    {
        SetupQuestBannerFn original = (SetupQuestBannerFn)originalSetupQuestBanner;
        original(pThis);
    }
}
