#pragma once

#include <windows.h>
#include <Xinput.h>
#include <atomic>
#include <thread>

class GamepadHotSwitch
{
public:
    static GamepadHotSwitch& GetInstance();

    bool Initialize();
    
    void Shutdown();
    
    void SetEnabled(bool enabled);
    
    bool IsEnabled() const;
    
    void ProcessWindowMessage(UINT msg, WPARAM wParam, LPARAM lParam);

private:
    GamepadHotSwitch();
    ~GamepadHotSwitch();
    
    GamepadHotSwitch(const GamepadHotSwitch&) = delete;
    GamepadHotSwitch& operator=(const GamepadHotSwitch&) = delete;
    
    void MainThread();
    
    bool IsControllerActive(const XINPUT_STATE& state) const;
    
    bool IsMouseActive() const;
    
    void SendSwitchMessage(bool toGamepad);

private:
    std::atomic<bool> m_isExiting{false};
    std::atomic<bool> m_enabled{false};
    
    HANDLE m_hThread{nullptr};
    
    HMODULE m_hXInput{nullptr};
    DWORD (WINAPI* m_XInputGetState)(DWORD, XINPUT_STATE*){nullptr};
    
    POINT m_lastMousePos{0, 0};
    ULONGLONG m_lastMouseTime = 0;
    std::atomic<ULONGLONG> m_lastMouseActivityTime{0};
    
    std::atomic<ULONGLONG> m_lastGamepadActivityTime{0};

	bool isGamepadMode = false;
    
    static constexpr DWORD SWITCH_DELAY_MS = 100;
    static constexpr DWORD MOUSE_INACTIVITY_THRESHOLD_MS = 2000;
    static constexpr DWORD GAMEPAD_INACTIVITY_THRESHOLD_MS = 3000;
    
    static constexpr BYTE TRIGGER_THRESHOLD = 30;
    static constexpr SHORT THUMB_L_THRESHOLD = 7849;
    static constexpr SHORT THUMB_R_THRESHOLD = 8689;
};
