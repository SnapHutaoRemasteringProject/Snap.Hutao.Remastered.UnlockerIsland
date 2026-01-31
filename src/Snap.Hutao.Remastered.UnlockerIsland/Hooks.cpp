#include "Hooks.h"
#include "framework.h"
#include "MemoryUtils.h"
#include <cstring>
#include <iostream>

// Get_FrameCount
static LPVOID originalGetFrameCount = nullptr;
// Set_FrameCount (Not hooked, just called)
static LPVOID setFrameCount = nullptr;
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
static LPVOID ptrToStringAnsi = nullptr;
static LPVOID craftEntryPartner = nullptr;
static LPVOID originalCraftEntry = nullptr;

// Team Anime
static LPVOID checkCanEnter = nullptr;
static LPVOID openTeamPageAccordingly = nullptr;
static LPVOID originalOpenTeam = nullptr;

static LPVOID originalGameUpdate = nullptr;

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

// Paimon Display
static LPVOID getActive = nullptr;

// Hide PlayerProfile
static LPVOID getPlayerID = nullptr;
static LPVOID setText = nullptr;
static void* monoInLevelPlayerProfilePageV3 = nullptr;
static LPVOID originalMonoInLevelPlayerProfilePageV3Ctor = nullptr;
static LPVOID getPlayerName = nullptr;

// Resin
static LPVOID originalSetupResinList = nullptr;

// Paimon Display
static LPVOID originalActorManagerCtor = nullptr;
static void* actorManager = nullptr;
static LPVOID getGlobalActor = nullptr;
static LPVOID resumePaimonInProfilePageAll = nullptr;
static LPVOID avatarPaimonAppear = nullptr;

// typedef int(*HookGet_FrameCount_t)();
typedef int(* GetFrameCountFn)();

// typedef int(*Set_FrameCount_t)(int value);
typedef int(* SetFrameCountFn)(int);

// typedef int(*HookChangeFOV_t)(__int64 a1, float a2);
typedef int(* SetFovFn)(void*, float);

// typedef void (*SwitchInputDeviceToTouchScreen_t)(void*);
typedef void(* SwitchInputDeviceToTouchScreenFn)(void*);

// Quest Banner Types
// typedef void (*SetupQuestBanner_t)(void*);
typedef void(* SetupQuestBannerFn)(void*);
// typedef void* (*FindGameObject_t)(Il2CppString*);
typedef void*(* FindGameObjectFn)(void*);
// typedef void (*SetActive_t)(void*, bool);
typedef void(* SetActiveFn)(void*, bool);
// typedef bool (*GetActive_t)(void*);
typedef bool(*GetActiveFn)(void*);

// Event Camera Types
// typedef bool (*EventCameraMove_t)(void*, void*);
typedef bool(* EventCameraMoveFn)(void*, void*);

// Damage Text Types
// typedef void (*ShowOneDamageTextEx_t)(void*, int, int, int, float, Il2CppString*, void*, void*, int);
typedef void(* ShowOneDamageTextExFn)(void*, int, int, int, float, Il2CppString*, void*, void*, int);

// typedef int(*HookDisplayFog_t)(__int64 a1, __int64 a2);
typedef int(* DisplayFogFn)(void*, void*);

// typedef void* (*HookPlayer_Perspective_t)(void* RCX, float Display, void* R8);
typedef void*(* PlayerPerspectiveFn)(void*, float, void*);

// Craft Redirect Types
// typedef Il2CppString* (*FindString_t)(const char*);
typedef Il2CppString*(* FindStringFn)(const char*);
typedef Il2CppString* (*PtrToStringAnsiFn)(const char*);

// typedef void (*CraftEntry_t)(void*);
typedef void(* CraftEntryFn)(void*);

// typedef bool (*CraftEntryPartner_t)(Il2CppString*, void*, void*, void*, void*);
typedef bool(* CraftEntryPartnerFn)(Il2CppString*, void*, void*, void*, void*);

