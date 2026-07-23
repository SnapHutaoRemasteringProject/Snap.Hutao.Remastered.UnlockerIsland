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

    if (!getActive || !avatarPaimonAppear)
    {
        return;
    }

    // Cache GameObject pointers once, re-cache if invalidated
    if (!m_cacheValid)
    {
        m_cachedPaimon = FindGameObject(PAIMON_PATH);
        m_cachedDivePaimon = FindGameObject(DIVE_PAIMON_PATH);
        m_cachedBeydPaimon = FindGameObject(BEYD_PAIMON_PATH);

        if (!m_cachedPaimon || !m_cachedDivePaimon || !m_cachedBeydPaimon)
        {
            return;
        }

        m_cacheValid = true;
    }

    GetActiveFn getActiveFunc = (GetActiveFn)getActive;

    bool anyActive = false;
    __try
    {
        anyActive = getActiveFunc(m_cachedPaimon)
            || getActiveFunc(m_cachedDivePaimon)
            || getActiveFunc(m_cachedBeydPaimon);
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        // Object was destroyed or invalidated, re-cache next frame
        m_cacheValid = false;
        m_cachedPaimon = nullptr;
        m_cachedDivePaimon = nullptr;
        m_cachedBeydPaimon = nullptr;
        return;
    }

    if (anyActive)
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
