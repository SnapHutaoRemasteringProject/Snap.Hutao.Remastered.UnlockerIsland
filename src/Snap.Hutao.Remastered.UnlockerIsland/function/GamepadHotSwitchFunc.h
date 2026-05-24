#pragma once

#include "IFunction.h"
#include "FunctionType.h"

class GamepadHotSwitchFunc : public IFunction
{
public:
	void Initialize() override;
	void OnUpdate() override;
	void* GetHookFunction() override { return nullptr; }
	bool IsEnabled() override;
	void SetEnabled(bool enabled) override { (void)enabled; }
	FunctionType GetFunctionType() override { return FunctionType::GAMEPAD_HOT_SWITCH; }

private:
	ULONGLONG m_lastExecuteTime = 0;
	static constexpr ULONGLONG THROTTLE_MS = 1000;
};
