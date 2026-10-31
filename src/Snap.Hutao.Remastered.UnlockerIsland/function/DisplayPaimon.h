#pragma once

#include "IFunction.h"
#include "FunctionType.h"

class DisplayPaimon : public IFunction
{
public:
    void Initialize() override;
    void OnUpdate() override;
    void* GetHookFunction() override { return nullptr; }
    bool IsEnabled() override;
    void SetEnabled(bool enabled) override { (void)enabled; }
    FunctionType GetFunctionType() override { return FunctionType::DISPLAY_PAIMON; }

private:
    // 拦截 MoleMole.BaseActor::AvatarPaimonDisappear(callback, directly)：
    static void HookAvatarPaimonDisappear(void* self, void* callback, bool directly);

    void OnPaimonDisappear();
    void CheckPaimon(ULONGLONG now);
    void RefreshCache(ULONGLONG now);
    bool IsAnyPaimonActive();
    void TryAppear(ULONGLONG now);
    void ScheduleCheck(ULONGLONG now, ULONGLONG delayMs);

    static DisplayPaimon* s_instance;

    void* m_cachedPaimon = nullptr;
    void* m_cachedDivePaimon = nullptr;
    void* m_cachedBeydPaimon = nullptr;
    bool m_cacheValid = false;
    bool m_forceFind = false;
    bool m_lastAnyActive = false;
    bool m_cacheMissLogged = false;

    ULONGLONG m_lastTick = 0;
    ULONGLONG m_lastFind = 0;
    ULONGLONG m_nextCheck = 0;
    ULONGLONG m_lastAppear = 0;

    static constexpr ULONGLONG TICK_INTERVAL_MS = 250;
    static constexpr ULONGLONG CHECK_INTERVAL_MS = 5000;
    static constexpr ULONGLONG CACHE_REFRESH_MS = 30000;
    static constexpr ULONGLONG CACHE_MISS_RETRY_MS = 10000;
    static constexpr ULONGLONG APPEAR_COOLDOWN_MS = 5000;
    static constexpr ULONGLONG DISAPPEAR_SETTLE_MS = 2500;
};
