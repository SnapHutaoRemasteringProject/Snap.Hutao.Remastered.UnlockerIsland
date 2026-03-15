#include "GamepadHotSwitch.h"
#include "HookWndProc.h"
#include "Logger.h"
#include <chrono>
#include <string>
#include <dinput.h>
#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

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
    
    // Initialize XInput
    m_hXInput = LoadLibraryW(L"XInput1_4.dll");
    if (!m_hXInput) m_hXInput = LoadLibraryW(L"XInput9_1_0.dll");
    if (!m_hXInput) m_hXInput = LoadLibraryW(L"XInput1_3.dll");
    
    if (m_hXInput)
    {
        m_XInputGetState = (DWORD(WINAPI*)(DWORD, XINPUT_STATE*))GetProcAddress(m_hXInput, "XInputGetState");
        if (!m_XInputGetState)
        {
            FreeLibrary(m_hXInput);
            m_hXInput = nullptr;
            Log("[GamepadHotSwitch] Failed to get XInputGetState function");
        }
        else
        {
            Log("[GamepadHotSwitch] XInput initialized successfully");
        }
    }
    else
    {
        Log("[GamepadHotSwitch] XInput library not available, continuing with DirectInput only");
    }
    
    // Initialize DirectInput for PS controllers
    if (!InitializeDirectInput())
    {
        Log("[GamepadHotSwitch] DirectInput initialization failed or no DirectInput devices found");
    }
    
    // If neither XInput nor DirectInput is available, log warning but continue
    if (!m_hXInput && m_directInputDevices.empty())
    {
        Log("[GamepadHotSwitch] Warning: No gamepad support available (XInput or DirectInput)");
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
        if (m_hXInput)
        {
            FreeLibrary(m_hXInput);
            m_hXInput = nullptr;
        }
        ShutdownDirectInput();
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
    
    ShutdownDirectInput();
    
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

bool GamepadHotSwitch::IsXInputControllerActive(const XINPUT_STATE& state) const
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
        
        // Check XInput controllers (Xbox)
        for (DWORD i = 0; i < XUSER_MAX_COUNT; ++i)
        {
            XINPUT_STATE state = {};
            if (m_XInputGetState && m_XInputGetState(i, &state) == ERROR_SUCCESS)
            {
                if (IsXInputControllerActive(state))
                {
                    anyGamepadActive = true;
                    m_lastGamepadActivityTime = GetTickCount64();
                    break;
                }
            }
        }
        
        // Check DirectInput controllers (PS controllers)
        if (!anyGamepadActive && IsDirectInputControllerActive())
        {
            anyGamepadActive = true;
            m_lastGamepadActivityTime = GetTickCount64();
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

// DirectInput callback for enumerating devices (static)
static BOOL CALLBACK EnumDirectInputDevicesCallback(LPCDIDEVICEINSTANCEW lpddi, LPVOID pvRef)
{
    GamepadHotSwitch* pThis = static_cast<GamepadHotSwitch*>(pvRef);
    return pThis->InitializeDirectInputDevice(lpddi);
}

bool GamepadHotSwitch::InitializeDirectInput()
{
    // Load dinput8.dll
    m_hDirectInput = LoadLibraryW(L"dinput8.dll");
    if (!m_hDirectInput)
    {
        Log("[GamepadHotSwitch] Failed to load dinput8.dll");
        return false;
    }
    
    // Get DirectInput8Create function
    typedef HRESULT(WINAPI* DirectInput8CreateFn)(HINSTANCE, DWORD, REFIID, LPVOID*, LPUNKNOWN);
    DirectInput8CreateFn pDirectInput8Create = (DirectInput8CreateFn)GetProcAddress(m_hDirectInput, "DirectInput8Create");
    
    if (!pDirectInput8Create)
    {
        FreeLibrary(m_hDirectInput);
        m_hDirectInput = nullptr;
        Log("[GamepadHotSwitch] Failed to get DirectInput8Create function");
        return false;
    }
    
    // Create DirectInput8 interface
    HRESULT hr = pDirectInput8Create(GetModuleHandle(nullptr), DIRECTINPUT_VERSION, 
                                      IID_IDirectInput8W, (LPVOID*)&m_pDirectInput, nullptr);
    if (FAILED(hr) || !m_pDirectInput)
    {
        FreeLibrary(m_hDirectInput);
        m_hDirectInput = nullptr;
        Log("[GamepadHotSwitch] Failed to create DirectInput8 interface");
        return false;
    }
    
    // Enumerate game controllers
    hr = m_pDirectInput->EnumDevices(DI8DEVCLASS_GAMECTRL, 
                                     EnumDirectInputDevicesCallback, 
                                     this, DIEDFL_ATTACHEDONLY);
    
    if (FAILED(hr))
    {
        Log("[GamepadHotSwitch] Failed to enumerate DirectInput devices");
        return false;
    }
    
    if (m_directInputDevices.empty())
    {
        Log("[GamepadHotSwitch] No DirectInput game controllers found");
        return false;
    }
    
    Log("[GamepadHotSwitch] DirectInput initialized with " + std::to_string(m_directInputDevices.size()) + " device(s)");
    return true;
}

BOOL GamepadHotSwitch::InitializeDirectInputDevice(LPCDIDEVICEINSTANCEW lpddi)
{
    if (!m_pDirectInput)
        return DIENUM_STOP;
    
    IDirectInputDevice8W* pDevice = nullptr;
    HRESULT hr = m_pDirectInput->CreateDevice(lpddi->guidInstance, &pDevice, nullptr);
    
    if (FAILED(hr) || !pDevice)
    {
        Log("[GamepadHotSwitch] Failed to create DirectInput device");
        return DIENUM_CONTINUE;
    }
    
    // Set data format
    hr = pDevice->SetDataFormat(&c_dfDIJoystick2);
    if (FAILED(hr))
    {
        pDevice->Release();
        Log("[GamepadHotSwitch] Failed to set data format for DirectInput device");
        return DIENUM_CONTINUE;
    }
    
    // Set cooperative level
    hr = pDevice->SetCooperativeLevel(nullptr, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND);
    if (FAILED(hr))
    {
        pDevice->Release();
        Log("[GamepadHotSwitch] Failed to set cooperative level for DirectInput device");
        return DIENUM_CONTINUE;
    }
    
    // Acquire the device
    hr = pDevice->Acquire();
    if (FAILED(hr))
    {
        pDevice->Release();
        Log("[GamepadHotSwitch] Failed to acquire DirectInput device");
        return DIENUM_CONTINUE;
    }
    
    m_directInputDevices.push_back(pDevice);
    
    // Convert wide string to UTF-8 for logging
    std::wstring deviceName = lpddi->tszProductName;
    int bufferSize = WideCharToMultiByte(CP_UTF8, 0, deviceName.c_str(), -1, nullptr, 0, nullptr, nullptr);
    if (bufferSize > 0)
    {
        std::string utf8DeviceName(bufferSize, 0);
        WideCharToMultiByte(CP_UTF8, 0, deviceName.c_str(), -1, &utf8DeviceName[0], bufferSize, nullptr, nullptr);
        Log("[GamepadHotSwitch] DirectInput device initialized: " + utf8DeviceName);
    }
    else
    {
        Log("[GamepadHotSwitch] DirectInput device initialized");
    }
    
    return DIENUM_CONTINUE;
}

void GamepadHotSwitch::ShutdownDirectInput()
{
    // Release all DirectInput devices
    for (auto* pDevice : m_directInputDevices)
    {
        if (pDevice)
        {
            pDevice->Unacquire();
            pDevice->Release();
        }
    }
    m_directInputDevices.clear();
    
    // Release DirectInput interface
    if (m_pDirectInput)
    {
        m_pDirectInput->Release();
        m_pDirectInput = nullptr;
    }
    
    // Free library
    if (m_hDirectInput)
    {
        FreeLibrary(m_hDirectInput);
        m_hDirectInput = nullptr;
    }
    
    Log("[GamepadHotSwitch] DirectInput shutdown");
}

bool GamepadHotSwitch::IsDirectInputDeviceActive(IDirectInputDevice8W* pDevice)
{
    if (!pDevice)
        return false;

    DIJOYSTATE2 state;
    HRESULT hr = pDevice->GetDeviceState(sizeof(DIJOYSTATE2), &state);

    if (FAILED(hr))
    {
        hr = pDevice->Acquire();
        if (SUCCEEDED(hr))
        {
            hr = pDevice->GetDeviceState(sizeof(DIJOYSTATE2), &state);
        }
        if (FAILED(hr))
            return false;
    }

    const LONG CENTER = 32768;

    if (abs(state.lX - CENTER) > THUMB_L_THRESHOLD ||
        abs(state.lY - CENTER) > THUMB_L_THRESHOLD)
        return true;

    if (abs(state.lZ - CENTER) > THUMB_R_THRESHOLD ||
        abs(state.lRz - CENTER) > THUMB_R_THRESHOLD)
        return true;

    const LONG TRIGGER_SCALED = (TRIGGER_THRESHOLD * 65535L) / 255L;
    if (state.lRx > TRIGGER_SCALED || state.lRy > TRIGGER_SCALED)
        return true;

    return false;
}

bool GamepadHotSwitch::IsDirectInputControllerActive()
{
    for (auto* pDevice : m_directInputDevices)
    {
        if (IsDirectInputDeviceActive(pDevice))
            return true;
    }
    return false;
}
