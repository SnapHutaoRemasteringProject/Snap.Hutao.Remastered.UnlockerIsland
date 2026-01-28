#include "Scanner.h"
#include <iostream>
#include <iomanip>

// Simple test function to verify Scanner functionality
void TestScanner() {
    std::cout << "=== Testing Signature Scanner ===" << std::endl;
    
    // Test 1: Parse pattern
    std::cout << "\nTest 1: Parse pattern" << std::endl;
    std::string testPattern = "48 8B 05 ? ? ? ? 85 C0 74 ? 48 8B 40 ?";
    auto pattern = Scanner::ParsePattern(testPattern);
    
    std::cout << "Pattern: " << testPattern << std::endl;
    std::cout << "Parsed result (" << pattern.size() << " bytes): ";
    for (size_t i = 0; i < pattern.size(); ++i) {
        if (pattern[i] == -1) {
            std::cout << "?? ";
        } else {
            std::cout << std::hex << std::setw(2) << std::setfill('0') << pattern[i] << " ";
        }
    }
    std::cout << std::dec << std::endl;
    
    // Test 2: Scan main module (this is just a demo, actual scan may need valid pattern)
    std::cout << "\nTest 2: Scan main module" << std::endl;
    // Use an unlikely pattern for testing
    std::string unlikelyPattern = "FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF";
    void* result = Scanner::ScanMainModule(unlikelyPattern);
    
    if (result == nullptr) {
        std::cout << "Scan result: No match found (as expected)" << std::endl;
    } else {
        std::cout << "Scan result: Found match at: " << result << std::endl;
    }
    
    // Test 3: Test ScanMemory function
    std::cout << "\nTest 3: Memory scan demo" << std::endl;
    // Create a test buffer
    unsigned char testBuffer[] = {0x48, 0x8B, 0x05, 0x12, 0x34, 0x56, 0x78, 0x90, 0xAB, 0xCD, 0xEF};
    std::string searchPattern = "48 8B 05 12 34 56 78";
    
    void* found = Scanner::ScanMemory(testBuffer, sizeof(testBuffer), searchPattern);
    if (found != nullptr) {
        std::cout << "Found pattern in test buffer" << std::endl;
        std::cout << "Offset: " << (static_cast<unsigned char*>(found) - testBuffer) << " bytes" << std::endl;
    } else {
        std::cout << "Pattern not found in test buffer" << std::endl;
    }
    
    // Test 4: Test ScanModule function
    std::cout << "\nTest 4: Module scan demo" << std::endl;
    // Try to scan the main module with a simple pattern
    std::string simplePattern = "CC"; // INT3 instruction (breakpoint)
    void* moduleResult = Scanner::ScanModule(nullptr, simplePattern);
    
    if (moduleResult == nullptr) {
        std::cout << "Module scan: No match found" << std::endl;
    } else {
        std::cout << "Module scan: Found match at: " << moduleResult << std::endl;
    }
    
    std::cout << "\n=== Test completed ===" << std::endl;
}

int main() {
    TestScanner();
    
    // Wait for user input
    std::cout << "\nPress Enter to exit..." << std::endl;
    std::cin.get();
    
    return 0;
}
