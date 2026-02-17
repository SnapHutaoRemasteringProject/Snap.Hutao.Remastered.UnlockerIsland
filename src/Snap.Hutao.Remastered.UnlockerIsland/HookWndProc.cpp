#include "HookWndProc.h"
#include "MacroDetector.h"
#include "GamepadHotSwitch.h"
#include "Logger.h" 
#include <commctrl.h>

static HWND g_hUnityWindow = nullptr;
static bool g_subclassInstalled = false;
static UINT_PTR g_subclassId = 1;

extern LPVOID switchInputDeviceToTouchScreen;
extern LPVOID switchInputDeviceToKeboardMouse;
extern LPVOID switchInputDeviceToJoypad;

LRESULT CALLBACK WindowSubclassProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData)
{
    if (uMsg == WM_LBUTTONDOWN || uMsg == WM_RBUTTONDOWN)
    {
        MacroDetector::GetInstance().RecordClick();
    }
    
    switch (uMsg)
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
        if (GamepadHotSwitch::GetInstance().IsEnabled())
        {
            GamepadHotSwitch::GetInstance().ProcessWindowMessage(uMsg, wParam, lParam);
        }
        break;
        

    case WM_GAMEPAD_ACTIVATED:
        HandleSwitchToGamepad();
        return 0;
        
    case WM_MOUSE_ACTIVATED:
        HandleSwitchToKeyboardMouse();
        return 0;
    }
    
    return DefSubclassProc(hWnd, uMsg, wParam, lParam);
}

void HandleSwitchToGamepad()
{
    if (switchInputDeviceToJoypad)
    {
        typedef void(*SwitchInputDeviceToJoypadFn)(void*);
        SwitchInputDeviceToJoypadFn switchInput = (SwitchInputDeviceToJoypadFn)switchInputDeviceToJoypad;
        
        __try
        {
            Log("[HookWndProc] Switched to gamepad input");
            switchInput(nullptr);
        }
        __except (EXCEPTION_EXECUTE_HANDLER)
        {

        }
    }
    else
    {
        Log("[HookWndProc] switchInputDeviceToJoypad function not available");
    }
}

void HandleSwitchToKeyboardMouse()
{
    if (switchInputDeviceToTouchScreen)
    {
        typedef void(*SwitchInputDeviceToKeyboardMouseFn)(void*);
        SwitchInputDeviceToKeyboardMouseFn switchInput = (SwitchInputDeviceToKeyboardMouseFn)switchInputDeviceToKeboardMouse;
        
        __try
        {
            Log("[HookWndProc] Switched to keyboard/mouse input");
            switchInput(nullptr);
        }
        __except (EXCEPTION_EXECUTE_HANDLER)
        {
        }
    }
    else
    {
        Log("[HookWndProc] switchInputDeviceToTouchScreen function not available");
    }
}
 
bool InstallWindowSubclass()
{
    if (!g_hUnityWindow || g_subclassInstalled)
    {
        return false;
    }
    
    if (SetWindowSubclass(g_hUnityWindow, WindowSubclassProc, g_subclassId, 0))
    {
        g_subclassInstalled = true;
        Log("[HookWndProc] Window subclass installed successfully");
        return true;
    }
    
    DWORD error = GetLastError();
    char buffer[256];
    snprintf(buffer, sizeof(buffer), "[HookWndProc] Failed to install window subclass: %lu", error);
    Log(buffer);
    return false;
}

bool RemoveWindowSubclass()
{
    if (!g_hUnityWindow || !g_subclassInstalled)
    {
        return false;
    }
    
    if (::RemoveWindowSubclass(g_hUnityWindow, WindowSubclassProc, g_subclassId))
    {
        g_subclassInstalled = false;
        Log("[HookWndProc] Window subclass removed successfully");
        return true;
    }
    
    DWORD error = GetLastError();
    char buffer[256];
    snprintf(buffer, sizeof(buffer), "[HookWndProc] Failed to remove window subclass: %lu", error);
    Log(buffer);
    return false;
}

void SetUnityMainWindow(HWND hWnd)
{
    if (g_hUnityWindow != hWnd)
    {
        if (g_subclassInstalled)
        {
            RemoveWindowSubclass();
        }
        
        g_hUnityWindow = hWnd;
        
        if (g_hUnityWindow)
        {
            InstallWindowSubclass();
        }
    }
}

HWND GetUnityMainWindow()
{
    return g_hUnityWindow;
}

void InitializeWndProcHooks()
{
    HWND hWnd = FindUnityMainWindow();
    if (hWnd)
    {
        SetUnityMainWindow(hWnd);
    }
    else
    {
        Log("[HookWndProc] Unity main window not found during initialization");
    }
}

HWND FindUnityMainWindow()
{
    HWND result = nullptr;
    EnumWindows(EnumWindowsProc, reinterpret_cast<LPARAM>(&result));
    return result;
}

BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam)
{
    if (!IsWindowVisible(hWnd))
        return TRUE;
    
    wchar_t className[256];
    GetClassNameW(hWnd, className, 256);
    
    std::wstring classNameStr(className);
    if (classNameStr.find(L"Unity") != std::wstring::npos)
    {
        wchar_t windowTitle[256];
        GetWindowTextW(hWnd, windowTitle, 256);
        if (wcslen(windowTitle) > 0)
        {
            HWND* pResult = reinterpret_cast<HWND*>(lParam);
            *pResult = hWnd;
            return FALSE;
        }
    }
    return TRUE;
}
