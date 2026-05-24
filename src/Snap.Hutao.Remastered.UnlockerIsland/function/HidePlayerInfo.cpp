#include "HidePlayerInfo.h"
#include "../framework.h"
#include "../dllmain.h"
#include "../Constants.h"
#include "HooksShared.h"

typedef Il2CppString* (*FindStringFn)(const char*);
typedef void* (*FindGameObjectFn)(void*);
typedef void(*SetActiveFn)(void*, bool);
typedef bool(*GetActiveFn)(void*);

void HidePlayerInfo::Initialize()
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
        if (!setActive)
        {
            setActive = GetFunctionAddress(g_pEnv->Offsets.ObjectActive);
        }
    }

    if (g_pEnv->Offsets.IsObjectActive)
    {
        if (!getActive)
        {
            getActive = GetFunctionAddress(g_pEnv->Offsets.IsObjectActive);
        }
    }
}

void HidePlayerInfo::OnUpdate()
{
    if (!g_pEnv->HidePlayerInfo)
    {
        return;
    }

    // Execute logic only every 500ms to reduce performance impact
    ULONGLONG now = GetTickCount64();
    if (now - m_lastExecuteTime < THROTTLE_MS)
    {
        return;
    }
    m_lastExecuteTime = now;

    if (!findString || !findGameObject || !setActive || !getActive)
    {
        return;
    }

    FindStringFn findStringFunc = (FindStringFn)findString;
    FindGameObjectFn findGameObjectFunc = (FindGameObjectFn)findGameObject;
    SetActiveFn setActiveFunc = (SetActiveFn)setActive;

    Il2CppString* uidStrObj = findStringFunc(UID_PATH);
    if (uidStrObj)
    {
        void* uidObj = findGameObjectFunc(uidStrObj);
        if (uidObj)
        {
            setActiveFunc(uidObj, false);
        }
    }

    Il2CppString* profileUidStrObj = findStringFunc(PROFILE_UID_PATH);
    if (profileUidStrObj)
    {
        void* profileUidObj = findGameObjectFunc(profileUidStrObj);
        if (profileUidObj)
        {
            setActiveFunc(profileUidObj, false);
        }
    }

    Il2CppString* profileNameStrObj = findStringFunc(PROFILE_NAME_PATH);
    if (profileNameStrObj)
    {
        void* profileNameObj = findGameObjectFunc(profileNameStrObj);
        if (profileNameObj)
        {
            setActiveFunc(profileNameObj, false);
        }
    }
}

bool HidePlayerInfo::IsEnabled()
{
    return g_pEnv->HidePlayerInfo != FALSE;
}
