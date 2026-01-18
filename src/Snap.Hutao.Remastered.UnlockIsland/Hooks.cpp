#include "Hooks.h"
#include "HookEnvironment.h"
#include "HookFunctionOffsets.h"
#include "MemoryUtils.h"
#include "include/MinHook.h"
#include <cstdint>
#include <cstring>

// Get_FrameCount
static LPVOID originalGetFrameCount = nullptr;
// Set_FrameCount (Not hooked, just called)
static LPVOID originalSetFrameCount = nullptr;
// ChangeFOV
static LPVOID originalSetFov = nullptr;
// DisplayFog
static LPVOID originalDisplayFog = nullptr;
// Player_Perspective
static LPVOID originalPlayerPerspective = nullptr;
// Touch Screen
static LPVOID switchInputDeviceToTouchScreen = nullptr;

// Quest Banner
static LPVOID originalSetupQuestBanner = nullptr;
static LPVOID findGameObject = nullptr;
static LPVOID setActive = nullptr;

// Event Camera
static LPVOID originalEventCameraMove = nullptr;

// Damage Text
static LPVOID originalShowOneDamageTextEx = nullptr;

// Craft Redirect
static LPVOID findString = nullptr;
static LPVOID craftEntryPartner = nullptr;
static LPVOID originalCraftEntry = nullptr;

// Team Anime
static LPVOID checkCanEnter = nullptr;
static LPVOID openTeamPageAccordingly = nullptr;
static LPVOID originalOpenTeam = nullptr;

// Global State
static bool gameUpdateInit = false;
static bool touchScreenInit = false;
// Flag to request opening the craft menu from the main thread
static bool requestOpenCraft = false;

// Fake Fog Struct for alignment (64 bytes)
struct FakeFogStruct {
    alignas(16) uint8_t data[64];
};
static FakeFogStruct fakeFogStruct;


// typedef int(*HookGet_FrameCount_t)();
typedef int(__stdcall* GetFrameCountFn)();

// typedef int(*Set_FrameCount_t)(int value);
typedef int(__stdcall* SetFrameCountFn)(int);

// typedef int(*HookChangeFOV_t)(__int64 a1, float a2);
typedef int(__stdcall* SetFovFn)(void*, float);

// typedef void (*SwitchInputDeviceToTouchScreen_t)(void*);
typedef void(__stdcall* SwitchInputDeviceToTouchScreenFn)(void*);

// Quest Banner Types
// typedef void (*SetupQuestBanner_t)(void*);
typedef void(__stdcall* SetupQuestBannerFn)(void*);
// typedef void* (*FindGameObject_t)(Il2CppString*);
typedef void*(__stdcall* FindGameObjectFn)(void*);
// typedef void (*SetActive_t)(void*, bool);
typedef void(__stdcall* SetActiveFn)(void*, bool);

// Event Camera Types
// typedef bool (*EventCameraMove_t)(void*, void*);
typedef bool(__stdcall* EventCameraMoveFn)(void*, void*);

// Damage Text Types
// typedef void (*ShowOneDamageTextEx_t)(void*, int, int, int, float, Il2CppString*, void*, void*, int);
typedef void(__stdcall* ShowOneDamageTextExFn)(void*, int, int, int, float, void*, void*, void*, int);

// typedef int(*HookDisplayFog_t)(__int64 a1, __int64 a2);
typedef int(__stdcall* DisplayFogFn)(void*, void*);

// typedef void* (*HookPlayer_Perspective_t)(void* RCX, float Display, void* R8);
typedef void*(__stdcall* PlayerPerspectiveFn)(void*, float, void*);

// Craft Redirect Types
// typedef Il2CppString* (*FindString_t)(const char*);
typedef void*(__stdcall* FindStringFn)(const char*);

// typedef void (*CraftEntry_t)(void*);
typedef void(__stdcall* CraftEntryFn)(void*);

// typedef bool (*CraftEntryPartner_t)(Il2CppString*, void*, void*, void*, void*);
typedef bool(__stdcall* CraftEntryPartnerFn)(void*, void*, void*, void*, void*);

