#include "Scanner.h"

#include <Windows.h>
#include <Psapi.h>
#include <sstream>
#include <vector>
#include <iostream>

namespace Scanner {

    std::vector<int> ParsePattern(const std::string& signature) {
        std::vector<int> pattern;
        std::stringstream ss(signature);
        std::string word;
        
        while (ss >> word) {
            if (word == "?" || word == "??") {
                pattern.push_back(-1);
            }
            else {
                try {
                    pattern.push_back(std::stoi(word, nullptr, 16));
                }
                catch (...) {
                    // 转换失败时当作通配符处理
                    pattern.push_back(-1);
                }
            }
        }
        
        return pattern;
    }
    
    void* ScanMainModule(const std::string& signature) {
        return ScanModule(nullptr, signature);
    }

    void* ScanModule(const char* moduleName, const std::string& signature) {
        HMODULE hModule = nullptr;
        
        if (moduleName == nullptr) {
            hModule = GetModuleHandle(nullptr);
        }
        else {
            hModule = GetModuleHandleA(moduleName);
        }
        
        if (!hModule) {
            return nullptr;
        }

        MODULEINFO modInfo = { 0 };
        if (!GetModuleInformation(GetCurrentProcess(), hModule, &modInfo, sizeof(MODULEINFO))) {
            return nullptr;
        }

        auto pattern = ParsePattern(signature);
        if (pattern.empty()) {
            return nullptr;
        }

        uintptr_t startAddr = (uintptr_t)modInfo.lpBaseOfDll;
        uintptr_t endAddr = startAddr + modInfo.SizeOfImage;
        
        return ScanMemory((void*)startAddr, modInfo.SizeOfImage, signature);
    }

    void* ScanMemory(void* start, size_t size, const std::string& signature) {
        if (!start || size == 0) {
            return nullptr;
        }

        auto pattern = ParsePattern(signature);
        if (pattern.empty()) {
            return nullptr;
        }

        uintptr_t startAddr = (uintptr_t)start;
        uintptr_t endAddr = startAddr + size;
        uintptr_t current = startAddr;
        
        MEMORY_BASIC_INFORMATION mbi;
        while (current < endAddr) {
            if (VirtualQuery((LPCVOID)current, &mbi, sizeof(mbi)) == 0) {
                break;
            }
            
            bool isAvailable = (mbi.State == MEM_COMMIT) &&
                          ((mbi.Protect & PAGE_EXECUTE_READ) || 
                           (mbi.Protect & PAGE_EXECUTE_READWRITE) || 
                           (mbi.Protect & PAGE_READONLY) || 
                           (mbi.Protect & PAGE_READWRITE));

            if (isAvailable) {
                size_t regionSize = mbi.RegionSize;
                uintptr_t regionEnd = (uintptr_t)mbi.BaseAddress + regionSize;
                
                if (regionEnd > endAddr) {
                    regionSize = endAddr - (uintptr_t)mbi.BaseAddress;
                }
                
                const uint8_t* pStart = (const uint8_t*)mbi.BaseAddress;
                const size_t pSize = pattern.size();

                for (size_t i = 0; i <= regionSize - pSize; ++i) {
                    bool found = true;
                    
                    for (size_t j = 0; j < pSize; ++j) {
                        if (pattern[j] != -1 && pattern[j] != pStart[i + j]) {
                            found = false;
                            break;
                        }
                    }
                    
                    if (found) {
                        return (void*)(pStart + i);
                    }
                }
            }
            
            current = (uintptr_t)mbi.BaseAddress + mbi.RegionSize;
        }

        return nullptr;
    }
}
