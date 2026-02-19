#include "GamepadHotSwitch.h"
#include "HookWndProc.h"
#include "Logger.h"
#include <chrono>
#include <string>

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
    
    m_hXInput = LoadLibraryW(L"XInput1_4.dll");
    if (!m_hXInput) m_hXInput = LoadLibraryW(L"XInput9_1_0.dll");
    if (!m_hXInput) m_hXInput = LoadLibraryW(L"XInput1_3.dll");
    
    if (!m_hXInput)
    {
        Log("[GamepadHotSwitch] Failed to load XInput library");
        return false;
    }
    
    m_XInputGetState = (DWORD(WINAPI*)(DWORD, XINPUT_STATE*))GetProcAddress(m_hXInput, "XInputGetState");
    if (!m_XInputGetState)
    {
        FreeLibrary(m_hXInput);
        m_hXInput = nullptr;
        Log("[GamepadHotSwitch] Failed to get XInputGetState function");
        return false;
    }
    
    GetCursorPos(&m_lastMousePos);
    m_lastMouseTime = GetTickCount64();
    m_lastMouseActivityTime = m_lastMouseTime;
    
    m_isExiting = false;
    m_hThread = CreateThread(nullptr, 0, [](LPVOID lpParam) -> DWORD {
        GamepadHotSwitch* pThis = static_cast<GamepadHotSwitch*>(lpParam);
        pThis->MainThread();
        return 0;
    }, this, 0, nullptr);
    
    if (!m_hThread)
    {
        FreeLibrary(m_hXInput);
        m_hXInput = nullptr;
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
        WaitForSingleObject(m_hThread, 1000);
        CloseHandle(m_hThread);
        m_hThread = nullptr;
    }
    
    if (m_hXInput)
    {
        FreeLibrary(m_hXInput);
        m_hXInput = nullptr;
        m_XInputGetState = nullptr;
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

bool GamepadHotSwitch::IsEnabled() const
{
    return m_enabled;
}

void GamepadHotSwitch::ProcessWindowMessage(UINT msg, WPARAM wParam, LPARAM lParam)
{
    if (!m_enabled)
        return;
    
    switch (msg)
    {
    case WM_MOUSEMOVE:
    case WM_LBUTTONDOWN:
    case WM_LBUTTONUP:
    case WM_RBUTTONDOWN:
    case WM_RBUTTONUP:
    case WM_MBUTTONDOWN:
    case WM_MBUTTONUP:
    case WM_MOUSEWHEEL:
    case WM_MOUSEHWHEEL:
        m_lastMouseActivityTime = GetTickCount64();
        break;
    }
}

bool GamepadHotSwitch::IsControllerActive(const XINPUT_STATE& state) const
{
    if (state.Gamepad.wButtons != 0)
        return true;
    
    if (state.Gamepad.bLeftTrigger > TRIGGER_THRESHOLD || 
        state.Gamepad.bRightTrigger > TRIGGER_THRESHOLD)
        return true;
    
    short lx = state.Gamepad.sThumbLX;
    short ly = state.Gamepad.sThumbLY;
    if (abs(lx) > THUMB_L_THRESHOLD || abs(ly) > THUMB_L_THRESHOLD)
        return true;
    
    short rx = state.Gamepad.sThumbRX;
    short ry = state.Gamepad.sThumbRY;
    if (abs(rx) > THUMB_R_THRESHOLD || abs(ry) > THUMB_R_THRESHOLD)
        return true;
    
    return false;
}

bool GamepadHotSwitch::IsMouseActive() const
{
    ULONGLONG currentTime = GetTickCount64();
    ULONGLONG lastActivity = m_lastMouseActivityTime.load();
    
    if (currentTime - lastActivity < MOUSE_INACTIVITY_THRESHOLD_MS)
    {
        return true;
    }
    
    POINT currentPos;
    GetCursorPos(&currentPos);
    
    if (currentPos.x != m_lastMousePos.x || currentPos.y != m_lastMousePos.y)
    {
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
        if (!m_enabled)
        {
            Sleep(100);
            continue;
        }
        
        bool anyGamepadActive = false;
        
        for (DWORD i = 0; i < XUSER_MAX_COUNT; ++i)
        {
            XINPUT_STATE state = {};
            if (m_XInputGetState && m_XInputGetState(i, &state) == ERROR_SUCCESS)
            {
                if (IsControllerActive(state))
                {
                    anyGamepadActive = true;
                    m_lastGamepadActivityTime = GetTickCount64();
                    break;
                }
            }
        }
        
        bool mouseCurrentlyActive = IsMouseActive();
        
        ULONGLONG currentTime = GetTickCount64();
        
        if (anyGamepadActive)
        {
            SendSwitchMessage(true);
        }
        else if (mouseCurrentlyActive)
        {
            if (currentTime - m_lastGamepadActivityTime > GAMEPAD_INACTIVITY_THRESHOLD_MS)
            {
                SendSwitchMessage(false);
            }
        }
        
        GetCursorPos(&m_lastMousePos);
        
        Sleep(50);
    }
    
    Log("[GamepadHotSwitch] Main thread exiting");
}
