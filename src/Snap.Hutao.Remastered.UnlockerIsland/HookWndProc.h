#pragma once

#include <windows.h>
#include <string>

#define WM_GAMEPAD_ACTIVATED (WM_APP + 100)
#define WM_MOUSE_ACTIVATED   (WM_APP + 101)

LRESULT CALLBACK WindowSubclassProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData);

void HandleSwitchToGamepad();
void HandleSwitchToKeyboardMouse();

extern LPVOID switchInputDeviceToTouchScreen;
extern LPVOID switchInputDeviceToJoypad;

bool InstallWindowSubclass();
bool RemoveWindowSubclass();
void SetUnityMainWindow(HWND hWnd);
HWND GetUnityMainWindow();
void InitializeWndProcHooks();
HWND FindUnityMainWindow();
BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam);
