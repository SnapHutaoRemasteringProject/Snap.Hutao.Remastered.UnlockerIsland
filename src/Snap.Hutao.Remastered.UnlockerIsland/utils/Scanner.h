#pragma once

#include <string>
#include <Windows.h>

namespace Scanner
{
    /// Scans the game module for the given byte pattern and returns
    /// the virtual address of the first match, or nullptr on failure.
    void* Scan(const std::string& signature);

    /// Resolves a relative CALL/JMP target.
    /// @param instruction  address of the instruction (scan result)
    /// @param offset       byte offset from instruction start to the relative operand (default 1)
    /// @param instrSize    total instruction length in bytes (default 5)
    /// @return the absolute target address of the relative jump/call
    void* ResolveRelative(void* instruction, int offset = 1, int instrSize = 5);

    /// Resolves a relative 32-bit value embedded at a fixed offset from the
    /// scanned address and converts it to a module-relative offset.
    /// Used for derived data offsets (e.g. ClosePage, ResinList).
    /// @return the 32-bit value read at (scanResult + fieldOffset)
    DWORD ReadFieldOffset(void* scanResult, int fieldOffset);
}
