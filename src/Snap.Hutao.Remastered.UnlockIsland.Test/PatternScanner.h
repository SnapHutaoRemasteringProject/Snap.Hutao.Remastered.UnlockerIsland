#pragma once

#include <Windows.h>
#include <TlHelp32.h>
#include <vector>
#include <string>
#include <cstdint>
#include <thread>
#include <atomic>
#include <mutex>
#include <condition_variable>

class PatternScanner
{
public:
    static HANDLE OpenProcessHandle(const std::wstring& processName);
    static DWORD ScanPatternInModule(HANDLE hProcess, const std::wstring& moduleName, const std::string& pattern);
    
    // Multi-threaded scanning
    static DWORD ScanPatternInModuleMultiThreaded(HANDLE hProcess, const std::wstring& moduleName, 
                                                 const std::string& pattern, int threadCount = 4);
    
    // Convert pattern string to byte array and mask
    static void ParsePattern(const std::string& pattern, std::vector<uint8_t>& bytes, std::vector<bool>& mask);
    
    // DLL injection related methods
    static bool InjectDLL(HANDLE hProcess, const std::wstring& dllPath);
    static bool IsDLLAlreadyInjected(HANDLE hProcess, const std::wstring& dllName);

private:
    static bool ReadProcessMemorySafe(HANDLE hProcess, uintptr_t address, void* buffer, size_t size);
    static MODULEENTRY32W GetModuleEntry(HANDLE hProcess, const std::wstring& moduleName);
    
    // Multi-threaded scanning helper structures and functions
    struct ScanTask {
        HANDLE hProcess;
        uintptr_t baseAddress;
        uintptr_t startOffset;
        uintptr_t endOffset;
        const std::vector<uint8_t>* patternBytes;
        const std::vector<bool>* patternMask;
        std::atomic<DWORD>* result;
        std::atomic<int>* activeThreads;
        std::mutex* resultMutex;
        std::condition_variable* cv;
    };
    
    static void ScanWorker(const ScanTask& task);
    static DWORD ScanChunk(HANDLE hProcess, uintptr_t baseAddress, uintptr_t startOffset, 
                          uintptr_t endOffset, const std::vector<uint8_t>& patternBytes, 
                          const std::vector<bool>& patternMask, std::atomic<bool>* shouldStop = nullptr);
};
