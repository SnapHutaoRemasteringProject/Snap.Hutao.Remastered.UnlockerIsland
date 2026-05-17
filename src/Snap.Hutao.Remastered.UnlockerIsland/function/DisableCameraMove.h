#pragma once

#include "IFunction.h"
#include "FunctionType.h"

class DisableCameraMove : public IFunction
{
public:
    void Initialize() override;
    void OnUpdate() override {}
    void* GetHookFunction() override;
    bool IsEnabled() override;
    void SetEnabled(bool enabled) override { (void)enabled; }
    FunctionType GetFunctionType() override { return FunctionType::DISABLE_CAMERA_MOVE; }

    static bool HookEventCameraMove(void* pThis, void* event);
};