// Team Anime Types
// typedef bool(*CheckCanEnter_t)();
typedef bool(* CheckCanEnterFn)();

// typedef void(*OpenTeam_t)();
typedef void(* OpenTeamFn)();

// typedef void(*OpenTeamPageAccordingly_t)(bool);
typedef void(* OpenTeamPageAccordinglyFn)(bool);

typedef void(* UpdateFn)(void*);
typedef void(* SetTextFn)(void*, Il2CppString*);
typedef void*(* GetPlayerIDFn)(void*);
typedef void*(* GetPlayerNameFn)(void*);
typedef void(* CtorFn)(void*);

// Paimon Display
typedef void*(*GetGlobalActorFn)(void*);
typedef void(*ResumePaimonInProfilePageAll)(void*);
typedef void(*AvatarPaimonAppearFn)(void*, void*, bool);

void HandlePaimon() {
    if (!findString || !findGameObject || !setActive || !getActive)
    {
        return;
    }

    FindStringFn findStringFunc = (FindStringFn)findString;
    FindGameObjectFn findGameObjectFunc = (FindGameObjectFn)findGameObject;
    SetActiveFn setActiveFunc = (SetActiveFn)setActive;
    GetActiveFn getActiveFunc = (GetActiveFn)getActive;

    if (g_pEnv->DisplayPaimon)
    {
        Il2CppString* paimonStrObj = findStringFunc(PAIMON_PATH);
        Il2CppString* profileLayerStrObj = findStringFunc(PROFILE_LAYER_PATH);

        if (paimonStrObj && profileLayerStrObj)
        {
            void* paimonObj = findGameObjectFunc(paimonStrObj);
			void* profileLayerObj = findGameObjectFunc(profileLayerStrObj);

            if (paimonObj && profileLayerObj)
            {
				bool profileOpen = getActiveFunc(profileLayerObj);

                if (profileOpen) {
                    setActiveFunc(paimonObj, false);
                }
                else {
                    setActiveFunc(paimonObj, true);
                }
            }
        }
    }
}

void HandlePaimonV2() {
    if (!g_pEnv->DisplayPaimon) {
        return;
    }

    if (!getGlobalActor || !resumePaimonInProfilePageAll || !getActive || !findString || !findGameObject || !avatarPaimonAppear) {
        return;
    }

    if (!actorManager) {
        return;
    }

    GetGlobalActorFn getGlobalActorFunc = (GetGlobalActorFn)getGlobalActor;
    GetActiveFn getActiveFunc = (GetActiveFn)getActive;
    FindStringFn findStringFunc = (FindStringFn)findString;
    FindGameObjectFn findGameObjectFunc = (FindGameObjectFn)findGameObject;
    Il2CppString* paimonStrObj = findStringFunc(PAIMON_PATH);
    Il2CppString* beydPaimonStrObj = findStringFunc(BEYD_PAIMON_PATH);

	if (!paimonStrObj || !beydPaimonStrObj) {
        return;
    }

	void* paimonObj = findGameObjectFunc(paimonStrObj);
	void* beydPaimonObj = findGameObjectFunc(beydPaimonStrObj);

    if (!paimonObj && !beydPaimonObj) {
        return;
	}

    if (getActiveFunc(paimonObj) || getActiveFunc(beydPaimonObj)) {
        return;
    }

    void* globalActor = getGlobalActorFunc(actorManager);

    if (globalActor) {
        AvatarPaimonAppearFn avatarPaimonAppearFunc = (AvatarPaimonAppearFn)avatarPaimonAppear;
        avatarPaimonAppearFunc(globalActor, nullptr, true);
	}
}

