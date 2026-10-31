#include "DisplayPaimon.h"
#include "../framework.h"
#include "../dllmain.h"
#include "../Constants.h"
#include "../utils/UnityUtils.h"
#include "../Logger.h"
#include "HooksShared.h"

typedef void(*AvatarPaimonAppearFn)(void*, void*, bool);
typedef void(*AvatarPaimonDisappearFn)(void*, void*, bool);
typedef bool(*GetActiveFn)(void*);

DisplayPaimon* DisplayPaimon::s_instance = nullptr;

void DisplayPaimon::Initialize()
{
    s_instance = this;

    if (g_pEnv->Offsets.IsObjectActive)
    {
        getActive = GetFunctionAddress(g_pEnv->Offsets.IsObjectActive);
    }

    if (g_pEnv->Offsets.AvatarPaimonAppear)
    {
        avatarPaimonAppear = GetFunctionAddress(g_pEnv->Offsets.AvatarPaimonAppear);
    }

    if (g_pEnv->Offsets.AvatarPaimonDisappear)
    {
        LPVOID avatarPaimonDisappearAddr = GetFunctionAddress(g_pEnv->Offsets.AvatarPaimonDisappear);
        if (avatarPaimonDisappearAddr)
        {
            MH_CreateHook(avatarPaimonDisappearAddr, &DisplayPaimon::HookAvatarPaimonDisappear, &originalAvatarPaimonDisappear);
        }
    }
}

void DisplayPaimon::ScheduleCheck(ULONGLONG now, ULONGLONG delayMs)
{
    m_nextCheck = now + delayMs;
}

void DisplayPaimon::OnPaimonDisappear()
{
    const ULONGLONG now = GetTickCount64();
    m_lastAnyActive = false;

    // 消失动画和游戏内部 2s 的回调都结束之后，再决定是否把她拉回来。
    ScheduleCheck(now, DISAPPEAR_SETTLE_MS);
}

void DisplayPaimon::HookAvatarPaimonDisappear(void* self, void* callback, bool directly)
{
    if (originalAvatarPaimonDisappear)
    {
        AvatarPaimonDisappearFn original = (AvatarPaimonDisappearFn)originalAvatarPaimonDisappear;
        original(self, callback, directly);
    }

    if (g_pEnv->DisplayPaimon && s_instance)
    {
        Logf("DisplayPaimon: AvatarPaimonDisappear called (callback=%p, directly=%d)",
            callback, (int)directly);
        s_instance->OnPaimonDisappear();
    }
}

void DisplayPaimon::RefreshCache(ULONGLONG now)
{
    void* paimon = FindGameObject(PAIMON_PATH);
    void* divePaimon = FindGameObject(DIVE_PAIMON_PATH);
    void* beydPaimon = FindGameObject(BEYD_PAIMON_PATH);

    const bool wasValid = m_cacheValid;
    const bool changed = paimon != m_cachedPaimon
        || divePaimon != m_cachedDivePaimon
        || beydPaimon != m_cachedBeydPaimon;

    m_cachedPaimon = paimon;
    m_cachedDivePaimon = divePaimon;
    m_cachedBeydPaimon = beydPaimon;
    // 三个路径并不总是同时存在（潜水分支 / 千星奇域分支），有一个可用即可。
    m_cacheValid = paimon != nullptr || divePaimon != nullptr || beydPaimon != nullptr;
    m_lastFind = now;

    if (!wasValid && m_cacheValid)
    {
        m_cacheMissLogged = false;
        Logf("DisplayPaimon: cache resolved (paimon=%p dive=%p beyd=%p)",
            paimon, divePaimon, beydPaimon);
    }
    else if (wasValid && changed)
    {
        Logf("DisplayPaimon: cache changed (paimon=%p dive=%p beyd=%p)",
            paimon, divePaimon, beydPaimon);
    }
    else if (!m_cacheValid && !m_cacheMissLogged)
    {
        // 只在第一次 miss 时输出，之后按退避静默重试，避免刷屏。
        m_cacheMissLogged = true;
        Log("DisplayPaimon: cache miss - 当前场景还没有派蒙实体，稍后重试");
    }
}

bool DisplayPaimon::IsAnyPaimonActive()
{
    GetActiveFn getActiveFunc = (GetActiveFn)getActive;

    __try
    {
        if (m_cachedPaimon && getActiveFunc(m_cachedPaimon))
        {
            return true;
        }
        if (m_cachedDivePaimon && getActiveFunc(m_cachedDivePaimon))
        {
            return true;
        }
        if (m_cachedBeydPaimon && getActiveFunc(m_cachedBeydPaimon))
        {
            return true;
        }
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        m_cacheValid = false;
        m_forceFind = true;
        m_cachedPaimon = nullptr;
        m_cachedDivePaimon = nullptr;
        m_cachedBeydPaimon = nullptr;
        return false;
    }

    return false;
}

void DisplayPaimon::TryAppear(ULONGLONG now)
{
    m_lastAppear = now;

    Log("DisplayPaimon: triggering AvatarPaimonAppear");
    AvatarPaimonAppearFn avatarPaimonAppearFunc = (AvatarPaimonAppearFn)avatarPaimonAppear;
    avatarPaimonAppearFunc(nullptr, nullptr, true);
}

void DisplayPaimon::CheckPaimon(ULONGLONG now)
{
    // 定期（或出现/失效后）重新用 FindGameObject 解析，不能一次命中永久有效。
    if (m_forceFind || !m_cacheValid || now - m_lastFind >= CACHE_REFRESH_MS)
    {
        RefreshCache(now);
        m_forceFind = false;
    }

    if (!m_cacheValid)
    {
        ScheduleCheck(now, CACHE_MISS_RETRY_MS);
        return;
    }

    const bool anyActive = IsAnyPaimonActive();

    if (!m_cacheValid)
    {
        ScheduleCheck(now, CACHE_MISS_RETRY_MS);
        return;
    }

    if (anyActive)
    {
        if (!m_lastAnyActive)
        {
            m_lastAnyActive = true;
            Log("DisplayPaimon: Paimon is visible");
        }

        ScheduleCheck(now, CHECK_INTERVAL_MS);
        return;
    }

    if (m_lastAnyActive)
    {
        m_lastAnyActive = false;
        Log("DisplayPaimon: Paimon is hidden");
    }

    if (m_lastAppear != 0 && now - m_lastAppear < APPEAR_COOLDOWN_MS)
    {
        ScheduleCheck(now, CHECK_INTERVAL_MS);
        return;
    }

    TryAppear(now);

    // 出现后实例可能被重建：下一轮先重新 Find，再根据新指针判定，
    // 否则旧指针会一直返回 inactive，导致不停重复调用 AvatarPaimonAppear。
    m_forceFind = true;
    ScheduleCheck(now, CHECK_INTERVAL_MS);
}

void DisplayPaimon::OnUpdate()
{
    if (!g_pEnv->DisplayPaimon)
    {
        m_nextCheck = 0;
        return;
    }

    if (!getActive || !avatarPaimonAppear)
    {
        return;
    }

    const ULONGLONG now = GetTickCount64();

    if (now - m_lastTick < TICK_INTERVAL_MS)
    {
        return;
    }
    m_lastTick = now;

    if (m_nextCheck != 0 && now < m_nextCheck)
    {
        return;
    }

    CheckPaimon(now);
}

bool DisplayPaimon::IsEnabled()
{
    return g_pEnv->DisplayPaimon != FALSE;
}
