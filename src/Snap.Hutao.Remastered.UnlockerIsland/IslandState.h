#pragma once
#include <Windows.h>

enum class IslandState : DWORD
{
    None = 0,
    Error = 1,
    Started = 2,
    Stopped = 3,
};