void HandlePlayerInfo() {
    if (!g_pEnv->HidePlayerInfo) {
        return;
    }

    if (!findString || !findGameObject || !setActive || !getActive || !setText ||!ptrToStringAnsi || !getPlayerName) {
        return;
    }

    FindStringFn findStringFunc = (FindStringFn)findString;
    FindGameObjectFn findGameObjectFunc = (FindGameObjectFn)findGameObject;
    SetActiveFn setActiveFunc = (SetActiveFn)setActive;
    GetActiveFn getActiveFunc = (GetActiveFn)getActive;
    SetTextFn setTextFunc = (SetTextFn)setText;
    PtrToStringAnsiFn ptrToStringAnsiFunc = (PtrToStringAnsiFn)ptrToStringAnsi;
    GetPlayerNameFn getPlayerNameFunc = (GetPlayerNameFn)getPlayerName;

    Il2CppString* uidStrObj = findStringFunc(UID_PATH);
    if (uidStrObj)
    {
        void* uidObj = findGameObjectFunc(uidStrObj);
        if (uidObj)
        {
            setActiveFunc(uidObj, false);
        }
    }

	// Hide Player Profile UID

    Il2CppString* profileLayerStrObj = findStringFunc(PROFILE_LAYER_PATH);
    if (!profileLayerStrObj) {
        return;
    }
    void* profileLayerObj = findGameObjectFunc(profileLayerStrObj);
    if (!profileLayerObj || !getPlayerID) {
        return;
	}

    if (!getActiveFunc(profileLayerObj)) {
        return;
    }

	GetPlayerIDFn getPlayerIDFunc = (GetPlayerIDFn)getPlayerID;
	void* playerIDText = getPlayerIDFunc(monoInLevelPlayerProfilePageV3);
    void* playerNameText = getPlayerNameFunc(monoInLevelPlayerProfilePageV3);

    if (playerIDText) {
        setTextFunc(playerIDText, nullptr);
	}

    if (playerNameText) {
        setTextFunc(playerNameText, nullptr);
    }
}

void HandleTouchMode() {
    if (gameUpdateInit && !touchScreenInit && g_pEnv->TouchMode && switchInputDeviceToTouchScreen)
    {
        touchScreenInit = true;
        SwitchInputDeviceToTouchScreenFn switchInput = (SwitchInputDeviceToTouchScreenFn)switchInputDeviceToTouchScreen;
        __try
        {
            switchInput(nullptr);
        }
        __except (EXCEPTION_EXECUTE_HANDLER)
        {
            // Ignore exceptions
        }
	}
}

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

    Il2CppString* strObj = findStringFunc(SYNTHESIS_PAGE_NAME);

    if (strObj)
    {
        // Invoke the page opener
        craftEntryPartnerFunc(strObj, nullptr, nullptr, nullptr, nullptr);
        return true;
    }

    return false;
}

static int HookGetFrameCount()
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

static int HookSetFov(void* a1, float changeFovValue)
{
    if (!gameUpdateInit)
    {
        gameUpdateInit = true;
    }

    HandleTouchMode();

    // FOV override
    if (changeFovValue > 30.0f && g_pEnv->EnableSetFov)
    {
        changeFovValue = g_pEnv->FieldOfView;
    }

    // FPS override
    if (setFrameCount && g_pEnv->EnableSetFps) {
        SetFrameCountFn setFrameCountFunc = (SetFrameCountFn)setFrameCount;
        setFrameCountFunc(g_pEnv->TargetFps);
    }

    if (originalSetFov)
    {
        SetFovFn original = (SetFovFn)originalSetFov;
        return original(a1, changeFovValue);
    }
    return 0;
}

static int HookDisplayFog(void* a1, void* a2)
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

static void* HookPlayerPerspective(void* rcx, float display, void* r8)
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

