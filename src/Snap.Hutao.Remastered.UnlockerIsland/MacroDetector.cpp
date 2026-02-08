#include "MacroDetector.h"
#include <iostream>
#include <commctrl.h>

static MacroDetector g_macroDetector;

LRESULT CALLBACK MacroDetector::WindowSubclassProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, UINT_PTR uIdSubclass, DWORD_PTR dwRefData)
{
    MacroDetector* pDetector = reinterpret_cast<MacroDetector*>(dwRefData);
    
    if (uMsg == WM_LBUTTONDOWN || uMsg == WM_RBUTTONDOWN)
    {
        if (pDetector)
        {
            pDetector->RecordClick();
        }
    }

    return DefSubclassProc(hWnd, uMsg, wParam, lParam);
}

MacroDetector::MacroDetector() 
    : m_hUnityWindow(nullptr)
{

}

MacroDetector::~MacroDetector()
{
    RemoveWindowSubclass();
}

MacroDetector& MacroDetector::GetInstance()
{
    return g_macroDetector;
}

void MacroDetector::Initialize()
{
    FindUnityMainWindow();
    
    if (m_hUnityWindow)
    {
        std::cout << "[MacroDetector] Found Unity main window: " << m_hUnityWindow << std::endl;

        CreateThread(NULL, 0, [](LPVOID _) -> DWORD 
        {
            while (true) {
                Sleep(1000);
                MacroDetector::GetInstance().Update();
            }
        }, 0, 0, NULL);
        
        if (InstallWindowSubclass())
        {
            std::cout << "[MacroDetector] Window subclass installed successfully" << std::endl;
        }
        else
        {
            std::cout << "[MacroDetector] Failed to install window subclass" << std::endl;
        }
    }
    else
    {
        std::cout << "[MacroDetector] Unity main window not found" << std::endl;
    }
}

void MacroDetector::RecordClick()
{
    auto now = std::chrono::steady_clock::now();
    m_clickTimes.push(now);
    
    auto cutoff = now - m_timeWindow;
    while (!m_clickTimes.empty() && m_clickTimes.front() < cutoff)
    {
        m_clickTimes.pop();
    }
}

bool MacroDetector::IsOverCpsLimit() const
{
    auto now = std::chrono::steady_clock::now();
    auto cutoff = now - m_timeWindow;
    
    std::queue<std::chrono::steady_clock::time_point> tempQueue = m_clickTimes;
    while (!tempQueue.empty() && tempQueue.front() < cutoff)
    {
        tempQueue.pop();
    }
    
    bool overLimit = tempQueue.size() >= m_maxClicksPerSecond;
    
    return overLimit;
}

double MacroDetector::GetCurrentCps() const
{
    auto now = std::chrono::steady_clock::now();
    auto cutoff = now - m_timeWindow;
    
    std::queue<std::chrono::steady_clock::time_point> tempQueue = m_clickTimes;
    while (!tempQueue.empty() && tempQueue.front() < cutoff)
    {
        tempQueue.pop();
    }
    
    double cps = static_cast<double>(tempQueue.size());

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

DWORD MacroDetector::ShowLimitedMessageThread(LPVOID _)
{
    MessageBoxW(g_macroDetector.m_hUnityWindow, L"检测到进入千星奇域关卡 解锁功能已被限制", L"警告", MB_ICONWARNING);
    return 0;
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
    if (!m_clickTimes.empty())
    {
        auto now = std::chrono::steady_clock::now();
        auto cutoff = now - m_timeWindow;
        
        while (!m_clickTimes.empty() && m_clickTimes.front() < cutoff)
        {
            m_clickTimes.pop();
        }
    }
    
    if (!m_hUnityWindow)
    {
        FindUnityMainWindow();
        
        if (m_hUnityWindow && !m_subclassInstalled)
        {
            if (InstallWindowSubclass())
            {
                std::cout << "[MacroDetector] Window subclass installed in Update()" << std::endl;
            }
        }
    }
    
    if (!warned && IsOverCpsLimit())
    {
        warned = true;
        CreateThread(NULL, 0, ShowMessageThread, 0, 0, NULL);
    }
}

void MacroDetector::ShowLimitedMessage()
{
    CreateThread(NULL, 0, ShowLimitedMessageThread, 0, 0, NULL);
}

bool MacroDetector::InstallWindowSubclass()
{
    if (!m_hUnityWindow || m_subclassInstalled)
    {
        return false;
    }
    
    // Use SetWindowSubclass for safer subclassing
    if (SetWindowSubclass(m_hUnityWindow, WindowSubclassProc, m_subclassId, reinterpret_cast<DWORD_PTR>(this)))
    {
        m_subclassInstalled = true;
        return true;
    }
    
    std::cout << "[MacroDetector] Failed to install window subclass: " << GetLastError() << std::endl;
    return false;
}

bool MacroDetector::RemoveWindowSubclass()
{
    if (!m_hUnityWindow || !m_subclassInstalled)
    {
        return false;
    }
    
    if (::RemoveWindowSubclass(m_hUnityWindow, WindowSubclassProc, m_subclassId))
    {
        m_subclassInstalled = false;
        return true;
    }
    
    std::cout << "[MacroDetector] Failed to remove window subclass: " << GetLastError() << std::endl;
    return false;
}
