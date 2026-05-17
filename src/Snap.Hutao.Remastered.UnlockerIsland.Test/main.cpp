#include "pch.h"
#include <iostream>
#include <filesystem>
#include <memory>
#include <vector>
#include <Windows.h>
#include <TlHelp32.h>

#include "../Snap.Hutao.Remastered.UnlockerIsland/HookEnvironment.h"

namespace fs = std::filesystem;

// ---------------------------------------------------------------------------
// RAII wrappers
// ---------------------------------------------------------------------------

struct HandleDeleter
{
    void operator()(HANDLE h) const noexcept
    {
        if (h && h != INVALID_HANDLE_VALUE)
            CloseHandle(h);
    }
};

using unique_handle = std::unique_ptr<std::remove_pointer_t<HANDLE>, HandleDeleter>;

// Custom deleter for remote-process memory allocations.
struct RemoteMemDeleter
{
    HANDLE hProcess;
    void operator()(void* p) const noexcept
    {
        if (p) VirtualFreeEx(hProcess, p, 0, MEM_RELEASE);
    }
};

// ---------------------------------------------------------------------------
// Constants
// ---------------------------------------------------------------------------

constexpr auto SharedMemName = L"4F3E8543-40F7-4808-82DC-21E48A6037A7";
constexpr auto TargetDllName = L"Snap.Hutao.Remastered.UnlockerIsland.dll";

// ---------------------------------------------------------------------------
// Game path resolution
// ---------------------------------------------------------------------------

static std::wstring FindGameExecutable()
{
    const std::vector<std::wstring> candidates = {
        L"C:\\Program Files\\Genshin Impact\\Genshin Impact Game\\YuanShen.exe",
        L"C:\\Program Files\\Genshin Impact\\Genshin Impact Game\\GenshinImpact.exe",
        L"D:\\Genshin Impact Game\\YuanShen.exe",
        L"D:\\Genshin Impact Game\\GenshinImpact.exe",
        L"E:\\Genshin Impact Game\\YuanShen.exe",
        L"E:\\Genshin Impact Game\\GenshinImpact.exe",
    };

    for (const auto& path : candidates)
    {
        if (fs::exists(path))
            return path;
    }
    return {};
}

// ---------------------------------------------------------------------------
// DLL path (relative to test exe)
// ---------------------------------------------------------------------------

static std::wstring GetDllPath(std::wstring_view dllName)
{
    wchar_t exePath[MAX_PATH];
    GetModuleFileNameW(nullptr, exePath, MAX_PATH);
    auto dllPath = fs::path(exePath).parent_path() / dllName;

    if (fs::exists(dllPath))
        return dllPath.wstring();

    std::wcerr << L"File not found: " << dllPath << std::endl;
    return {};
}

// ---------------------------------------------------------------------------
// Shared memory for HookEnvironment
// ---------------------------------------------------------------------------

struct SharedMemory
{
    HANDLE mapping = nullptr;
    HookEnvironment* env = nullptr;

    SharedMemory() = default;
    ~SharedMemory() { Cleanup(); }

    SharedMemory(const SharedMemory&) = delete;
    SharedMemory& operator=(const SharedMemory&) = delete;

    SharedMemory(SharedMemory&& other) noexcept
        : mapping(std::exchange(other.mapping, nullptr))
        , env(std::exchange(other.env, nullptr))
    {
    }

    SharedMemory& operator=(SharedMemory&& other) noexcept
    {
        if (this != &other)
        {
            Cleanup();
            mapping = std::exchange(other.mapping, nullptr);
            env = std::exchange(other.env, nullptr);
        }
        return *this;
    }

    [[nodiscard]] bool Create()
    {
        mapping = CreateFileMappingW(
            INVALID_HANDLE_VALUE, nullptr,
            PAGE_READWRITE, 0, sizeof(HookEnvironment),
            SharedMemName);

        if (!mapping)
        {
            std::wcerr << L"CreateFileMappingW failed: " << GetLastError() << std::endl;
            return false;
        }

        env = static_cast<HookEnvironment*>(
            MapViewOfFile(mapping, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(HookEnvironment)));

        if (!env)
        {
            std::wcerr << L"MapViewOfFile failed: " << GetLastError() << std::endl;
            Cleanup();
            return false;
        }

        return true;
    }

private:
    void Cleanup()
    {
        if (env)
        {
            UnmapViewOfFile(env);
            env = nullptr;
        }
        if (mapping)
        {
            CloseHandle(mapping);
            mapping = nullptr;
        }
    }
};

