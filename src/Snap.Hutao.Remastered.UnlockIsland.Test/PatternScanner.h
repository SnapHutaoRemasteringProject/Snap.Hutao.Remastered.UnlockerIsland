#pragma once

#include <Windows.h>
#include <TlHelp32.h>
#include <vector>
#include <string>
#include <cstdint>

class PatternScanner
{
public:
    static HANDLE OpenProcessHandle(const std::wstring& processName);
    static DWORD ScanPatternInModule(HANDLE hProcess, const std::wstring& moduleName, const std::string& pattern);
    // Convert pattern string to byte array and mask
    static void ParsePattern(const std::string& pattern, std::vector<uint8_t>& bytes, std::vector<bool>& mask);
    
    // DLL injection related methods
    static bool InjectDLL(HANDLE hProcess, const std::wstring& dllPath);
    static bool IsDLLAlreadyInjected(HANDLE hProcess, const std::wstring& dllName);

private:
    static bool ReadProcessMemorySafe(HANDLE hProcess, uintptr_t address, void* buffer, size_t size);
    static MODULEENTRY32W GetModuleEntry(HANDLE hProcess, const std::wstring& moduleName);
};
