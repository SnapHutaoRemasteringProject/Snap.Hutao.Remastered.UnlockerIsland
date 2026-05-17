#pragma once

#include "IFunction.h"
#include "FunctionType.h"

class RemoveTeamProgress : public IFunction
{
public:
    void Initialize() override;
    void OnUpdate() override {}
    void* GetHookFunction() override;
    bool IsEnabled() override;
    void SetEnabled(bool enabled) override { (void)enabled; }
    FunctionType GetFunctionType() override { return FunctionType::REMOVE_TEAM_PROGRESS; }

    static void HookOpenTeam();
};
