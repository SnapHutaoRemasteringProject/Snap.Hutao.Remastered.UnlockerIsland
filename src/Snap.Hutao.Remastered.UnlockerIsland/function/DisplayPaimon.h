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
    bool m_cacheValid = false;
    void* m_cachedPaimon = nullptr;
    void* m_cachedDivePaimon = nullptr;
    void* m_cachedBeydPaimon = nullptr;
};
