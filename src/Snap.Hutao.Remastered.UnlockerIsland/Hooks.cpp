#include "Hooks.h"
#include "framework.h"
#include "MemoryUtils.h"
#include "MacroDetector.h"
#include <cstring>
#include <iostream>

// Hardcoded offsets (used when ProvideOffsets is FALSE)
static HookFunctionOffsets g_ChinaOffsets = {
    /* SetUid */ 0xAC68570,
    /* SetFov */ 0x1560ec0,
    /* SetFog */ 0x1573060,
    /* GetFps */ 0x106a3b0,
    /* SetFps */ 0x106a3c0,
    /* OpenTeam */ 0xe47e1b0,
    /* OpenTeamAdvanced */ 0xe4851e0,
    /* CheckEnter */ 0xfeafc10,
    /* QuestBanner */ 0xa98f410,
    /* FindObject */ 0x15B625B0,
    /* ObjectActive */ 0x15B62300,
    /* CameraMove */ 0xfa87490,
    /* DamageText */ 0x1084e9e0,
    /* TouchInput */ 0x105c2c10,
    /* CombineEntry */ 0x69ea500,
    /* CombineEntryPartner */ 0x9199950,
    /* SetupResinList */ 0,
    /* ResinList */ 0,
    /* ResinCount */ 0,
    /* ResinItem */ 0,
    /* ResinRemove */ 0,
    /* FindString */ 0x406330,
    /* PlayerPerspective */ 0xd80fb50,
    /* IsObjectActive */ 0x15B622E0,
    /* GameUpdate */ 0x15394C70,
    /* PtrToStringAnsi */ 0x15565F40,
    /* GetPlayerID */ 0x1082F640,
    /* SetText */ 0x15C451A0,
    /* MonoInLevelPlayerProfilePageV3Ctor */ 0x1082F8E0,
    /* GetPlayerName */ 0x1082F730,
    /* ActorManagerCtor */ 0xD2D4EF0,
    /* GetGlobalActor */ 0xD2CC9E0,
    /* AvatarPaimonAppear */ 0x107BAC60,
    /* GetComponent */ 0x15B61F60,
    /* GetText */ 0x15C45190
};

static HookFunctionOffsets g_OverseaOffsets = {
    /* SetUid */ 0xac5cf50,
    /* SetFov */ 0x155fec0,
    /* SetFog */ 0x1572060,
    /* GetFps */ 0x10693b0,
    /* SetFps */ 0x10693c0,
    /* OpenTeam */ 0xe44b740,
    /* OpenTeamAdvanced */ 0xe478920,
    /* CheckEnter */ 0xfeb9610,
    /* QuestBanner */ 0xa910ef0,
    /* FindObject */ 0x1062c50,
    /* ObjectActive */ 0x1062450,
    /* CameraMove */ 0xfa486c0,
    /* DamageText */ 0x10836b90,
    /* TouchInput */ 0x105a6ab0,
    /* CombineEntry */ 0x69e9630,
    /* CombineEntryPartner */ 0x91936d0,
    /* SetupResinList */ 0,
    /* ResinList */ 0,
    /* ResinCount */ 0,
    /* ResinItem */ 0,
    /* ResinRemove */ 0,
    /* FindString */ 0x405bc0,
    /* PlayerPerspective */ 0xd7fdde0,
    /* IsObjectActive */ 0x15ae6da0,
    /* GameUpdate */ 0x1531c5a0,
    /* PtrToStringAnsi */ 0x154ed320,
    /* GetPlayerID */ 0x10817160,
    /* SetText */ 0x15bc99a0,
    /* MonoInLevelPlayerProfilePageV3Ctor */ 0x10816de0,
    /* GetPlayerName */ 0x10816eb0,
    /* ActorManagerCtor */ 0xd2bcc80,
    /* GetGlobalActor */ 0xd2bd8d0,
    /* AvatarPaimonAppear */ 0x10798cd0,
    /* GetComponent */ 0x15ae6a20,
    /* GetText */ 0x15bc9990
};

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
static bool macroDetectorInitialized = false;
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
static LPVOID avatarPaimonAppear = nullptr;

static LPVOID originalSetUID = nullptr;

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

typedef void (*SetUidFn)(void*, uint32_t);

// Beyd Limit
static LPVOID getComponent = nullptr;
static LPVOID getText = nullptr;
typedef void* (*GetComponentFn)(void*, Il2CppString*);
typedef Il2CppString* (*GetTextFn)(void*);

