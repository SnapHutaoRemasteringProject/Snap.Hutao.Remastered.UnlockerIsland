#pragma once

#include "IFunction.h"
#include "FunctionType.h"
#include "../utils/Patch.h"

class DisablePlayerDiveMosaic : public IFunction
{
public:
    void Initialize() override;
    void OnUpdate() override;
    void* GetHookFunction() override;
    bool IsEnabled() override;
    void SetEnabled(bool enabled) override { (void)enabled; }
    FunctionType GetFunctionType() override { return FunctionType::DISABLE_PLAYER_DIVE_MOSAIC; }

    static void HookPlayerDiveMosaic(void* a1, float a2);

private:
    Patch* patch;
};