// Team Anime Types
// typedef bool(*CheckCanEnter_t)();
typedef bool(__stdcall* CheckCanEnterFn)();

// typedef void(*OpenTeam_t)();
typedef void(__stdcall* OpenTeamFn)();

// typedef void(*OpenTeamPageAccordingly_t)(bool);
typedef void(__stdcall* OpenTeamPageAccordinglyFn)(bool);


void RequestOpenCraft()
{
    requestOpenCraft = true;
}

static bool DoOpenCraftMenu()
{
    if (!findString || !craftEntryPartner)
    {
        return false;
    }

    FindStringFn findStringFunc = (FindStringFn)findString;
    CraftEntryPartnerFn craftEntryPartnerFunc = (CraftEntryPartnerFn)craftEntryPartner;

    // path to the global combine page
    const char* path = "SynthesisPage";
    void* strObj = findStringFunc(path);

    if (strObj)
    {
        // Invoke the page opener
        craftEntryPartnerFunc(strObj, nullptr, nullptr, nullptr, nullptr);
        return true;
    }

    return false;
}

static int __stdcall HookGetFrameCount()
{
    if (originalGetFrameCount)
    {
        GetFrameCountFn original = (GetFrameCountFn)originalGetFrameCount;
        int ret = original();
        if (ret >= 60)
        {
            return 60;
        }
        else if (ret >= 45)
        {
            return 45;
        }
        else if (ret >= 30)
        {
            return 30;
        }
        else
        {
            return ret;
        }
    }
    return 60;
}

static int __stdcall HookSetFov(void* a1, float changeFovValue)
{
    if (!gameUpdateInit)
    {
        gameUpdateInit = true;
    }

    // Check for craft menu request (Main Thread Execution)
    if (requestOpenCraft)
    {
        requestOpenCraft = false;
        // We don't care about the return value here, just do it
        DoOpenCraftMenu();
    }

    // Touch screen initialization (once)
    if (!touchScreenInit)
    {
        touchScreenInit = true;
        if (g_pEnv->TouchMode && switchInputDeviceToTouchScreen)
        {
            SwitchInputDeviceToTouchScreenFn switchInput = (SwitchInputDeviceToTouchScreenFn)switchInputDeviceToTouchScreen;
            __try
            {
                switchInput(nullptr);
            }
            __except (0)
            {
                // Ignore exceptions
            }
        }
    }

    // FPS override
    if (g_pEnv->EnableSetFps && originalSetFrameCount)
    {
        SetFrameCountFn setFrameCount = (SetFrameCountFn)originalSetFrameCount;
        setFrameCount(g_pEnv->TargetFps);
    }

    // FOV override
    if (changeFovValue > 30.0f && g_pEnv->EnableSetFov)
    {
        changeFovValue = g_pEnv->FieldOfView;
    }

    if (originalSetFov)
    {
        SetFovFn original = (SetFovFn)originalSetFov;
        return original(a1, changeFovValue);
    }
    return 0;
}

static int __stdcall HookDisplayFog(void* a1, void* a2)
{
    if (g_pEnv->DisableFog && a2)
    {
        // Copy memory from a2 to fakeFogStruct
        memcpy(fakeFogStruct.data, a2, 64);
        // Set first byte to 0
        fakeFogStruct.data[0] = 0;

        if (originalDisplayFog)
        {
            DisplayFogFn original = (DisplayFogFn)originalDisplayFog;
            return original(a1, &fakeFogStruct);
        }
    }

    if (originalDisplayFog)
    {
        DisplayFogFn original = (DisplayFogFn)originalDisplayFog;
        return original(a1, a2);
    }
    return 0;
}

static void* __stdcall HookPlayerPerspective(void* rcx, float display, void* r8)
{
    if (g_pEnv->FixLowFov)
    {
        display = 1.0f;
    }

    if (originalPlayerPerspective)
    {
        PlayerPerspectiveFn original = (PlayerPerspectiveFn)originalPlayerPerspective;
        return original(rcx, display, r8);
    }
    return nullptr;
}

