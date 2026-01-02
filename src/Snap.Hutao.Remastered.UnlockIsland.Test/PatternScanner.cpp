#include "pch.h"
#include "PatternScanner.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <future>
#include <iomanip>

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
    WaitForSingleObject(hThread, INFINITE);
    DWORD exitCode = 0;
    GetExitCodeThread(hThread, &exitCode);
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

// Boyer-Moore-Horspool算法预处理函数
static void BuildBadCharTable(const std::vector<uint8_t>& pattern, const std::vector<bool>& mask, 
                             std::vector<size_t>& badCharShift, size_t& patternSize)
{
    patternSize = pattern.size();
    badCharShift.resize(256, patternSize);
    
    for (size_t i = 0; i < patternSize - 1; ++i)
    {
        if (mask[i])
        {
            badCharShift[pattern[i]] = patternSize - 1 - i;
        }
    }
}

// 优化的扫描函数，使用Boyer-Moore-Horspool算法
static bool PatternMatchBMH(const uint8_t* data, const std::vector<uint8_t>& pattern, 
                           const std::vector<bool>& mask, size_t patternSize)
{
    // 对于短模式，使用朴素算法
    if (patternSize <= 4)
    {
        for (size_t j = 0; j < patternSize; ++j)
        {
            if (mask[j] && data[j] != pattern[j])
            {
                return false;
            }
        }
        return true;
    }
    
    // 检查第一个和最后一个固定字节（如果存在）以快速排除
    size_t firstFixed = 0;
    while (firstFixed < patternSize && !mask[firstFixed]) firstFixed++;
    
    size_t lastFixed = patternSize - 1;
    while (lastFixed > firstFixed && !mask[lastFixed]) lastFixed--;
    
    if (firstFixed < patternSize && data[firstFixed] != pattern[firstFixed])
        return false;
    
    if (lastFixed > firstFixed && data[lastFixed] != pattern[lastFixed])
        return false;
    
    // 完整比较
    for (size_t j = 0; j < patternSize; ++j)
    {
        if (mask[j] && data[j] != pattern[j])
        {
            return false;
        }
    }
    return true;
}

// Multi-threaded scanning implementation
DWORD PatternScanner::ScanChunk(HANDLE hProcess, uintptr_t baseAddress, uintptr_t startOffset, 
                               uintptr_t endOffset, const std::vector<uint8_t>& patternBytes, 
                               const std::vector<bool>& patternMask, std::atomic<bool>* shouldStop)
{
    // 安全检查：确保参数有效
    if (!hProcess || hProcess == INVALID_HANDLE_VALUE || patternBytes.empty() || startOffset >= endOffset)
    {
        return 0;
    }

    // 大幅增加读取缓冲区大小，减少系统调用次数
    const size_t chunkSize = 1024 * 1024; // 1MB缓冲区，显著减少ReadProcessMemory调用
    std::vector<uint8_t> buffer(chunkSize);
    size_t patternSize = patternBytes.size();
    
    // 预处理Boyer-Moore-Horspool表
    std::vector<size_t> badCharShift;
    size_t actualPatternSize;
    BuildBadCharTable(patternBytes, patternMask, badCharShift, actualPatternSize);
    
    // 确保badCharShift表有效
    if (badCharShift.empty() || actualPatternSize == 0)
    {
        return 0;
    }

    // 计算实际需要扫描的范围
    uintptr_t actualEndOffset = endOffset;

    for (uintptr_t offset = startOffset; offset < actualEndOffset; )
    {
        // 检查是否需要提前终止
        if (shouldStop && shouldStop->load(std::memory_order_relaxed))
        {
            return 0;
        }

        // 确保读取大小有效
        if (actualEndOffset - offset == 0)
        {
            break;
        }

        size_t readSize = min(chunkSize, static_cast<size_t>(actualEndOffset - offset));
        
        // 确保readSize至少为patternSize，否则无法匹配
        if (readSize < patternSize)
        {
            break;
        }

        if (!ReadProcessMemorySafe(hProcess, baseAddress + offset, buffer.data(), readSize))
        {
            // 读取失败，跳过这个区域
            offset += chunkSize;
            continue;
        }

        // 使用Boyer-Moore-Horspool算法进行扫描
        size_t i = 0;
        while (i <= readSize - patternSize)
        {
            // 定期检查是否需要提前终止（每扫描4096字节检查一次）
            if (shouldStop && (i & 0xFFF) == 0 && shouldStop->load(std::memory_order_relaxed))
            {
                return 0;
            }
            
            // 检查最后一个字节（如果它是固定字节）
            size_t lastByteIdx = patternSize - 1;
            bool lastByteIsFixed = patternMask[lastByteIdx];
            
            if (!lastByteIsFixed || buffer[i + lastByteIdx] == patternBytes[lastByteIdx])
            {
                // 如果最后一个字节匹配或者是通配符，检查整个模式
                if (PatternMatchBMH(&buffer[i], patternBytes, patternMask, patternSize))
                {
                    return offset + i;
                }
            }
            
            // 根据坏字符表计算跳转距离，确保不会越界
            if (i + patternSize - 1 < readSize)
            {
                uint8_t badChar = buffer[i + patternSize - 1];
                size_t shift = badCharShift[badChar];
                
                // 确保shift至少为1，避免无限循环
                if (shift == 0)
                {
                    shift = 1;
                }
                
                i += shift;
            }
            else
            {
                // 如果越界，跳出循环
                break;
            }
        }

        // 确保偏移量向前移动，避免无限循环
        size_t advance = readSize - patternSize + 1;
        if (advance == 0)
        {
            advance = 1;
        }
        offset += advance;
    }

    return 0;
}

