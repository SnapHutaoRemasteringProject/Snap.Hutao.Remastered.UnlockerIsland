#include "TouchMode.h"
#include "../framework.h"
#include "../dllmain.h"
#include "../Logger.h"
#include "HooksShared.h"

typedef void(*SwitchInputDeviceToTouchScreenFn)(void*);

void TouchMode::Initialize()
{
    if (g_pEnv->Offsets.TouchInput)
    {
        switchInputDeviceToTouchScreen = GetFunctionAddress(g_pEnv->Offsets.TouchInput);
    }
}

void TouchMode::OnUpdate()
{
    if (gameUpdateInit && !touchScreenInit && g_pEnv->TouchMode && switchInputDeviceToTouchScreen)
    {
        touchScreenInit = true;
        SwitchInputDeviceToTouchScreenFn switchInput = (SwitchInputDeviceToTouchScreenFn)switchInputDeviceToTouchScreen;
        __try
        {
            switchInput(nullptr);
        }
        __except (EXCEPTION_EXECUTE_HANDLER)
        {
            // Ignore exceptions
        }
    }
}

bool TouchMode::IsEnabled()
{
    return g_pEnv->TouchMode != FALSE;
}
