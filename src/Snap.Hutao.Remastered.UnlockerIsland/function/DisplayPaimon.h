#pragma once

#include "IFunction.h"
#include "FunctionType.h"

class DisplayPaimon : public IFunction
{
public:
    void Initialize() override;
    void OnUpdate() override;
    void* GetHookFunction() override;
    bool IsEnabled() override;
    void SetEnabled(bool enabled) override { (void)enabled; }
    FunctionType GetFunctionType() override { return FunctionType::DISPLAY_PAIMON; }

    static void HookActorManagerCtor(void* pThis);

private:
    int frameCounter = 0;
    static constexpr int FRAME_INTERVAL = 200;
};
