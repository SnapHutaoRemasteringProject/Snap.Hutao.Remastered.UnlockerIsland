#pragma once

#include "include/MinHook.h"
#include "HookEnvironment.h"
#include "Constants.h"
#include <Windows.h>

struct Il2CppObject {
    void* klass;
    void* monitor;
};

struct Il2CppString {
    Il2CppObject object;
    long length;
    wchar_t chars[1];
};

struct Color {
    float r;
    float g;
    float b;
    float a;
};