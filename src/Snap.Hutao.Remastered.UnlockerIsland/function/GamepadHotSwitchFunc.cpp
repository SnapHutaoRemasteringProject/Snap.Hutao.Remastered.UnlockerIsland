#include "GamepadHotSwitchFunc.h"
#include "../framework.h"
#include "../dllmain.h"
#include "../GamepadHotSwitch.h"
#include "../Logger.h"
#include "../hook/HookWndProc.h"
#include "../utils/UnityUtils.h"
#include "HooksShared.h"

void GamepadHotSwitchFunc::Initialize()
{
	if (g_pEnv->Offsets.KeyboardMouseInput)
	{
		switchInputDeviceToKeyboardMouse = GetFunctionAddress(g_pEnv->Offsets.KeyboardMouseInput);
	}

	if (g_pEnv->Offsets.JoypadInput)
	{
		switchInputDeviceToJoypad = GetFunctionAddress(g_pEnv->Offsets.JoypadInput);
	}

	if (g_pEnv->Offsets.TouchInput)
	{
		switchInputDeviceToTouchScreen = GetFunctionAddress(g_pEnv->Offsets.TouchInput);
	}

	if (g_pEnv->Offsets.FindString)
	{
		findString = GetFunctionAddress(g_pEnv->Offsets.FindString);
	}

	if (g_pEnv->Offsets.FindObject)
	{
		findGameObject = GetFunctionAddress(g_pEnv->Offsets.FindObject);
	}

	if (g_pEnv->Offsets.IsObjectActive)
	{
		if (!getActive)
		{
			getActive = GetFunctionAddress(g_pEnv->Offsets.IsObjectActive);
		}
	}
}

void GamepadHotSwitchFunc::OnUpdate()
{
	GamepadHotSwitch& hotSwitch = GamepadHotSwitch::GetInstance();
	if (findString && findGameObject && getActive)
	{
		// Execute logic only every 1000ms to reduce performance impact
		ULONGLONG now = GetTickCount64();
		if (now - m_lastExecuteTime < THROTTLE_MS)
		{
			goto postChatCheck;
		}
		m_lastExecuteTime = now;

		void* chatObj = FindGameObject(CHAT_DIALOG_PATH);
		if (chatObj)
		{
			typedef bool (*GetActiveFn)(void*);
			if (((GetActiveFn)getActive)(chatObj))
			{
				Log("[GamepadHotSwitch] Input page active, ignoring key");
				hotSwitch.SetIsInChatPage(true);
				goto postChatCheck;
			}

			hotSwitch.SetIsInChatPage(false);
		}

		hotSwitch.SetIsInChatPage(false);
	}
postChatCheck:
	if (!gamepadHotSwitchInitialized && g_pEnv->GamepadHotSwitch)
	{
		gamepadHotSwitchInitialized = true;

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
		hotSwitch.SetEnabled(false);
		gamepadHotSwitchInitialized = false;
		Log("[GamepadHotSwitch] Disabled");
	}

	if (gamepadHotSwitchInitialized)
	{
		hotSwitch.SetEnabled(g_pEnv->GamepadHotSwitch);
	}
}

bool GamepadHotSwitchFunc::IsEnabled()
{
	return g_pEnv->GamepadHotSwitch != FALSE;
}
