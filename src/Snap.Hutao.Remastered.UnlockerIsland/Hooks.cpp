#include "Hooks.h"
#include "framework.h"
#include "MemoryUtils.h"
#include "MacroDetector.h"
#include "Cache.h"
#include "Logger.h"
#include "GamepadHotSwitch.h"
#include "HookWndProc.h"
#include <vector>

// Hardcoded offsets (used when ProvideOffsets is FALSE)
static HookFunctionOffsets g_ChinaOffsets = {
	/* SetUid */ 0,
	/* SetFov */ 0x15C0590,
	/* SetFog */ 0x16C99DC0,
	/* GetFps */ 0x12DCD00,
	/* SetFps */ 0x12DCD10,
	/* OpenTeam */ 0xF8E1940,
	/* OpenTeamAdvanced */ 0xF8D7070,
	/* CheckEnter */ 0x101A9C70,
	/* QuestBanner */ 0xE27A820,
	/* FindObject */ 0x10B8540,
	/* ObjectActive */ 0x10B7D00,
	/* CameraMove */ 0xCBDE200,
	/* DamageText */ 0x11514DB0,
	/* TouchInput */ 0xDD948B0,
	/* KeyboardMouseInput */ 0xDD94A60,
	/* JoypadInput */ 0xDD94A60,
	/* CombineEntry */ 0x6A1C4A0,
	/* CombineEntryPartner */ 0x1038BC60,
	/* SetupResinList */ 0xAF372F0,
	/* ResinList */ 0x230,
	/* FindString */ 0x435F60,
	/* PlayerPerspective */ 0xD0F91E0,
	/* IsObjectActive */ 0x16c88e30,
	/* GameUpdate */ 0x164B9860,
	/* Reserved */ 0,
	/* Reserved */ 0,
	/* Reserved */ 0,
	/* Reserved */ 0,
	/* ActorManagerCtor */ 0xdefcd30,
	/* GetGlobalActor */ 0xdf01950,
	/* AvatarPaimonAppear */ 0x11469590,
	/* GetComponent */ 0x16c88ab0,
	/* GetText */ 0x16d88760,
	/* GetName */ 0x16ca0230,
	/* CheckCanOpenMap */ 0x6A1E363,
	/* InLevelClockPageOkButtonClicked */ 0x118DD5E0,
	/* InLevelClockPageCloseButtonClicked */ 0x6E76350,
};

static HookFunctionOffsets g_OverseaOffsets = {
	/* SetUid */ 0xAF1A5A0,
	/* SetFov */ 0,
	/* SetFog */ 0,
	/* GetFps */ 0,
	/* SetFps */ 0,
	/* OpenTeam */ 0,
	/* OpenTeamAdvanced */ 0,
	/* CheckEnter */ 0,
	/* QuestBanner */ 0,
	/* FindObject */ 0,
	/* ObjectActive */ 0,
	/* CameraMove */ 0,
	/* DamageText */ 0,
	/* TouchInput */ 0,
	/* KeyboardMouseInput */ 0,
	/* JoypadInput */ 0,
	/* CombineEntry */ 0,
	/* CombineEntryPartner */ 0,
	/* SetupResinList */ 0,
	/* ResinList */ 0x220,
	/* FindString */ 0,
	/* PlayerPerspective */ 0,
	/* IsObjectActive */ 0,
	/* GameUpdate */ 0,
	/* Reserved */ 0,
	/* Reserved */ 0,
	/* Reserved */ 0,
	/* Reserved */ 0,
	/* ActorManagerCtor */ 0,
	/* GetGlobalActor */ 0,
	/* AvatarPaimonAppear */ 0,
	/* GetComponent */ 0,
	/* GetText */ 0,
	/* GetName */ 0,
	/* CheckCanOpenMap */ 0,
	/* InLevelClockPageOkButtonClicked */ 0,
	/* InLevelClockPageCloseButtonClicked */ 0,
};

// Get_FrameCount
static LPVOID originalGetFrameCount = nullptr;
// Set_FrameCount (Not hooked, just called)
static LPVOID setFrameCount = nullptr;
// ChangeFOV
static LPVOID originalSetFov = nullptr;
// DisplayFog
static LPVOID fnDisplayFog = nullptr;
// Player_Perspective
static LPVOID originalPlayerPerspective = nullptr;
// Touch Screen
LPVOID switchInputDeviceToTouchScreen = nullptr;
LPVOID switchInputDeviceToKeboardMouse = nullptr;
LPVOID switchInputDeviceToJoypad = nullptr;

