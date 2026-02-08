#pragma once

#include <Windows.h>
#include <queue>
#include <chrono>

class MacroDetector
{
public:
    static MacroDetector& GetInstance();

    MacroDetector();
    ~MacroDetector();

    void Initialize();
    void RecordClick();
    bool IsOverCpsLimit() const;
    double GetCurrentCps() const;
    HWND GetUnityMainWindow() const;
    void SetUnityMainWindow(HWND hWnd);
    HWND FindUnityMainWindow();
    void Update();

    static void ShowLimitedMessage();

private:
    MacroDetector(const MacroDetector&) = delete;
    MacroDetector& operator=(const MacroDetector&) = delete;

    static BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam);
    static DWORD WINAPI ShowMessageThread(LPVOID _);
    static DWORD WINAPI ShowLimitedMessageThread(LPVOID _);
    static DWORD WINAPI CrashThread(LPVOID _);
    
    // Window subclassing methods
    static LRESULT CALLBACK WindowSubclassProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData);
    bool InstallWindowSubclass();
    bool RemoveWindowSubclass();

private:
    HWND m_hUnityWindow;
    std::queue<std::chrono::steady_clock::time_point> m_clickTimes;
    const size_t m_maxClicksPerSecond = 30;
    const std::chrono::seconds m_timeWindow{1};
    bool warned = false;
    bool m_subclassInstalled = false;
    UINT_PTR m_subclassId = 1; // Arbitrary ID for our subclass
};
