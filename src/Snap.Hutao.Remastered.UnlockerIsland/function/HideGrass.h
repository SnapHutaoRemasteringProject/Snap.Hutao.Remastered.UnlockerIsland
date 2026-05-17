#pragma once

#include "IFunction.h"
#include "FunctionType.h"

class HideGrass : public IFunction
{
public:
    void Initialize() override;
    void OnUpdate() override {}
    void* GetHookFunction() override;
    bool IsEnabled() override;
    void SetEnabled(bool enabled) override { (void)enabled; }
    FunctionType GetFunctionType() override { return FunctionType::HIDE_GRASS; }

    static void HookSetActive(void* pThis, bool active);
};
