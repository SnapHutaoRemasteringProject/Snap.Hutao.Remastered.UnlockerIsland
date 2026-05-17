#pragma once

#include "IFunction.h"
#include "FunctionType.h"
#include "../framework.h"

class DisableDamageText : public IFunction
{
public:
    void Initialize() override;
    void OnUpdate() override {}
    void* GetHookFunction() override;
    bool IsEnabled() override;
    void SetEnabled(bool enabled) override { (void)enabled; }
    FunctionType GetFunctionType() override { return FunctionType::DISABLE_DAMAGE_TEXT; }

    static void HookShowOneDamageTextEx(void* pThis, int type_, int damageType, int showType, float damage, Il2CppString* showText, void* worldPos, void* attackee, int elementReactionType);
};
