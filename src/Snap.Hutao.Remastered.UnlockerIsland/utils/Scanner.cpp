#include "Scanner.h"
#include "../utils/MemoryUtils.h"
#include <Psapi.h>
#include <sstream>
#include <vector>
#include <inttypes.h>

namespace Scanner
{
    // ------------------------------------------------------------------
    // Internal helpers
    // ------------------------------------------------------------------

    static std::vector<int> ParsePattern(const std::string& signature)
    {
        std::vector<int> pattern;
        std::stringstream ss(signature);
        std::string word;
        while (ss >> word)
        {
            if (word == "?" || word == "??")
                pattern.push_back(-1);
            else
            {
                try { pattern.push_back(std::stoi(word, nullptr, 16)); }
                catch (...) { pattern.push_back(-1); }
            }
        }
        return pattern;
    }

    // ------------------------------------------------------------------
    // Public API
    // ------------------------------------------------------------------

    void* Scan(const std::string& signature)
    {
        if (signature.empty())
            return nullptr;

        auto pattern = ParsePattern(signature);
        if (pattern.empty())
            return nullptr;

        // Ensure the game module handle is available
        if (g_hModule == NULL)
        {
            InitializeModuleHandle();
            if (g_hModule == NULL)
                return nullptr;
        }

        MODULEINFO modInfo = { 0 };
        if (!GetModuleInformation(GetCurrentProcess(), g_hModule, &modInfo, sizeof(modInfo)))
            return nullptr;

        const uintptr_t startAddr = (uintptr_t)modInfo.lpBaseOfDll;
        const uintptr_t endAddr = startAddr + modInfo.SizeOfImage;
        const size_t pSize = pattern.size();

        uintptr_t current = startAddr;

        while (current < endAddr)
        {
            MEMORY_BASIC_INFORMATION mbi = {};
            if (!VirtualQuery((LPCVOID)current, &mbi, sizeof(mbi)))
                break;

            const bool isGood = (mbi.State == MEM_COMMIT) &&
                                ((mbi.Protect & PAGE_GUARD) == 0) &&
                                (mbi.Protect & (PAGE_EXECUTE_READ |
                                                PAGE_EXECUTE_READWRITE |
                                                PAGE_READWRITE |
                                                PAGE_READONLY));

            if (isGood)
            {
                size_t regionSize = mbi.RegionSize;
                if ((uintptr_t)mbi.BaseAddress + regionSize > endAddr)
                    regionSize = endAddr - (uintptr_t)mbi.BaseAddress;

                if (regionSize >= pSize)
                {
                    const uint8_t* pStart = (const uint8_t*)mbi.BaseAddress;
                    for (size_t i = 0; i <= regionSize - pSize; ++i)
                    {
                        bool found = true;
                        for (size_t j = 0; j < pSize; ++j)
                        {
                            if (pattern[j] != -1 && pattern[j] != pStart[i + j])
                            {
                                found = false;
                                break;
                            }
                        }
                        if (found)
                            return (void*)(pStart + i);
                    }
                }
            }

            const uintptr_t nextAddr = (uintptr_t)mbi.BaseAddress + mbi.RegionSize;
            if (nextAddr <= current)
                break;
            current = nextAddr;
        }

        return nullptr;
    }

    void* ResolveRelative(void* instruction, int offset, int instrSize)
    {
        if (!instruction)
            return nullptr;

        __try
        {
            const uintptr_t instrAddr = (uintptr_t)instruction;
            const int32_t relative = *(int32_t*)(instrAddr + offset);
            return (void*)(instrAddr + instrSize + relative);
        }
        __except (EXCEPTION_EXECUTE_HANDLER)
        {
            return nullptr;
        }
    }

    DWORD ReadFieldOffset(void* scanResult, int fieldOffset)
    {
        if (!scanResult)
            return 0;

        __try
        {
            return *(DWORD*)((uintptr_t)scanResult + fieldOffset);
        }
        __except (EXCEPTION_EXECUTE_HANDLER)
        {
            return 0;
        }
    }
}
