#pragma once

#include "IFunction.h"
#include "FunctionType.h"

class WeakMapCheck : public IFunction
{
public:
    void Initialize() override;
    void OnUpdate() override {}
    void* GetHookFunction() override;
    bool IsEnabled() override;
    void SetEnabled(bool enabled) override { (void)enabled; }
    FunctionType GetFunctionType() override { return FunctionType::WEAK_MAP_CHECK; }

    static bool HookCheckCanOpenMap(void* pThis);
};
