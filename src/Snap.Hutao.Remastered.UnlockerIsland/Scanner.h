#pragma once

#include <Windows.h> 
#include <Psapi.h>

#include <sstream>
#include <vector>
#include <string>

namespace Scanner {

    std::vector<int> ParsePattern(const std::string& signature);

    void* ScanMainModule(const std::string& signature);

    void* ScanModule(const char* moduleName, const std::string& signature);

    void* ScanMemory(void* start, size_t size, const std::string& signature);

    void* ResolveRelative(void* instruction, int offset, int instrSize);
}