// SetupQuestBanner hook (hides UID and quest banner)
static void __stdcall HookSetupQuestBanner(void* pThis)
{
    if (findString && findGameObject && setActive)
    {
        FindStringFn findStringFunc = (FindStringFn)findString;
        FindGameObjectFn findGameObjectFunc = (FindGameObjectFn)findGameObject;
        SetActiveFn setActiveFunc = (SetActiveFn)setActive;

        // Hide UID Logic
        if (g_pEnv->Uid != 0)
        {
            const char* uidPath = "/BetaWatermarkCanvas(Clone)/Panel/TxtUID";
            void* strObj = findStringFunc(uidPath);
            if (strObj)
            {
                void* uidObj = findGameObjectFunc(strObj);
                if (uidObj)
                {
                    setActiveFunc(uidObj, false);
                }
            }
        }

        // Hide Quest Banner Logic
        if (g_pEnv->HideQuestBanner)
        {
            const char* bannerPath = "Canvas/Pages/InLevelMapPage/GrpMap/GrpPointTips/Layout/QuestBanner";
            void* strObj = findStringFunc(bannerPath);
            if (strObj)
            {
                void* banner = findGameObjectFunc(strObj);
                if (banner)
                {
                    setActiveFunc(banner, false);
                    return;
                }
            }
        }
    }

    if (originalSetupQuestBanner)
    {
        SetupQuestBannerFn original = (SetupQuestBannerFn)originalSetupQuestBanner;
        original(pThis);
    }
}

static bool __stdcall HookEventCameraMove(void* pThis, void* event)
{
    if (g_pEnv->DisableCameraMove)
    {
        return true;
    }

    if (originalEventCameraMove)
    {
        EventCameraMoveFn original = (EventCameraMoveFn)originalEventCameraMove;
        return original(pThis, event);
    }
    return true;
}

static void __stdcall HookShowOneDamageTextEx(void* pThis, int type_, int damageType, int showType, float damage, void* showText, void* worldPos, void* attackee, int elementReactionType)
{
    if (g_pEnv->DisableDamageText)
    {
        return;
    }

    if (originalShowOneDamageTextEx)
    {
        ShowOneDamageTextExFn original = (ShowOneDamageTextExFn)originalShowOneDamageTextEx;
        original(pThis, type_, damageType, showType, damage, showText, worldPos, attackee, elementReactionType);
    }
}

static void __stdcall HookCraftEntry(void* pThis)
{
    // If redirect is enabled AND we successfully opened the menu via our helper
    if (g_pEnv->RedirectCombine && DoOpenCraftMenu())
    {
        // Return early, skipping the original tedious dialog
        return;
    }

    if (originalCraftEntry)
    {
        CraftEntryFn original = (CraftEntryFn)originalCraftEntry;
        original(pThis);
    }
}

static void __stdcall HookOpenTeam()
{
    if (g_pEnv->RemoveTeamProgress && checkCanEnter)
    {
        CheckCanEnterFn checkCanEnterFunc = (CheckCanEnterFn)checkCanEnter;
        if (checkCanEnterFunc())
        {
            if (openTeamPageAccordingly)
            {
                OpenTeamPageAccordinglyFn openTeamPageFunc = (OpenTeamPageAccordinglyFn)openTeamPageAccordingly;
                openTeamPageFunc(false);
                return;
            }
        }
    }

    if (originalOpenTeam)
    {
        OpenTeamFn original = (OpenTeamFn)originalOpenTeam;
        original();
    }
}