// ---------------------------------------------------------------------------
// Game launcher (suspended)
// ---------------------------------------------------------------------------

struct GameProcess
{
    unique_handle process;
    unique_handle mainThread;
    DWORD pid = 0;

    [[nodiscard]] static GameProcess LaunchSuspended(const std::wstring& gamePath)
    {
        GameProcess gp;
        STARTUPINFOW si = { sizeof(si) };
        PROCESS_INFORMATION pi = {};

        std::wstring cmdLine = L"\"" + gamePath + L"\"";

        if (!CreateProcessW(
                gamePath.c_str(), cmdLine.data(),
                nullptr, nullptr, FALSE, CREATE_SUSPENDED,
                nullptr, nullptr, &si, &pi))
        {
            std::wcerr << L"CreateProcessW failed: " << GetLastError() << std::endl;
            return gp;
        }

        gp.process.reset(pi.hProcess);
        gp.mainThread.reset(pi.hThread);
        gp.pid = pi.dwProcessId;

        std::wcout << L"Game started with PID: " << gp.pid << L" (suspended)" << std::endl;
        return gp;
    }

    explicit operator bool() const noexcept
    {
        return process != nullptr;
    }

    void Resume()
    {
        if (mainThread)
        {
            ResumeThread(mainThread.get());
            std::wcout << L"Game process resumed." << std::endl;
        }
    }
};

// ---------------------------------------------------------------------------
// DLL injection
// ---------------------------------------------------------------------------

static bool InjectDll(HANDLE hProcess, const std::wstring& dllPath)
{
    auto* loadLibraryAddr = reinterpret_cast<LPVOID>(
        GetProcAddress(GetModuleHandleW(L"kernel32.dll"), "LoadLibraryW"));

    if (!loadLibraryAddr)
    {
        std::wcerr << L"GetProcAddress(LoadLibraryW) failed: " << GetLastError() << std::endl;
        return false;
    }

    const size_t pathSize = (dllPath.size() + 1) * sizeof(wchar_t);

    std::unique_ptr<void, RemoteMemDeleter> remoteMem(
        VirtualAllocEx(hProcess, nullptr, pathSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE),
        RemoteMemDeleter{ hProcess });

    if (!remoteMem)
    {
        std::wcerr << L"VirtualAllocEx failed: " << GetLastError() << std::endl;
        return false;
    }

    if (!WriteProcessMemory(hProcess, remoteMem.get(), dllPath.c_str(), pathSize, nullptr))
    {
        std::wcerr << L"WriteProcessMemory failed: " << GetLastError() << std::endl;
        return false;
    }

    unique_handle hThread(CreateRemoteThread(
        hProcess, nullptr, 0,
        reinterpret_cast<LPTHREAD_START_ROUTINE>(loadLibraryAddr),
        remoteMem.get(), 0, nullptr));

    if (!hThread)
    {
        std::wcerr << L"CreateRemoteThread failed: " << GetLastError() << std::endl;
        return false;
    }

    WaitForSingleObject(hThread.get(), INFINITE);

    DWORD exitCode = 0;
    GetExitCodeThread(hThread.get(), &exitCode);

    if (exitCode == 0)
    {
        std::wcerr << L"LoadLibraryW returned 0 in target process" << std::endl;
        return false;
    }

    auto dllName = fs::path(dllPath).filename();
    std::wcout << L"DLL injected: " << dllName << std::endl;
    return true;
}

// ---------------------------------------------------------------------------
// HookEnvironment preset
// ---------------------------------------------------------------------------

