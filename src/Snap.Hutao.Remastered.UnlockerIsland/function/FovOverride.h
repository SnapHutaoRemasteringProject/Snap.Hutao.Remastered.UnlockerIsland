#pragma once

#include "IFunction.h"
#include "FunctionType.h"

class FovOverride : public IFunction
{
public:
    void Initialize() override;
    void OnUpdate() override;
    void* GetHookFunction() override { return nullptr; }
    bool IsEnabled() override;
    void SetEnabled(bool enabled) override { (void)enabled; }
    FunctionType GetFunctionType() override { return FunctionType::FOV_OVERRIDE; }
};
