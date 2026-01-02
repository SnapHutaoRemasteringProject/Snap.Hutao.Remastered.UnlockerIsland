#include "pch.h"
#include "PatternScanner.h"
#include <iostream>
#include <sstream>
#include <algorithm>

HANDLE PatternScanner::OpenProcessHandle(const std::wstring& processName)
{
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (hSnapshot == INVALID_HANDLE_VALUE)
    {
        std::wcerr << L"CreateToolhelp32Snapshot failed: " << GetLastError() << std::endl;
        return nullptr;
    }

    PROCESSENTRY32W pe;
    pe.dwSize = sizeof(PROCESSENTRY32W);

    if (!Process32FirstW(hSnapshot, &pe))
    {
        std::wcerr << L"Process32First failed: " << GetLastError() << std::endl;
        CloseHandle(hSnapshot);
        return nullptr;
    }

    DWORD pid = 0;
    do
    {
        if (processName == pe.szExeFile)
        {
            pid = pe.th32ProcessID;
            break;
        }
    } while (Process32NextW(hSnapshot, &pe));

    CloseHandle(hSnapshot);

    if (pid == 0)
    {
        std::wcerr << L"Process not found: " << processName << std::endl;
        return nullptr;
    }
    
    HANDLE hProcess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION |
        PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ,
        FALSE, pid);
    if (hProcess == nullptr)
    {
        std::wcerr << L"OpenProcess failed: " << GetLastError() << std::endl;
    }

    return hProcess;
}

MODULEENTRY32W PatternScanner::GetModuleEntry(HANDLE hProcess, const std::wstring& moduleName)
{
    MODULEENTRY32W me = { 0 };
    DWORD pid = GetProcessId(hProcess);
    if (pid == 0)
    {
        return me;
    }

    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, pid);
    if (hSnapshot == INVALID_HANDLE_VALUE)
    {
        return me;
    }

    me.dwSize = sizeof(MODULEENTRY32W);
    if (Module32FirstW(hSnapshot, &me))
    {
        do
        {
            if (moduleName == me.szModule)
            {
                CloseHandle(hSnapshot);
                return me;
            }
        } while (Module32NextW(hSnapshot, &me));
    }

    CloseHandle(hSnapshot);
    return { 0 };
}

bool PatternScanner::ReadProcessMemorySafe(HANDLE hProcess, uintptr_t address, void* buffer, size_t size)
{
    SIZE_T bytesRead = 0;
    return ReadProcessMemory(hProcess, reinterpret_cast<LPCVOID>(address), buffer, size, &bytesRead) && bytesRead == size;
}

void PatternScanner::ParsePattern(const std::string& pattern, std::vector<uint8_t>& bytes, std::vector<bool>& mask)
{
    bytes.clear();
    mask.clear();

    std::istringstream iss(pattern);
    std::string token;

    while (iss >> token)
    {
        if (token == "?" || token == "??")
        {
            bytes.push_back(0);
            mask.push_back(false); // wildcard
        }
        else
        {
            try
            {
                uint8_t byte = static_cast<uint8_t>(std::stoul(token, nullptr, 16));
                bytes.push_back(byte);
                mask.push_back(true); // fixed byte
            }
            catch (...)
            {
                // ignore invalid hex
            }
        }
    }
}

