#pragma once

#include "FunctionType.h"
#include "../framework.h"

class IFunction
{
public:
	virtual ~IFunction() = default;
	virtual void Initialize() = 0;
	virtual void OnUpdate() = 0;
	virtual void* GetHookFunction() = 0;
	virtual bool IsEnabled() = 0;
	virtual void SetEnabled(bool enabled) = 0;
	virtual FunctionType GetFunctionType() = 0;
};