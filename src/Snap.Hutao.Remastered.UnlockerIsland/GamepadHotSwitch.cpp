#include "GamepadHotSwitch.h"
#include "hook/HookWndProc.h"
#include "Constants.h"
#include "utils/UnityUtils.h"
#include "function/HooksShared.h"
#include "Logger.h"
#include <chrono>

GamepadHotSwitch::GamepadHotSwitch()
{
}

GamepadHotSwitch::~GamepadHotSwitch()
{
    Shutdown();
}

GamepadHotSwitch& GamepadHotSwitch::GetInstance()
{
    static GamepadHotSwitch instance;
    return instance;
}

bool GamepadHotSwitch::Initialize()
{
    if (m_hThread)
    {
        Log("[GamepadHotSwitch] Already initialized");
        return true;
    }

    if (!InitializeXInput())
        return false;

    m_isExiting = false;
    m_hThread = CreateThread(nullptr, 0, [](LPVOID lpParam) -> DWORD
    {
        GamepadHotSwitch* pThis = static_cast<GamepadHotSwitch*>(lpParam);
        pThis->MainThread();
        return 0;
    }, this, 0, nullptr);

    if (!m_hThread)
    {
        if (m_hXInput)
        {
            FreeLibrary(m_hXInput);
            m_hXInput = nullptr;
        }
        Log("[GamepadHotSwitch] Failed to create thread");
        return false;
    }

    Log("[GamepadHotSwitch] Initialized successfully");
    return true;
}

void GamepadHotSwitch::Shutdown()
{
    m_isExiting = true;
    m_enabled = false;

	if (m_hThread)
	{
		WaitForSingleObject(m_hThread, 100);

		CloseHandle(m_hThread);
		m_hThread = nullptr;
	}

    if (m_hXInput)
    {
        FreeLibrary(m_hXInput);
        m_hXInput = nullptr;
        m_XInputGetKeystroke = nullptr;
    }
    
    Log("[GamepadHotSwitch] Shutdown");
}

void GamepadHotSwitch::SetEnabled(bool enabled)
{
    if (enabled == m_enabled)
        return;

    m_enabled = enabled;

    if (enabled)
    {
        if (!m_hThread)
        {
            Initialize();
        }
        Log("[GamepadHotSwitch] Enabled");
    }
    else
    {
        Log("[GamepadHotSwitch] Disabled");
    }
}

void GamepadHotSwitch::SetIsInChatPage(bool inChat)
{
	isInChatPage = inChat;
}

bool GamepadHotSwitch::IsEnabled() const
{
    return m_enabled;
}

void GamepadHotSwitch::ProcessWindowMessage(UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (!m_enabled)
        return;

    ULONGLONG currentTime = GetTickCount64();
    switch (msg)
    {
    case WM_KILLFOCUS:
        m_pauseUntilTime = MAXULONGLONG;
        break;
    case WM_SETFOCUS:
        m_pauseUntilTime = currentTime + SWITCH_DELAY_MS;
        break;
    case WM_WINDOWPOSCHANGING:
        if (m_pauseUntilTime != MAXULONGLONG)
            m_pauseUntilTime = currentTime + SWITCH_DELAY_MS;
        break;

    case WM_MOUSEMOVE:
        if (m_lastMousePos != lParam)
        {
            m_lastMousePos = lParam;
            if (currentTime > m_pauseUntilTime)
                m_mouseActivity = true;
        }
        break;

    case WM_KEYDOWN:
		if (isInChatPage)
            break;
        if (currentTime > m_pauseUntilTime)
            m_keyboardActivity = true;
        break;

    case WM_LBUTTONDOWN:
    case WM_RBUTTONDOWN:
    case WM_MBUTTONDOWN:
    case WM_XBUTTONDOWN:
    case WM_MOUSEWHEEL:
    case WM_MOUSEHWHEEL:
        if (currentTime > m_pauseUntilTime)
            m_mouseActivity = true;
        break;
    }
}

bool GamepadHotSwitch::InitializeXInput()
{
    const char* dlls[] =
    {
        "XInputUap.dll",
        "XInput1_4.dll",
        "XInput1_3.dll",
    };
    for (int i = 0; i < std::size(dlls); ++i)
    {
        m_hXInput = LoadLibraryA(dlls[i]);
        if (m_hXInput)
        {
            Log(std::format("[GamepadHotSwitch] XInput library {} loaded", dlls[i]));
            break;
        }
    }
    if (!m_hXInput)
    {
        Log("[GamepadHotSwitch] Failed to load XInput library");
        return false;
    }

    m_XInputGetKeystroke = (DWORD(WINAPI*)(DWORD, DWORD, PXINPUT_KEYSTROKE))GetProcAddress(m_hXInput, "XInputGetKeystroke");
    if (!m_XInputGetKeystroke)
    {
        FreeLibrary(m_hXInput);
        m_hXInput = nullptr;
        Log("[GamepadHotSwitch] Failed to get XInputGetKeystroke function");
        return false;
    }

    Log("[GamepadHotSwitch] XInput initialized");
    return true;
}

bool GamepadHotSwitch::IsXInputControllerActive() const
{
    if (!m_XInputGetKeystroke)
        return false;

    XINPUT_KEYSTROKE keystroke{};
    m_XInputGetKeystroke(XUSER_INDEX_ANY, 0, &keystroke);
    if (keystroke.VirtualKey != 0)
    {
        //Log(std::format("[GamepadHotSwitch] XInput VirtualKey:{:x} Flags:{} UserIndex:{}", keystroke.VirtualKey, keystroke.Flags, keystroke.UserIndex));
        return true;
    }
    
    return false;
}

bool GamepadHotSwitch::IsKeyboardActive()
{
    if (m_keyboardActivity)
    {
        m_keyboardActivity = false;
        return true;
    }
    return false;
}

bool GamepadHotSwitch::IsMouseActive()
{
    if (m_mouseActivity)
    {
        m_mouseActivity = false;
        return true;
    }
    return false;
}

void GamepadHotSwitch::SendSwitchMessage(bool toGamepad)
{
    if (isGamepadMode == toGamepad)
        return;

    isGamepadMode = toGamepad;

    HWND hWnd = GetUnityMainWindow();
    if (hWnd)
    {
        PostMessageW(hWnd,
            toGamepad ? WM_GAMEPAD_ACTIVATED : WM_MOUSE_ACTIVATED,
            (WPARAM)0, (LPARAM)0);
    }
}

void GamepadHotSwitch::MainThread()
{
    if (m_isExiting)
        return;

    Log("[GamepadHotSwitch] Main thread started");

    while (!m_isExiting)
    {
        ULONGLONG currentTime = GetTickCount64();
        if (!m_enabled || currentTime <= m_pauseUntilTime)
        {
            Sleep(2000);
            continue;
        }

        if (IsXInputControllerActive())
            m_lastGamepadActivityTime = currentTime;
        if (IsKeyboardActive() || IsMouseActive())
            m_lastKeyboardMouseActivityTime = currentTime;

        if (m_lastGamepadActivityTime > m_lastKeyboardMouseActivityTime + SWITCH_DELAY_MS)
            SendSwitchMessage(true);
        else if (m_lastKeyboardMouseActivityTime > m_lastGamepadActivityTime + SWITCH_DELAY_MS)
            SendSwitchMessage(false);

        Sleep(50);
    }

    Log("[GamepadHotSwitch] Main thread exiting");
}