DWORD PatternScanner::ScanPatternInModule(HANDLE hProcess, const std::wstring& moduleName, const std::string& pattern)
{
    MODULEENTRY32W me = GetModuleEntry(hProcess, moduleName);
    if (me.modBaseAddr == 0)
    {
        std::wcerr << L"Module not found: " << moduleName << std::endl;
        return 0;
    }

    std::vector<uint8_t> patternBytes;
    std::vector<bool> patternMask;
    ParsePattern(pattern, patternBytes, patternMask);

    if (patternBytes.empty())
    {
        return 0;
    }

    uintptr_t baseAddress = reinterpret_cast<uintptr_t>(me.modBaseAddr);
    DWORD moduleSize = me.modBaseSize;

    const size_t chunkSize = 4096;
    std::vector<uint8_t> buffer(chunkSize);

    for (uintptr_t offset = 0; offset < moduleSize; offset += chunkSize - patternBytes.size())
    {
        size_t readSize = min(chunkSize, static_cast<size_t>(moduleSize - offset));
        if (!ReadProcessMemorySafe(hProcess, baseAddress + offset, buffer.data(), readSize))
        {
            continue;
        }

        for (size_t i = 0; i <= readSize - patternBytes.size(); ++i)
        {
            bool match = true;
            for (size_t j = 0; j < patternBytes.size(); ++j)
            {
                if (patternMask[j] && buffer[i + j] != patternBytes[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                return offset + i;
            }
        }
    }

    return 0;
}

bool PatternScanner::IsDLLAlreadyInjected(HANDLE hProcess, const std::wstring& dllName)
{
    DWORD pid = GetProcessId(hProcess);
    if (pid == 0)
    {
        return false;
    }

    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, pid);
    if (hSnapshot == INVALID_HANDLE_VALUE)
    {
        return false;
    }

    MODULEENTRY32W me;
    me.dwSize = sizeof(MODULEENTRY32W);
    
    if (Module32FirstW(hSnapshot, &me))
    {
        do
        {
            std::wstring currentModule(me.szModule);
            if (currentModule.find(dllName) != std::wstring::npos)
            {
                CloseHandle(hSnapshot);
                return true;
            }
        } while (Module32NextW(hSnapshot, &me));
    }

    CloseHandle(hSnapshot);
    return false;
}

// Inject DLL into target process
bool PatternScanner::InjectDLL(HANDLE hProcess, const std::wstring& dllPath)
{
    // First check if DLL is already injected
    std::wstring dllName = dllPath.substr(dllPath.find_last_of(L"\\/") + 1);
    if (IsDLLAlreadyInjected(hProcess, dllName))
    {
        std::wcout << L"DLL already injected: " << dllName << std::endl;
        return true;
    }

    // Get LoadLibraryW function address
    LPVOID loadLibraryAddr = reinterpret_cast<LPVOID>(GetProcAddress(GetModuleHandleW(L"kernel32.dll"), "LoadLibraryW"));
    if (loadLibraryAddr == nullptr)
    {
        std::wcerr << L"Failed to get LoadLibraryW address: " << GetLastError() << std::endl;
        return false;
    }

    // Allocate memory in target process for DLL path
    size_t pathSize = (dllPath.length() + 1) * sizeof(wchar_t);
    LPVOID remoteMemory = VirtualAllocEx(hProcess, nullptr, pathSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (remoteMemory == nullptr)
    {
        std::wcerr << L"Failed to allocate memory in target process: " << GetLastError() << std::endl;
        return false;
    }

    // Write DLL path to target process
    if (!WriteProcessMemory(hProcess, remoteMemory, dllPath.c_str(), pathSize, nullptr))
    {
        std::wcerr << L"Failed to write DLL path to target process: " << GetLastError() << std::endl;
        VirtualFreeEx(hProcess, remoteMemory, 0, MEM_RELEASE);
        return false;
    }

    // Create remote thread to call LoadLibraryW
    HANDLE hThread = CreateRemoteThread(hProcess, nullptr, 0,
        reinterpret_cast<LPTHREAD_START_ROUTINE>(loadLibraryAddr),
        remoteMemory, 0, nullptr);
    
    if (hThread == nullptr)
    {
        std::wcerr << L"Failed to create remote thread: " << GetLastError() << std::endl;
        VirtualFreeEx(hProcess, remoteMemory, 0, MEM_RELEASE);
        return false;
    }

    // Wait for thread to complete
    WaitForSingleObject(hThread, INFINITE);

    // Check thread exit code
    DWORD exitCode = 0;
    GetExitCodeThread(hThread, &exitCode);
    
    // Cleanup
    CloseHandle(hThread);
    VirtualFreeEx(hProcess, remoteMemory, 0, MEM_RELEASE);

    if (exitCode == 0)
    {
        std::wcerr << L"LoadLibraryW failed in target process" << std::endl;
        return false;
    }

    std::wcout << L"DLL injected successfully: " << dllName << std::endl;
    return true;
}