static void ConfigureEnvironment(HookEnvironment& env)
{
    ZeroMemory(&env, sizeof(env));

    env.Size = sizeof(HookEnvironment);
    env.State = IslandState::None;

    // Feature flags
    env.DebugMode            = TRUE;
    env.EnableSetFov         = TRUE;
    env.FieldOfView          = 90.0f;
    env.DisablePlayerPerspective = TRUE;
    env.EnableSetFps         = TRUE;
    env.TargetFps            = 2000;
    env.RemoveTeamProgress   = TRUE;
    env.HideQuestBanner      = TRUE;
    env.DisableCameraMove    = TRUE;
    env.RedirectCombine      = TRUE;
    env.DisplayPaimon        = TRUE;
    env.HidePlayerInfo       = TRUE;
    env.HideGrass            = TRUE;
    env.GamepadHotSwitch     = TRUE;
    env.InLevelClockPageSpeedUp = TRUE;
    env.WeakMapCheck         = TRUE;
    env.CombineHotkey        = VK_F12;

    // Resin item overrides
    env.ResinItem000106 = TRUE;
    env.ResinItem107009 = TRUE;
    env.ResinItem107012 = TRUE;
    env.ResinItem220007 = TRUE;

    // Offsets
    env.Offsets.SetUid                   = 0xAC68570;
    env.Offsets.SetFov                   = 0x1560EC0;
    env.Offsets.SetFog                   = 0x15B73330;
    env.Offsets.GetFps                   = 0x106A3B0;
    env.Offsets.SetFps                   = 0x106A3C0;
    env.Offsets.OpenTeam                 = 0xE47E1B0;
    env.Offsets.OpenTeamAdvanced         = 0xE4851E0;
    env.Offsets.CheckEnter               = 0xFEAFC10;
    env.Offsets.QuestBanner              = 0xA98F410;
    env.Offsets.FindObject               = 0x15B625B0;
    env.Offsets.ObjectActive             = 0x1063450;
    env.Offsets.IsObjectActive           = 0x15B622E0;
    env.Offsets.CameraMove               = 0xFA87490;
    env.Offsets.DamageText               = 0x1084E9E0;
    env.Offsets.TouchInput               = 0x105C2C10;
    env.Offsets.KeyboardMouseInput       = 0xA2AF880;
    env.Offsets.JoypadInput              = 0x105AE050;
    env.Offsets.CombineEntry             = 0x69EA500;
    env.Offsets.CombineEntryPartner      = 0x9199950;
    env.Offsets.FindString               = 0x406330;
    env.Offsets.PlayerPerspective        = 0xD80FB50;
    env.Offsets.GameUpdate               = 0x15394C70;
    env.Offsets.ActorManagerCtor         = 0xD2D4EF0;
    env.Offsets.GetGlobalActor           = 0xD2CC9E0;
    env.Offsets.AvatarPaimonAppear       = 0x107BAC60;
    env.Offsets.GetComponent             = 0x15B61F60;
    env.Offsets.GetText                  = 0x15C45190;
    env.Offsets.GetName                  = 0x15B79680;
    env.Offsets.CheckCanOpenMap          = 0x69E9DD3;
}

// ---------------------------------------------------------------------------
// Main injection flow
// ---------------------------------------------------------------------------

static int Inject()
{
    // 1. Locate the game executable
    auto gamePath = FindGameExecutable();
    if (gamePath.empty())
    {
        std::wcerr << L"Game executable not found. "
                    << L"Adjust the candidate paths in FindGameExecutable()."
                    << std::endl;
        return 1;
    }

    // 2. Locate the target DLL
    auto dllPath = GetDllPath(TargetDllName);
    if (dllPath.empty())
        return 1;

    // 3. Launch game (suspended)
    auto game = GameProcess::LaunchSuspended(gamePath);
    if (!game)
        return 1;

    // 4. Create shared memory and initialise HookEnvironment
    SharedMemory sharedMem;
    if (!sharedMem.Create())
        return 1;

    ConfigureEnvironment(*sharedMem.env);

    // 5. Inject DLL
    if (!InjectDll(game.process.get(), dllPath))
    {
        std::wcerr << L"Injection failed." << std::endl;
        return 1;
    }

    // 6. Let the DLL initialise, then resume the game
    Sleep(2000);
    game.Resume();

    std::wcout << L"All done." << std::endl;
    return 0;
}

// ---------------------------------------------------------------------------
// Entry point
// ---------------------------------------------------------------------------

int main()
{
    return Inject();
}
