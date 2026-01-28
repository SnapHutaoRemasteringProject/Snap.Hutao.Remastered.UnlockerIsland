#pragma once

#include <Windows.h> 
#include <Psapi.h>

#include <sstream>
#include <vector>
#include <string>

namespace Scanner {

    // 解析特征码字符串，如 "48 8B 05 ? ? ? ?"
    // 返回整数向量，其中-1表示通配符"?"
    std::vector<int> ParsePattern(const std::string& signature);

    void* ScanMainModule(const std::string& signature);

    void* ScanModule(const char* moduleName, const std::string& signature);

    // 在指定内存范围内扫描特征码
    // start: 起始地址
    // size: 内存大小
    void* ScanMemory(void* start, size_t size, const std::string& signature);
}
