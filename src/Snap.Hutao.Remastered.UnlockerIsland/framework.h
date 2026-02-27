#pragma once

#include "include/MinHook.h"
#include "HookEnvironment.h"
#include "Constants.h"
#include <Windows.h>

#pragma pack(push, 4)
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

enum class  DeviceType : int
{
    TouchScreen = 0,
    KeyboardWithTouchScreen = 1,
    KeyboardWithMouse = 2,
    Joypad = 3
};

typedef uintptr_t il2cpp_array_size_t;
typedef int32_t il2cpp_array_lower_bound_t;

typedef struct Il2CppArrayBounds
{
    il2cpp_array_size_t length;
    il2cpp_array_lower_bound_t lower_bound;
} Il2CppArrayBounds;

template<typename T> class Il2CppArray
{
    Il2CppObject obj;
    Il2CppArrayBounds* bounds;
    il2cpp_array_size_t max_length;
    T vector[32];

public:
    inline T Get(int index) {
        return vector[index];
    }

    inline void Set(int index, T value) {
        vector[index] = value;
    }

    inline void Remove(T value) {
        for (il2cpp_array_size_t i = 0; i < max_length; ++i) {
            if (vector[i] == value) {
                for (il2cpp_array_size_t j = i + 1; j < max_length; ++j) {
                    vector[j - 1] = vector[j];
                }

                --max_length;

                vector[max_length] = T();
                break;
            }
        }
    }

    inline il2cpp_array_size_t Count() {
        return max_length;
    }
};

template<typename T> class Il2CppList
{
    Il2CppObject obj;
    Il2CppArray<T>* array;
    int size;
    int version;

public:
    inline T Get(int index) {
        return array->Get(index);
    }

    inline void Set(int index, T value) {
        array->Set(index, value);
    }

    inline void Remove(T value) {
        array->Remove(value);

        size--;
        version++;
    }

    inline int Count() {
        return size;
    }
};
