#include "GamepadHotSwitchFunc.h"
#include "../framework.h"
#include "../dllmain.h"
#include "../GamepadHotSwitch.h"
#include "../Logger.h"
#include "../hook/HookWndProc.h"
#include "HooksShared.h"

void GamepadHotSwitchFunc::Initialize()
{
    if (g_pEnv->Offsets.KeyboardMouseInput)
    {
        switchInputDeviceToKeboardMouse = GetFunctionAddress(g_pEnv->Offsets.KeyboardMouseInput);
    }

    if (g_pEnv->Offsets.JoypadInput)
    {
        switchInputDeviceToJoypad = GetFunctionAddress(g_pEnv->Offsets.JoypadInput);
    }

    if (g_pEnv->Offsets.TouchInput)
    {
        switchInputDeviceToTouchScreen = GetFunctionAddress(g_pEnv->Offsets.TouchInput);
    }
}

void GamepadHotSwitchFunc::OnUpdate()
{
    if (!gamepadHotSwitchInitialized && g_pEnv->GamepadHotSwitch)
    {
        gamepadHotSwitchInitialized = true;
        GamepadHotSwitch& hotSwitch = GamepadHotSwitch::GetInstance();

        if (!hotSwitch.Initialize())
        {
            Log("[GamepadHotSwitch] Failed to initialize");
            return;
        }

        hotSwitch.SetEnabled(true);
        InitializeWndProcHooks();

        Log("[GamepadHotSwitch] Initialized and enabled");
    }
    else if (gamepadHotSwitchInitialized && !g_pEnv->GamepadHotSwitch)
    {
        GamepadHotSwitch& hotSwitch = GamepadHotSwitch::GetInstance();
        hotSwitch.SetEnabled(false);
        gamepadHotSwitchInitialized = false;
        Log("[GamepadHotSwitch] Disabled");
    }

    if (gamepadHotSwitchInitialized)
    {
        GamepadHotSwitch& hotSwitch = GamepadHotSwitch::GetInstance();
        hotSwitch.SetEnabled(g_pEnv->GamepadHotSwitch);
    }
}

bool GamepadHotSwitchFunc::IsEnabled()
{
    return g_pEnv->GamepadHotSwitch != FALSE;
}