void PatternScanner::ScanWorker(const ScanTask& task)
{
    DWORD localResult = ScanChunk(task.hProcess, task.baseAddress, 
                                 task.startOffset, task.endOffset,
                                 *task.patternBytes, *task.patternMask, nullptr);
    
    if (localResult != 0)
    {
        std::lock_guard<std::mutex> lock(*task.resultMutex);
        DWORD expected = 0;
        if (task.result->compare_exchange_strong(expected, localResult))
        {
            // Signal that we found a result
            task.cv->notify_all();
        }
    }
    
    // Decrement active thread count
    (*task.activeThreads)--;
    if (*task.activeThreads == 0)
    {
        task.cv->notify_all();
    }
}

DWORD PatternScanner::ScanPatternInModuleMultiThreaded(HANDLE hProcess, const std::wstring& moduleName, 
                                                      const std::string& pattern, int threadCount)
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
        std::cerr << "Pattern parsing failed or pattern is empty" << std::endl;
        return 0;
    }

    uintptr_t baseAddress = reinterpret_cast<uintptr_t>(me.modBaseAddr);
    DWORD moduleSize = me.modBaseSize;

    // 优化：对于小模块，使用单线程
    if (moduleSize < 1024 * 1024) // 小于1MB的模块
    {
        std::cout << "Using single-threaded scan for small module" << std::endl;
        return ScanPatternInModule(hProcess, moduleName, pattern);
    }

    if (threadCount <= 0)
    {
        SYSTEM_INFO sysInfo;
        GetSystemInfo(&sysInfo);
        threadCount = sysInfo.dwNumberOfProcessors;
    }
    
    if (threadCount > 32) threadCount = 32;
    
    uintptr_t minChunkSize = 4 * 1024 * 1024; // 最小4MB每个线程，减少线程间切换
    uintptr_t chunkSize = moduleSize / threadCount;
    
    if (chunkSize < minChunkSize)
    {
        chunkSize = minChunkSize;
        threadCount = static_cast<int>(moduleSize / chunkSize);
        if (threadCount < 1) threadCount = 1;
        if (threadCount > 32) threadCount = 32; // 重新限制
    }

    std::atomic<bool> shouldStop(false);
    std::atomic<DWORD> finalResult(0);
    std::vector<std::thread> threads;
    
    for (int i = 0; i < threadCount; ++i)
    {
        uintptr_t startOffset = i * chunkSize;
        uintptr_t endOffset = (i == threadCount - 1) ? moduleSize : (i + 1) * chunkSize;
        
        threads.emplace_back([hProcess, baseAddress, startOffset, endOffset, 
                             &patternBytes, &patternMask, &shouldStop, &finalResult]() {
            DWORD localResult = ScanChunk(hProcess, baseAddress, startOffset, endOffset, 
                                         patternBytes, patternMask, &shouldStop);
            
            if (localResult != 0)
            {
                DWORD expected = 0;
                if (finalResult.compare_exchange_strong(expected, localResult, 
                                                       std::memory_order_relaxed, 
                                                       std::memory_order_relaxed))
                {
                    // 第一个找到结果的线程设置停止标志
                    shouldStop.store(true, std::memory_order_relaxed);
                    std::cout << "Found match at offset: 0x" << std::hex << localResult << std::dec << std::endl;
                }
            }
        });
    }

    // 等待所有线程完成
    for (auto& thread : threads)
    {
        if (thread.joinable())
        {
            thread.join();
        }
    }

    DWORD result = finalResult.load();
    if (result == 0)
    {
        std::cout << "No match found for pattern" << std::endl;
    }
    
    return result;
}