void SetupHooks()
{
    if (g_pEnv->Offsets.GetFps)
    {
        LPVOID getFrameCountAddr = GetFunctionAddress(g_pEnv->Offsets.GetFps);
        if (getFrameCountAddr)
        {
            MH_CreateHook(getFrameCountAddr, HookGetFrameCount, &originalGetFrameCount);
        }
    }

    if (g_pEnv->Offsets.SetFps)
    {
        originalSetFrameCount = GetFunctionAddress(g_pEnv->Offsets.SetFps);
    }

    if (g_pEnv->Offsets.SetFov)
    {
        LPVOID changeFovAddr = GetFunctionAddress(g_pEnv->Offsets.SetFov);
        if (changeFovAddr)
        {
            MH_CreateHook(changeFovAddr, HookSetFov, &originalSetFov);
        }
    }

    if (g_pEnv->Offsets.TouchInput)
    {
        switchInputDeviceToTouchScreen = GetFunctionAddress(g_pEnv->Offsets.TouchInput);
    }

    if (g_pEnv->Offsets.QuestBanner)
    {
        LPVOID setupQuestBannerAddr = GetFunctionAddress(g_pEnv->Offsets.QuestBanner);
        if (setupQuestBannerAddr)
        {
            MH_CreateHook(setupQuestBannerAddr, HookSetupQuestBanner, &originalSetupQuestBanner);
        }
    }

    if (g_pEnv->Offsets.FindObject)
    {
        findGameObject = GetFunctionAddress(g_pEnv->Offsets.FindObject);
    }

    if (g_pEnv->Offsets.ObjectActive)
    {
        setActive = GetFunctionAddress(g_pEnv->Offsets.ObjectActive);
    }

    if (g_pEnv->Offsets.CameraMove)
    {
        LPVOID eventCameraMoveAddr = GetFunctionAddress(g_pEnv->Offsets.CameraMove);
        if (eventCameraMoveAddr)
        {
            MH_CreateHook(eventCameraMoveAddr, HookEventCameraMove, &originalEventCameraMove);
        }
    }

    if (g_pEnv->Offsets.DamageText)
    {
        LPVOID showOneDamageTextExAddr = GetFunctionAddress(g_pEnv->Offsets.DamageText);
        if (showOneDamageTextExAddr)
        {
            MH_CreateHook(showOneDamageTextExAddr, HookShowOneDamageTextEx, &originalShowOneDamageTextEx);
        }
    }

    if (g_pEnv->Offsets.SetFog)
    {
        LPVOID displayFogAddr = GetFunctionAddress(g_pEnv->Offsets.SetFog);
        if (displayFogAddr)
        {
            MH_CreateHook(displayFogAddr, HookDisplayFog, &originalDisplayFog);
        }
    }

    if (g_pEnv->Offsets.PlayerPerspective)
    {
        LPVOID playerPerspectiveAddr = GetFunctionAddress(g_pEnv->Offsets.PlayerPerspective);
        if (playerPerspectiveAddr)
        {
            MH_CreateHook(playerPerspectiveAddr, HookPlayerPerspective, &originalPlayerPerspective);
        }
    }

    if (g_pEnv->Offsets.FindString)
    {
        findString = GetFunctionAddress(g_pEnv->Offsets.FindString);
    }

    if (g_pEnv->Offsets.CombineEntryPartner)
    {
        craftEntryPartner = GetFunctionAddress(g_pEnv->Offsets.CombineEntryPartner);
    }

    if (g_pEnv->Offsets.CombineEntry)
    {
        LPVOID craftEntryAddr = GetFunctionAddress(g_pEnv->Offsets.CombineEntry);
        if (craftEntryAddr)
        {
            MH_CreateHook(craftEntryAddr, HookCraftEntry, &originalCraftEntry);
        }
    }

    if (g_pEnv->Offsets.CheckEnter)
    {
        checkCanEnter = GetFunctionAddress(g_pEnv->Offsets.CheckEnter);
    }

    if (g_pEnv->Offsets.OpenTeamAdvanced)
    {
        openTeamPageAccordingly = GetFunctionAddress(g_pEnv->Offsets.OpenTeamAdvanced);
    }

    if (g_pEnv->Offsets.OpenTeam)
    {
        LPVOID openTeamAddr = GetFunctionAddress(g_pEnv->Offsets.OpenTeam);
        if (openTeamAddr)
        {
            MH_CreateHook(openTeamAddr, HookOpenTeam, &originalOpenTeam);
        }
    }
}