// Quest Banner
static LPVOID originalSetupQuestBanner = nullptr;
LPVOID findGameObject = nullptr;
LPVOID setActive = nullptr;

// Event Camera
static LPVOID originalEventCameraMove = nullptr;

// Damage Text
static LPVOID originalShowOneDamageTextEx = nullptr;

// Craft Redirect
LPVOID findString = nullptr;
LPVOID craftEntryPartner = nullptr;
static LPVOID originalCraftEntry = nullptr;
static LPVOID originalCheckCanOpenMap = nullptr;
static LPVOID checkCanOpenMap = nullptr;
static unsigned char originalCheckCanOpenMapBytes[5];

// Team Anime
LPVOID checkCanEnter = nullptr;
LPVOID openTeamPageAccordingly = nullptr;
static LPVOID originalOpenTeam = nullptr;

static LPVOID originalGameUpdate = nullptr;

// Global State
static bool gameUpdateInit = false;
static bool touchScreenInit = false;
static bool macroDetectorInitialized = false;
// Flag to request opening the craft menu from the main thread
static bool requestOpenCraft = false;

// Gamepad Hot Switch
static bool gamepadHotSwitchInitialized = false;

// Paimon Display
LPVOID getActive = nullptr;

// Paimon Display
static LPVOID originalActorManagerCtor = nullptr;
static void* actorManager = nullptr;
LPVOID getGlobalActor = nullptr;
LPVOID avatarPaimonAppear = nullptr;

// InLevelClockPage Speed Up
static LPVOID originalInLevelClockPageOkButtonClicked = nullptr;
LPVOID inLevelClockPageCloseButtonClicked = nullptr;

static LPVOID originalSetUID = nullptr;

typedef int(*GetFrameCountFn)();
typedef int(*SetFrameCountFn)(int);
typedef int(*SetFovFn)(void*, float);
typedef void(*SwitchInputDeviceToTouchScreenFn)(void*);
typedef void(*SwitchInputDeviceToKeyboardMouseFn)(void*);
typedef void(*SwitchInputDeviceToJoypadFn)(void*);

// Quest Banner Types
typedef void(*SetupQuestBannerFn)(void*);
typedef void* (*FindGameObjectFn)(void*);
typedef void(*SetActiveFn)(void*, bool);
typedef bool(*GetActiveFn)(void*);

// Event Camera Types
typedef bool(*EventCameraMoveFn)(void*, void*);

// Damage Text Types
typedef void(*ShowOneDamageTextExFn)(void*, int, int, int, float, Il2CppString*, void*, void*, int);

typedef void(*SetEnableFogRenderingFn)(bool);

typedef void* (*PlayerPerspectiveFn)(void*, float, void*);

// Craft Redirect Types
typedef Il2CppString* (*FindStringFn)(const char*);
typedef Il2CppString* (*PtrToStringAnsiFn)(const char*);

typedef void(*CraftEntryFn)(void*);
typedef bool(*CraftEntryPartnerFn)(Il2CppString*, void*, void*, void*, void*);

// Team Anime Types
typedef bool(*CheckCanEnterFn)();

typedef void(*OpenTeamFn)();

typedef void(*OpenTeamPageAccordinglyFn)(bool);

typedef void(*UpdateFn)(void*);
typedef void(*SetTextFn)(void*, Il2CppString*);
typedef void* (*GetPlayerIDFn)(void*);
typedef void* (*GetPlayerNameFn)(void*);
typedef void(*CtorFn)(void*);

// Paimon Display
typedef void* (*GetGlobalActorFn)(void*);
typedef void(*ResumePaimonInProfilePageAll)(void*);
typedef void(*AvatarPaimonAppearFn)(void*, void*, bool);

typedef void (*SetUidFn)(void*, uint32_t);

// Beyd Limit
LPVOID getComponent = nullptr;
LPVOID getText = nullptr;
typedef void* (*GetComponentFn)(void*, Il2CppString*);
typedef Il2CppString* (*GetTextFn)(void*);

static LPVOID originalSetActive = nullptr;
static LPVOID getName = nullptr;
typedef Il2CppString* (*GetNameFn)(void*);

// Resin
static LPVOID originalSetupResinList;
typedef void (*SetupResinListFn)(void*);

// InLevelClockPage Speed Up
typedef void (*ButtonClickedFn)(void*);

