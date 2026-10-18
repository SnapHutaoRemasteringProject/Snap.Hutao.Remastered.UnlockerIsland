#pragma once

#include "IFunction.h"
#include "FunctionType.h"

class CatherineRedirect : public IFunction
{
public:
    void Initialize() override;
    void OnUpdate() override {}
    void* GetHookFunction() override;
    bool IsEnabled() override;
    void SetEnabled(bool enabled) override { (void)enabled; }
    FunctionType GetFunctionType() override { return FunctionType::CATHERINE_REDIRECT; }

    static void HookCatherineEntry(void* self);

    static void HookDialogCtor(void* self, void* method);

private:
    static bool OpenDialog();
    static bool OpenExplorationPage();
    static bool IsRedirectEnabled();

    static uint32_t s_callCount;
    static bool s_redirecting;
    static void* s_dialogSystem;
};
