#pragma once

#include <windows.h>
#include <Xinput.h>
#include <atomic>
#include <thread>
#include <vector>
#include <dinput.h>

// Forward declaration for DirectInput
struct IDirectInput8W;
struct IDirectInputDevice8W;

class GamepadHotSwitch
{
public:
    static GamepadHotSwitch& GetInstance();

    bool Initialize();
    
    void Shutdown();
    
    void SetEnabled(bool enabled);
    
    bool IsEnabled() const;
    
    void ProcessWindowMessage(UINT msg, WPARAM wParam, LPARAM lParam);
    
    // Public for static callback access
    BOOL InitializeDirectInputDevice(LPCDIDEVICEINSTANCEW lpddi);

private:
    GamepadHotSwitch();
    ~GamepadHotSwitch();
    
    GamepadHotSwitch(const GamepadHotSwitch&) = delete;
    GamepadHotSwitch& operator=(const GamepadHotSwitch&) = delete;
    
    void MainThread();
    
    bool IsXInputControllerActive(const XINPUT_STATE& state) const;
    bool IsDirectInputControllerActive();
    
    bool IsMouseActive() const;
    
    void SendSwitchMessage(bool toGamepad);
    
    bool InitializeDirectInput();
    void ShutdownDirectInput();
    bool IsDirectInputDeviceActive(IDirectInputDevice8W* pDevice);

private:
    std::atomic<bool> m_isExiting{false};
    std::atomic<bool> m_enabled{false};
    
    HANDLE m_hThread{nullptr};
    
    // XInput members
    HMODULE m_hXInput{nullptr};
    DWORD (WINAPI* m_XInputGetState)(DWORD, XINPUT_STATE*){nullptr};
    
    // DirectInput members
    HMODULE m_hDirectInput{nullptr};
    IDirectInput8W* m_pDirectInput{nullptr};
    std::vector<IDirectInputDevice8W*> m_directInputDevices;
    
    POINT m_lastMousePos{0, 0};
    ULONGLONG m_lastMouseTime = 0;
    std::atomic<ULONGLONG> m_lastMouseActivityTime{0};
    
    std::atomic<ULONGLONG> m_lastGamepadActivityTime{0};

	bool isGamepadMode = false;
    
    static constexpr DWORD SWITCH_DELAY_MS = 100;
    static constexpr DWORD MOUSE_INACTIVITY_THRESHOLD_MS = 2000;
    static constexpr DWORD GAMEPAD_INACTIVITY_THRESHOLD_MS = 2000;
    
    static constexpr BYTE TRIGGER_THRESHOLD = 30;
    static constexpr SHORT THUMB_L_THRESHOLD = 7849;
    static constexpr SHORT THUMB_R_THRESHOLD = 8689;
};