static bool isResistedLastFrame = false;

bool CheckResistInBeyd()
{
	return g_cachedIsResisted;
}

void HandlePaimon()
{
	if (!setActive || !getActive)
	{
		return;
	}

	SetActiveFn setActiveFunc = (SetActiveFn)setActive;
	GetActiveFn getActiveFunc = (GetActiveFn)getActive;

	if (g_pEnv->DisplayPaimon)
	{
		void* paimonObj = GetCachedPaimonGameObject();
		void* profileLayerObj = GetCachedProfileLayerGameObject();

		if (paimonObj && profileLayerObj)
		{
			bool profileOpen = getActiveFunc(profileLayerObj);

			if (profileOpen)
			{
				setActiveFunc(paimonObj, false);
			}
			else
			{
				setActiveFunc(paimonObj, true);
			}
		}
	}
}

void HandlePaimonV2()
{
	if (!g_pEnv->DisplayPaimon)
	{
		return;
	}

	if (!getGlobalActor || !getActive || !avatarPaimonAppear)
	{
		return;
	}

	if (!actorManager)
	{
		return;
	}

	GetGlobalActorFn getGlobalActorFunc = (GetGlobalActorFn)getGlobalActor;
	GetActiveFn getActiveFunc = (GetActiveFn)getActive;

	void* paimonObj = GetCachedPaimonGameObject();
	void* divePaimonObj = GetCachedDivePaimonGameObject();
	void* beydPaimonObj = GetCachedBeydPaimonGameObject();

	if (!paimonObj || !divePaimonObj || !beydPaimonObj)
	{
		return;
	}

	if (getActiveFunc(paimonObj) || getActiveFunc(divePaimonObj) || getActiveFunc(beydPaimonObj))
	{
		return;
	}

	void* globalActor = getGlobalActorFunc(actorManager);

	if (globalActor)
	{
		AvatarPaimonAppearFn avatarPaimonAppearFunc = (AvatarPaimonAppearFn)avatarPaimonAppear;
		avatarPaimonAppearFunc(globalActor, nullptr, true);
	}
}

void HandlePlayerInfo()
{
	if (!g_pEnv->HidePlayerInfo)
	{
		return;
	}

	if (!findString || !findGameObject || !setActive || !getActive)
	{
		return;
	}

	FindStringFn findStringFunc = (FindStringFn)findString;
	FindGameObjectFn findGameObjectFunc = (FindGameObjectFn)findGameObject;
	SetActiveFn setActiveFunc = (SetActiveFn)setActive;
	GetActiveFn getActiveFunc = (GetActiveFn)getActive;

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

	Il2CppString* profileUidStrObj = findStringFunc(PROFILE_UID_PATH);
	if (profileUidStrObj)
	{
		void* profileUidObj = findGameObjectFunc(profileUidStrObj);
		if (profileUidObj)
		{
			setActiveFunc(profileUidObj, false);
		}
	}

	// Hide Player Name in Profile Page

	Il2CppString* profileNameStrObj = findStringFunc(PROFILE_NAME_PATH);
	if (profileNameStrObj)
	{
		void* profileNameObj = findGameObjectFunc(profileNameStrObj);
		if (profileNameObj)
		{
			setActiveFunc(profileNameObj, false);
		}
	}
}

