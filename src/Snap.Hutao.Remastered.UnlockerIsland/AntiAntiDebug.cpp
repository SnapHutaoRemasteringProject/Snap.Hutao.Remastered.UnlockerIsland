#include "AntiAntiDebug.h"
#include "MinHook.h"
#include <Windows.h>

// Define types if not already defined
typedef long NTSTATUS;
#define NTAPI __stdcall

// ThreadHideFromDebugger = 0x11
#define ThreadHideFromDebugger 0x11

// Original function pointers
static NTSTATUS (NTAPI *OriginalNtQueryInformationThread)(
    HANDLE ThreadHandle,
    DWORD ThreadInformationClass,  // Using DWORD instead of THREADINFOCLASS
    PVOID ThreadInformation,
    ULONG ThreadInformationLength,
    PULONG ReturnLength
) = nullptr;

static NTSTATUS (NTAPI *OriginalNtSetInformationThread)(
    HANDLE ThreadHandle,
    DWORD ThreadInformationClass,  // Using DWORD instead of THREADINFOCLASS
    PVOID ThreadInformation,
    ULONG ThreadInformationLength
) = nullptr;

// Hook functions
NTSTATUS NTAPI HookNtQueryInformationThread(
    HANDLE ThreadHandle,
    DWORD ThreadInformationClass,
    PVOID ThreadInformation,
    ULONG ThreadInformationLength,
    PULONG ReturnLength
)
{
    // Check if querying ThreadHideFromDebugger
    if (ThreadInformationClass == ThreadHideFromDebugger && 
        ThreadInformation != nullptr && 
        ThreadInformationLength >= sizeof(ULONG))
    {
        // Return 0 (not hidden) to bypass anti-debug check
        *((PULONG)ThreadInformation) = 0;
        if (ReturnLength != nullptr) {
            *ReturnLength = sizeof(ULONG);
        }
        return 0; // STATUS_SUCCESS
    }
    
    // For other queries, call original function
    return OriginalNtQueryInformationThread(
        ThreadHandle, 
        ThreadInformationClass, 
        ThreadInformation, 
        ThreadInformationLength, 
        ReturnLength
    );
}

NTSTATUS NTAPI HookNtSetInformationThread(
    HANDLE ThreadHandle,
    DWORD ThreadInformationClass,
    PVOID ThreadInformation,
    ULONG ThreadInformationLength
)
{
    // Check if trying to set ThreadHideFromDebugger
    if (ThreadInformationClass == ThreadHideFromDebugger)
    {
        // Block the call and return success to bypass anti-debug
        return 0; // STATUS_SUCCESS
    }
    
    // For other operations, call original function
    return OriginalNtSetInformationThread(
        ThreadHandle, 
        ThreadInformationClass, 
        ThreadInformation, 
        ThreadInformationLength
    );
}

void SetupAntiAntiDebugHooks()
{
    HMODULE ntdll = GetModuleHandleA("ntdll.dll");
    
    // Hook NtQueryInformationThread
    OriginalNtQueryInformationThread = (decltype(OriginalNtQueryInformationThread))GetProcAddress(
        ntdll, "NtQueryInformationThread");
    if (OriginalNtQueryInformationThread)
    {
        MH_CreateHook(OriginalNtQueryInformationThread, HookNtQueryInformationThread, 
                     (LPVOID*)&OriginalNtQueryInformationThread);
    }
    
    // Hook NtSetInformationThread
    OriginalNtSetInformationThread = (decltype(OriginalNtSetInformationThread))GetProcAddress(
        ntdll, "NtSetInformationThread");
    if (OriginalNtSetInformationThread)
    {
        MH_CreateHook(OriginalNtSetInformationThread, HookNtSetInformationThread, 
                     (LPVOID*)&OriginalNtSetInformationThread);
    }
}
