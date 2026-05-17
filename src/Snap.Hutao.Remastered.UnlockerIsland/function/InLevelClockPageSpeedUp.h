#pragma once

#include "IFunction.h"
#include "FunctionType.h"

class InLevelClockPageSpeedUp : public IFunction
{
public:
    void Initialize() override;
    void OnUpdate() override {}
    void* GetHookFunction() override;
    bool IsEnabled() override;
    void SetEnabled(bool enabled) override { (void)enabled; }
    FunctionType GetFunctionType() override { return FunctionType::IN_LEVEL_CLOCK_PAGE_SPEED_UP; }

    static void HookInLevelClockPageOkButtonClicked(void* pThis);
};
