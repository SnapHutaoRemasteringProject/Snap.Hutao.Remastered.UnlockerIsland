#pragma once

#include "IFunction.h"
#include "FunctionType.h"
#include "../utils/Patch.h"

class DisablePlayerPerspective : public IFunction
{
public:
    void Initialize() override;
    void OnUpdate() override;
    void* GetHookFunction() override;
    bool IsEnabled() override;
    void SetEnabled(bool enabled) override { (void)enabled; }
    FunctionType GetFunctionType() override { return FunctionType::DISABLE_PLAYER_PERSPECTIVE; }

    static void HookPlayerPerspective(void* rcx, bool display);
    static void HookPlayerDiveMosaic(void* a1, float a2);
    
private:
    Patch* patch;
};
