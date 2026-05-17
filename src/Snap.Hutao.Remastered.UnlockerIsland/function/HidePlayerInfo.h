#pragma once

#include "IFunction.h"
#include "FunctionType.h"

class HidePlayerInfo : public IFunction
{
public:
    void Initialize() override;
    void OnUpdate() override;
    void* GetHookFunction() override { return nullptr; }
    bool IsEnabled() override;
    void SetEnabled(bool enabled) override { (void)enabled; }
    FunctionType GetFunctionType() override { return FunctionType::HIDE_PLAYER_INFO; }

private:
    int frameCounter = 0;
    static constexpr int FRAME_INTERVAL = 200;
};