static bool isResistedLastFrame = false;

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

    if (!getGlobalActor || !getActive || !findString || !findGameObject || !avatarPaimonAppear) {
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

bool CheckResistInBeyd() {
    if (!findString || !findGameObject || !getComponent || !getText)
    {
        return false;
    }

    FindStringFn findStringFunc = (FindStringFn)findString;
    FindGameObjectFn findGameObjectFunc = (FindGameObjectFn)findGameObject;
    GetComponentFn getComponentFunc = (GetComponentFn)getComponent;
    GetTextFn getTextFunc = (GetTextFn)getText;

    Il2CppString* uidStrObj = findStringFunc(UID_PATH);
    Il2CppString* textStrObj = findStringFunc("Text");
    if (uidStrObj)
    {
        void* uidObj = findGameObjectFunc(uidStrObj);
        if (uidObj)
        {
            void* textComponent = getComponentFunc(uidObj, textStrObj);
            if (textComponent)
            {
                Il2CppString* textValue = getTextFunc(textComponent);
                if (textValue)
                {
                    const wchar_t* textChars = textValue->chars;
                    const wchar_t* resistText = L"GUID";
                    return wcsstr(textChars, resistText) != nullptr;
                }
            }
        }

        return false;
    }

    return false;
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
    bool isResisted = CheckResistInBeyd();
    if (!gameUpdateInit)
    {
        gameUpdateInit = true;
    }

    if (g_pEnv->DebugMode && !isResisted) {
        std::cout << "Function not limited" << std::endl;
    }

    if (isResisted && !isResistedLastFrame) {
        MacroDetector::GetInstance().ShowLimitedMessage();
    }

    isResistedLastFrame = isResisted;

    HandleTouchMode();

    // FOV override
    if (changeFovValue > 30.0f && g_pEnv->EnableSetFov && !isResisted)
    {
        changeFovValue = g_pEnv->FieldOfView;
    } else {
        changeFovValue = 45.0f;
    }

    // FPS override
    if (setFrameCount && g_pEnv->EnableSetFps && !isResisted) {
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
    if (g_pEnv->DisableFog && a2 && !CheckResistInBeyd())
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
    if (g_pEnv->FixLowFov && !CheckResistInBeyd())
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
    if (g_pEnv->DisableCameraMove && !CheckResistInBeyd())
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
    if (g_pEnv->DisableDamageText && !CheckResistInBeyd())
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
    if (g_pEnv->RedirectCombine && DoOpenCraftMenu() && !CheckResistInBeyd())
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
    if (g_pEnv->RemoveTeamProgress && checkCanEnter && !CheckResistInBeyd())
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

static void HookActorManagerCtor(void* pThis) {
    CtorFn original = (CtorFn)originalActorManagerCtor;

    actorManager = pThis;

    original(pThis);
}

static void HookSetUID(void* pThis, uint32_t uid) {
    g_pEnv->Uid = uid;
    SetUidFn original = (SetUidFn)originalSetUID;
	original(pThis, uid);
}

static void HookGameUpdate(void* pThis)
{
    if (!macroDetectorInitialized)
    {
        MacroDetector::GetInstance().Initialize();
        macroDetectorInitialized = true;
        std::cout << "[MacroDetector] Initialized on first GameUpdate" << std::endl;
    }
    
    HandlePaimonV2();
    HandlePlayerInfo();

    if (requestOpenCraft)
    {
        requestOpenCraft = false;
        DoOpenCraftMenu();
    }

    MacroDetector::GetInstance().Update();

    UpdateFn original = (UpdateFn)originalGameUpdate;
    original(pThis);
}

void SetupHooks()
{
    // Choose which offsets to use based on ProvideOffsets flag
    HookFunctionOffsets* offsets = &g_pEnv->Offsets;
    if (!g_pEnv->ProvideOffsets) {
        if (!g_pEnv->IsOversea) {
            offsets = &g_ChinaOffsets;
        } else {
            offsets = &g_OverseaOffsets;
        }
    }

    if (offsets->GetFps)
    {
        LPVOID getFrameCountAddr = GetFunctionAddress(offsets->GetFps);
        if (getFrameCountAddr)
        {
            MH_CreateHook(getFrameCountAddr, HookGetFrameCount, &originalGetFrameCount);
        }
    }

    if (offsets->SetFps)
    {
        setFrameCount = GetFunctionAddress(offsets->SetFps);
    }

    if (offsets->SetFov)
    {
        LPVOID changeFovAddr = GetFunctionAddress(offsets->SetFov);
        if (changeFovAddr)
        {
            MH_CreateHook(changeFovAddr, HookSetFov, &originalSetFov);
        }
    }

    if (offsets->TouchInput)
    {
        switchInputDeviceToTouchScreen = GetFunctionAddress(offsets->TouchInput);
    }

    if (offsets->QuestBanner)
    {
        LPVOID setupQuestBannerAddr = GetFunctionAddress(offsets->QuestBanner);
        if (setupQuestBannerAddr)
        {
            MH_CreateHook(setupQuestBannerAddr, HookSetupQuestBanner, &originalSetupQuestBanner);
        }
    }

    if (offsets->FindObject)
    {
        findGameObject = GetFunctionAddress(offsets->FindObject);
    }

    if (offsets->ObjectActive)
    {
        setActive = GetFunctionAddress(offsets->ObjectActive);
    }

    if (offsets->CameraMove)
    {
        LPVOID eventCameraMoveAddr = GetFunctionAddress(offsets->CameraMove);
        if (eventCameraMoveAddr)
        {
            MH_CreateHook(eventCameraMoveAddr, HookEventCameraMove, &originalEventCameraMove);
        }
    }

    if (offsets->DamageText)
    {
        LPVOID showOneDamageTextExAddr = GetFunctionAddress(offsets->DamageText);
        if (showOneDamageTextExAddr)
        {
            MH_CreateHook(showOneDamageTextExAddr, HookShowOneDamageTextEx, &originalShowOneDamageTextEx);
        }
    }

    if (offsets->SetFog)
    {
        LPVOID displayFogAddr = GetFunctionAddress(offsets->SetFog);
        if (displayFogAddr)
        {
            MH_CreateHook(displayFogAddr, HookDisplayFog, &originalDisplayFog);
        }
    }

    if (offsets->PlayerPerspective)
    {
        LPVOID playerPerspectiveAddr = GetFunctionAddress(offsets->PlayerPerspective);
        if (playerPerspectiveAddr)
        {
            MH_CreateHook(playerPerspectiveAddr, HookPlayerPerspective, &originalPlayerPerspective);
        }
    }

    if (offsets->FindString)
    {
        findString = GetFunctionAddress(offsets->FindString);
    }

    if (offsets->CombineEntryPartner)
    {
        craftEntryPartner = GetFunctionAddress(offsets->CombineEntryPartner);
    }

    if (offsets->CombineEntry)
    {
        LPVOID craftEntryAddr = GetFunctionAddress(offsets->CombineEntry);
        if (craftEntryAddr)
        {
            MH_CreateHook(craftEntryAddr, HookCraftEntry, &originalCraftEntry);
        }
    }

    if (offsets->CheckEnter)
    {
        checkCanEnter = GetFunctionAddress(offsets->CheckEnter);
    }

    if (offsets->OpenTeamAdvanced)
    {
        openTeamPageAccordingly = GetFunctionAddress(offsets->OpenTeamAdvanced);
    }

    if (offsets->OpenTeam)
    {
        LPVOID openTeamAddr = GetFunctionAddress(offsets->OpenTeam);
        if (openTeamAddr)
        {
            MH_CreateHook(openTeamAddr, HookOpenTeam, &originalOpenTeam);
        }
    }

	if (offsets->IsObjectActive)
    {
        getActive = GetFunctionAddress(offsets->IsObjectActive);
    }

    if (offsets->GameUpdate)
    {
        LPVOID gameUpdateAddr = GetFunctionAddress(offsets->GameUpdate);
        if (gameUpdateAddr)
        {
            MH_CreateHook(gameUpdateAddr, HookGameUpdate, &originalGameUpdate);
        }
	}

	if (offsets->PtrToStringAnsi)
    {
		ptrToStringAnsi = GetFunctionAddress(offsets->PtrToStringAnsi);
    }

	if (offsets->GetPlayerID)
    {
        getPlayerID = GetFunctionAddress(offsets->GetPlayerID);
    }

    if (offsets->SetText) {
        setText = GetFunctionAddress(offsets->SetText);
    }

    if (offsets->MonoInLevelPlayerProfilePageV3Ctor) {
        LPVOID monoInLevelPlayerProfilePageV3Addr = GetFunctionAddress(offsets->MonoInLevelPlayerProfilePageV3Ctor);
        if (monoInLevelPlayerProfilePageV3Addr) {
            MH_CreateHook(monoInLevelPlayerProfilePageV3Addr, HookMonoInLevelPlayerProfilePageV3Ctor, &originalMonoInLevelPlayerProfilePageV3Ctor);
        }
    }

    if (offsets->GetPlayerName)
    {
        getPlayerName = GetFunctionAddress(offsets->GetPlayerName);
    }

	if (offsets->ActorManagerCtor)
    {
        LPVOID actorManagerCtorAddr = GetFunctionAddress(offsets->ActorManagerCtor);
        if (actorManagerCtorAddr)
        {
            MH_CreateHook(actorManagerCtorAddr, HookActorManagerCtor, &originalActorManagerCtor);
        }
	}

    if (offsets->GetGlobalActor)
    {
        getGlobalActor = GetFunctionAddress(offsets->GetGlobalActor);
    }


    if (offsets->AvatarPaimonAppear)
    {
        avatarPaimonAppear = GetFunctionAddress(offsets->AvatarPaimonAppear);
    }

    if (offsets->SetUid)
    {
        LPVOID setUIDAddr = GetFunctionAddress(offsets->SetUid);
        if (setUIDAddr)
        {
            MH_CreateHook(setUIDAddr, HookSetUID, &originalSetUID);
        }
	}

	if (offsets->GetComponent)
    {
        getComponent = GetFunctionAddress(offsets->GetComponent);
    }

    if (offsets->GetText)
    {
        getText = GetFunctionAddress(offsets->GetText);
	}
}
