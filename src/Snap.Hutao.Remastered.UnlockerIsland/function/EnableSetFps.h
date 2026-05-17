#pragma once

#include "IFunction.h"
#include "FunctionType.h"

class EnableSetFps : public IFunction
{
public:
    void Initialize() override;
    void OnUpdate() override;
    void* GetHookFunction() override;
    bool IsEnabled() override;
    void SetEnabled(bool enabled) override { (void)enabled; }
    FunctionType GetFunctionType() override { return FunctionType::ENABLE_SET_FPS; }

    static int HookGetFrameCount();
};