void HandleTouchMode()
{
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

void HandleGamepadHotSwitch()
{
	if (!gamepadHotSwitchInitialized && g_pEnv->GamepadHotSwitchEnabled)
	{
		gamepadHotSwitchInitialized = true;
		GamepadHotSwitch& hotSwitch = GamepadHotSwitch::GetInstance();

		if (!hotSwitch.Initialize())
		{
			Log("[GamepadHotSwitch] Failed to initialize");
			return;
		}

		hotSwitch.SetEnabled(true);

		InitializeWndProcHooks();

		Log("[GamepadHotSwitch] Initialized and enabled");
	}
	else if (gamepadHotSwitchInitialized && !g_pEnv->GamepadHotSwitchEnabled)
	{
		GamepadHotSwitch& hotSwitch = GamepadHotSwitch::GetInstance();
		hotSwitch.SetEnabled(false);
		gamepadHotSwitchInitialized = false;
		Log("[GamepadHotSwitch] Disabled");
	}

	if (gamepadHotSwitchInitialized)
	{
		GamepadHotSwitch& hotSwitch = GamepadHotSwitch::GetInstance();
		hotSwitch.SetEnabled(g_pEnv->GamepadHotSwitchEnabled);
	}
}

void HandleOpenMap()
{
	if (!checkCanOpenMap)
	{
		return;
	}

	unsigned char* patchBytes = (unsigned char*)checkCanOpenMap;
	if (patchBytes[0] == 0xE8)
	{
		originalCheckCanOpenMapBytes[0] = patchBytes[0];
		originalCheckCanOpenMapBytes[1] = patchBytes[1];
		originalCheckCanOpenMapBytes[2] = patchBytes[2];
		originalCheckCanOpenMapBytes[3] = patchBytes[3];
		originalCheckCanOpenMapBytes[4] = patchBytes[4];
	}

	if (g_pEnv->RedirectCombine && !CheckResistInBeyd())
	{
		patchBytes[0] = 0xB8;
		patchBytes[1] = 0x00;
		patchBytes[2] = 0x00;
		patchBytes[3] = 0x00;
		patchBytes[4] = 0x00;
	}
	else
	{
		patchBytes[0] = originalCheckCanOpenMapBytes[0];
		patchBytes[1] = originalCheckCanOpenMapBytes[1];
		patchBytes[2] = originalCheckCanOpenMapBytes[2];
		patchBytes[3] = originalCheckCanOpenMapBytes[3];
		patchBytes[4] = originalCheckCanOpenMapBytes[4];
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
	bool isResisted = CheckResistInBeyd();
	if (!gameUpdateInit)
	{
		Cache_Init();
		gameUpdateInit = true;
	}

	if (isResisted && !isResistedLastFrame)
	{
		MacroDetector::GetInstance().ShowLimitedMessage();
	}

	isResistedLastFrame = isResisted;

	HandleTouchMode();
	HandleGamepadHotSwitch();

	// FOV override
	if (changeFovValue > 30.0f && g_pEnv->EnableSetFov && !isResisted)
	{
		changeFovValue = g_pEnv->FieldOfView;
	}

	// FPS override
	if (setFrameCount && g_pEnv->EnableSetFps && !isResisted)
	{
		SetFrameCountFn setFrameCountFunc = (SetFrameCountFn)setFrameCount;
		setFrameCountFunc(g_pEnv->TargetFps);
	}

	// Fog override
	if (fnDisplayFog)
	{
		SetEnableFogRenderingFn setFog = (SetEnableFogRenderingFn)fnDisplayFog;
		setFog(!g_pEnv->DisableFog);
	}

	if (originalSetFov)
	{
		SetFovFn original = (SetFovFn)originalSetFov;
		return original(a1, changeFovValue);
	}
	return 0;
}

static void* HookPlayerPerspective(void* rcx, float display, void* r8)
{
	if (g_pEnv->DisablePlayerPerspective && !CheckResistInBeyd())
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
			Il2CppString* strObj = findStringFunc(QUEST_BANNER_PATH);
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

static void HookActorManagerCtor(void* pThis)
{
	CtorFn original = (CtorFn)originalActorManagerCtor;

	actorManager = pThis;

	original(pThis);
}

static void HookSetUID(void* pThis, uint32_t uid)
{
	g_pEnv->Uid = uid;
	SetUidFn original = (SetUidFn)originalSetUID;
	original(pThis, uid);
}

static void HookSetActive(void* pThis, bool active)
{
	if (g_pEnv->HideGrass && !CheckResistInBeyd() && active && getName)
	{
		GetNameFn getNameFunc = (GetNameFn)getName;
		Il2CppString* name = getNameFunc(pThis);
		if (name)
		{
			if (wcsstr(name->chars, L"_Grass_"))
			{
				for (std::wstring prefix : GrassPrefix)
				{
					if (wcsstr(name->chars, prefix.c_str()))
					{
						Log(name);
						return;
					}
				}
			}
		}
	}

pass:
	SetActiveFn original = (SetActiveFn)originalSetActive;
	original(pThis, active);
}

static void HookSetupResinList(void* pThis)
{
	SetupResinListFn original = (SetupResinListFn)originalSetupResinList;
	original(pThis);

	Il2CppList<ULONG64>* resinList = *(Il2CppList<ULONG64>**)((intptr_t)pThis + g_pEnv->Offsets.ResinList);
	std::vector<ULONG64> toRemove(5);

	for (int i = 0; i < resinList->Count(); i++)
	{
		ULONG64 item = resinList->Get(i);
		Log("item=" + std::to_string(item) + ";len=" + std::to_string(resinList->Count()));

		UINT32 hight = (UINT32)(item >> 32);
		UINT32 low = (UINT32)(item & 0xFFFFFFFF);

		if ((hight == 106 || low == 106) && !g_pEnv->ResinItem000106
			|| (hight == 201 || low == 201) && !g_pEnv->ResinItem000201
			|| (hight == 107009 || low == 107009) && !g_pEnv->ResinItem107009
			|| (hight == 107012 || low == 107012) && !g_pEnv->ResinItem107012
			|| (hight == 220007 || low == 220007) && !g_pEnv->ResinItem220007)
		{
			toRemove.push_back(item);
		}
	}

	for (ULONG64 item : toRemove)
	{
		if (item == 0) continue;
		resinList->Remove(item);
		Log(std::to_string(item) + " was Removed");
	}
}

static void HookInLevelClockPageOkButtonClicked(void* pThis)
{
	ButtonClickedFn original = (ButtonClickedFn)originalInLevelClockPageOkButtonClicked;

	if (g_pEnv->EnableInLevelClockPageSpeedUp && inLevelClockPageCloseButtonClicked)
	{
		ButtonClickedFn inLevelClockPageCloseButtonClickedFunc = (ButtonClickedFn)inLevelClockPageCloseButtonClicked;
		Log("InLevelClockPage Speed Up");
		inLevelClockPageCloseButtonClickedFunc(pThis);
	}

	original(pThis);
}

static void HookGameUpdate(void* pThis)
{
	if (!macroDetectorInitialized)
	{
		MacroDetector::GetInstance().Initialize();
		macroDetectorInitialized = true;
		Log("[MacroDetector] Initialized on first GameUpdate");
	}

	static ULONGLONG lastExecutionTime = 0;
	ULONGLONG currentTime = GetTickCount64();

	if (currentTime - lastExecutionTime >= 500)
	{
		lastExecutionTime = currentTime;
		HandlePaimonV2();
		HandleOpenMap();
		CacheResistState();

		if (gamepadHotSwitchInitialized)
		{
			HandleGamepadHotSwitch();
		}
	}

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
	// Choose which offsets to use based on ProvideOffsets flag
	HookFunctionOffsets* offsets = &g_pEnv->Offsets;
	if (!g_pEnv->ProvideOffsets)
	{
		if (!g_pEnv->IsOversea)
		{
			offsets = &g_ChinaOffsets;
		}
		else
		{
			offsets = &g_OverseaOffsets;
		}
	}

	g_pEnv->Offsets = *offsets;

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

	if (offsets->KeyboardMouseInput)
	{
		switchInputDeviceToKeboardMouse = GetFunctionAddress(offsets->KeyboardMouseInput);
	}

	if (offsets->JoypadInput)
	{
		switchInputDeviceToJoypad = GetFunctionAddress(offsets->JoypadInput);
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
		if (setActive)
		{
			MH_CreateHook(setActive, HookSetActive, &originalSetActive);
		}
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
		fnDisplayFog = GetFunctionAddress(offsets->SetFog);
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

	if (offsets->GetName)
	{
		getName = GetFunctionAddress(offsets->GetName);
	}

	if (offsets->CheckCanOpenMap)
	{
		checkCanOpenMap = GetFunctionAddress(offsets->CheckCanOpenMap);
		DWORD oldProtect;
		VirtualProtect(checkCanOpenMap, 5, PAGE_EXECUTE_READWRITE, &oldProtect);
	}

	if (offsets->SetupResinList)
	{
		LPVOID setupResinListAddr = GetFunctionAddress(offsets->SetupResinList);
		if (setupResinListAddr)
		{
			MH_CreateHook(setupResinListAddr, HookSetupResinList, &originalSetupResinList);
		}
	}

	if (offsets->InLevelClockPageOkButtonClicked)
	{
		LPVOID inLevelClockPageOkButtonClickedAddr = GetFunctionAddress(offsets->InLevelClockPageOkButtonClicked);
		if (inLevelClockPageOkButtonClickedAddr)
		{
			MH_CreateHook(inLevelClockPageOkButtonClickedAddr, HookInLevelClockPageOkButtonClicked, &originalInLevelClockPageOkButtonClicked);
		}
	}

	if (offsets->InLevelClockPageCloseButtonClicked)
	{
		inLevelClockPageCloseButtonClicked = GetFunctionAddress(offsets->InLevelClockPageCloseButtonClicked);
	}
}