static void HookSetupQuestBanner(void* pThis)
{
    if (findString && findGameObject && setActive)
    {
        FindStringFn findStringFunc = (FindStringFn)findString;
        FindGameObjectFn findGameObjectFunc = (FindGameObjectFn)findGameObject;
        SetActiveFn setActiveFunc = (SetActiveFn)setActive;

        // Hide Quest Banner Logic
        if (g_pEnv->HideQuestBanner)
        {
            void* strObj = findStringFunc(QUEST_BANNER_PATH);
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

static bool HookEventCameraMove(void* pThis, void* event)
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

static void HookShowOneDamageTextEx(void* pThis, int type_, int damageType, int showType, float damage, Il2CppString* showText, void* worldPos, void* attackee, int elementReactionType)
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

static void HookCraftEntry(void* pThis)
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

static void HookOpenTeam()
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

static void HookMonoInLevelPlayerProfilePageV3Ctor(void* pThis)
{
    monoInLevelPlayerProfilePageV3 = pThis;

    CtorFn original = (CtorFn)originalMonoInLevelPlayerProfilePageV3Ctor;
    original(pThis);
}

static void HoolActorManagerCtor(void* pThis) {
    CtorFn original = (CtorFn)originalActorManagerCtor;

    actorManager = pThis;

    original(pThis);
}

static void HookGameUpdate(void* pThis)
{
    HandlePaimonV2();
    HandlePlayerInfo();

    if (requestOpenCraft)
    {
        requestOpenCraft = false;
        DoOpenCraftMenu();
    }

    UpdateFn original = (UpdateFn)originalGameUpdate;
    original(pThis);
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
        setFrameCount = GetFunctionAddress(g_pEnv->Offsets.SetFps);
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

	if (g_pEnv->Offsets.IsObjectActive)
    {
        getActive = GetFunctionAddress(g_pEnv->Offsets.IsObjectActive);
    }

    if (g_pEnv->Offsets.GameUpdate)
    {
        LPVOID gameUpdateAddr = GetFunctionAddress(g_pEnv->Offsets.GameUpdate);
        if (gameUpdateAddr)
        {
            MH_CreateHook(gameUpdateAddr, HookGameUpdate, &originalGameUpdate);
        }
	}

	if (g_pEnv->Offsets.PtrToStringAnsi)
    {
		ptrToStringAnsi = GetFunctionAddress(g_pEnv->Offsets.PtrToStringAnsi);
    }

	if (g_pEnv->Offsets.GetPlayerID)
    {
        getPlayerID = GetFunctionAddress(g_pEnv->Offsets.GetPlayerID);
    }

    if (g_pEnv->Offsets.SetText) {
        setText = GetFunctionAddress(g_pEnv->Offsets.SetText);
    }

    if (g_pEnv->Offsets.MonoInLevelPlayerProfilePageV3Ctor) {
        LPVOID monoInLevelPlayerProfilePageV3Addr = GetFunctionAddress(g_pEnv->Offsets.MonoInLevelPlayerProfilePageV3Ctor);
        if (monoInLevelPlayerProfilePageV3Addr) {
            MH_CreateHook(monoInLevelPlayerProfilePageV3Addr, HookMonoInLevelPlayerProfilePageV3Ctor, &originalMonoInLevelPlayerProfilePageV3Ctor);
        }
    }

    if (g_pEnv->Offsets.GetPlayerName)
    {
        getPlayerName = GetFunctionAddress(g_pEnv->Offsets.GetPlayerName);
    }

	if (g_pEnv->Offsets.ActorManagerCtor)
    {
        LPVOID actorManagerCtorAddr = GetFunctionAddress(g_pEnv->Offsets.ActorManagerCtor);
        if (actorManagerCtorAddr)
        {
            MH_CreateHook(actorManagerCtorAddr, HoolActorManagerCtor, &originalActorManagerCtor);
        }
	}

    if (g_pEnv->Offsets.GetGlobalActor)
    {
        getGlobalActor = GetFunctionAddress(g_pEnv->Offsets.GetGlobalActor);
    }

    if (g_pEnv->Offsets.ResumePaimonInProfilePageAll)
    {
        resumePaimonInProfilePageAll = GetFunctionAddress(g_pEnv->Offsets.ResumePaimonInProfilePageAll);
    }

    if (g_pEnv->Offsets.AvatarPaimonAppear)
    {
        avatarPaimonAppear = GetFunctionAddress(g_pEnv->Offsets.AvatarPaimonAppear);
    }
}
