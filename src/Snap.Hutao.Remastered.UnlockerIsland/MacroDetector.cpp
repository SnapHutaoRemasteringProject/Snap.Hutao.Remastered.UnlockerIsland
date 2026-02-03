#include "MacroDetector.h"
#include <iostream>

static MacroDetector g_macroDetector;
static HHOOK g_mouseHook = nullptr;

static LRESULT CALLBACK MouseHookProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode >= 0)
    {
        if (wParam == WM_LBUTTONDOWN || wParam == WM_RBUTTONDOWN)
        {
            MacroDetector::GetInstance().RecordClick();
        }
    }
    
    return CallNextHookEx(g_mouseHook, nCode, wParam, lParam);
}

MacroDetector::MacroDetector() 
    : m_hUnityWindow(nullptr)
{
    InitializeCriticalSection(&m_cs);
}

MacroDetector::~MacroDetector()
{
    // 卸载鼠标钩子
    if (g_mouseHook)
    {
        UnhookWindowsHookEx(g_mouseHook);
        g_mouseHook = nullptr;
    }
    
    DeleteCriticalSection(&m_cs);
}

MacroDetector& MacroDetector::GetInstance()
{
    return g_macroDetector;
}

void MacroDetector::Initialize()
{
    g_mouseHook = SetWindowsHookEx(WH_MOUSE_LL, MouseHookProc, GetModuleHandle(NULL), 0);
    if (g_mouseHook)
    {
        std::cout << "[MacroDetector] Mouse hook installed successfully" << std::endl;
    }
    else
    {
        std::cout << "[MacroDetector] Failed to install mouse hook: " << GetLastError() << std::endl;
    }
    
    FindUnityMainWindow();
    
    if (m_hUnityWindow)
    {
        std::cout << "[MacroDetector] Found Unity main window: " << m_hUnityWindow << std::endl;
    }
    else
    {
        std::cout << "[MacroDetector] Unity main window not found" << std::endl;
    }
}

void MacroDetector::RecordClick()
{
    EnterCriticalSection(&m_cs);
    
    auto now = std::chrono::steady_clock::now();
    m_clickTimes.push(now);
    
    auto cutoff = now - m_timeWindow;
    while (!m_clickTimes.empty() && m_clickTimes.front() < cutoff)
    {
        m_clickTimes.pop();
    }
    
    LeaveCriticalSection(&m_cs);
}

bool MacroDetector::IsOverCpsLimit() const
{
    EnterCriticalSection(&m_cs);
    
    auto now = std::chrono::steady_clock::now();
    auto cutoff = now - m_timeWindow;
    
    std::queue<std::chrono::steady_clock::time_point> tempQueue = m_clickTimes;
    while (!tempQueue.empty() && tempQueue.front() < cutoff)
    {
        tempQueue.pop();
    }
    
    bool overLimit = tempQueue.size() >= m_maxClicksPerSecond;
    
    LeaveCriticalSection(&m_cs);
    
    return overLimit;
}

double MacroDetector::GetCurrentCps() const
{
    EnterCriticalSection(&m_cs);
    
    auto now = std::chrono::steady_clock::now();
    auto cutoff = now - m_timeWindow;
    
    std::queue<std::chrono::steady_clock::time_point> tempQueue = m_clickTimes;
    while (!tempQueue.empty() && tempQueue.front() < cutoff)
    {
        tempQueue.pop();
    }
    
    double cps = static_cast<double>(tempQueue.size());
    
    LeaveCriticalSection(&m_cs);
    
    return cps;
}

HWND MacroDetector::GetUnityMainWindow() const
{
    return m_hUnityWindow;
}

void MacroDetector::SetUnityMainWindow(HWND hWnd)
{
    m_hUnityWindow = hWnd;
}

BOOL CALLBACK MacroDetector::EnumWindowsProc(HWND hWnd, LPARAM lParam)
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

DWORD MacroDetector::ShowMessageThread(LPVOID _)
{
    CreateThread(NULL, 0, CrashThread, 0, 0, NULL);
    MessageBoxW(g_macroDetector.m_hUnityWindow, L"Illegal tool detected, please restart the machine.\nError Code:(6,2,1)", L"错误", MB_ICONERROR);
    ExitProcess(-1);
}

DWORD MacroDetector::CrashThread(LPVOID _)
{
    Sleep(1000 * 10);
    ExitProcess(-1);
}

HWND MacroDetector::FindUnityMainWindow()
{
    HWND result = nullptr;
    EnumWindows(EnumWindowsProc, reinterpret_cast<LPARAM>(&result));
    
    if (result)
    {
        m_hUnityWindow = result;
    }
    
    return result;
}

void MacroDetector::Update()
{
    EnterCriticalSection(&m_cs);
    
    if (!m_clickTimes.empty())
    {
        auto now = std::chrono::steady_clock::now();
        auto cutoff = now - m_timeWindow;
        
        while (!m_clickTimes.empty() && m_clickTimes.front() < cutoff)
        {
            m_clickTimes.pop();
        }
    }
    
    LeaveCriticalSection(&m_cs);
    
    if (!m_hUnityWindow)
    {
        FindUnityMainWindow();
    }
    
    if (!warned && IsOverCpsLimit())
    {
        warned = true;
        CreateThread(NULL, 0, ShowMessageThread, 0, 0, NULL);
    }
}
