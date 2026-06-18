#include "DisplayPaimon.h"
#include "../framework.h"
#include "../dllmain.h"
#include "../Constants.h"
#include "../utils/UnityUtils.h"
#include "../Logger.h"
#include "HooksShared.h"

typedef void(*AvatarPaimonAppearFn)(void*, void*, bool);
typedef bool(*GetActiveFn)(void*);

void DisplayPaimon::Initialize()
{
    if (g_pEnv->Offsets.IsObjectActive)
    {
        getActive = GetFunctionAddress(g_pEnv->Offsets.IsObjectActive);
    }

    if (g_pEnv->Offsets.AvatarPaimonAppear)
    {
        avatarPaimonAppear = GetFunctionAddress(g_pEnv->Offsets.AvatarPaimonAppear);
    }
}

void DisplayPaimon::OnUpdate()
{
    if (!g_pEnv->DisplayPaimon)
    {
        return;
    }

    // Execute logic only every 5000ms to reduce performance impact
    ULONGLONG now = GetTickCount64();
    if (now - m_lastExecuteTime < THROTTLE_MS)
    {
        return;
    }
    m_lastExecuteTime = now;

    if (!getActive || !avatarPaimonAppear)
    {
        return;
    }

    GetActiveFn getActiveFunc = (GetActiveFn)getActive;

    void* paimonObj = FindGameObject(PAIMON_PATH);
    void* divePaimonObj = FindGameObject(DIVE_PAIMON_PATH);
    void* beydPaimonObj = FindGameObject(BEYD_PAIMON_PATH);

    if (!paimonObj || !divePaimonObj || !beydPaimonObj)
    {
        return;
    }

    if (getActiveFunc(paimonObj) || getActiveFunc(divePaimonObj) || getActiveFunc(beydPaimonObj))
    {
        return;
    }

    AvatarPaimonAppearFn avatarPaimonAppearFunc = (AvatarPaimonAppearFn)avatarPaimonAppear;
    avatarPaimonAppearFunc(nullptr, nullptr, true);
}

bool DisplayPaimon::IsEnabled()
{
    return g_pEnv->DisplayPaimon != FALSE;
}
