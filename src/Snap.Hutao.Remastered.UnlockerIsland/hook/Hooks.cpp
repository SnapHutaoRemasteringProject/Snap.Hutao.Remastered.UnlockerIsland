#include "Hooks.h"

#include "../framework.h"
#include "../function/HooksShared.h"
#include "../function/FovOverride.h"
#include "../function/DisablePlayerPerspective.h"
#include "../function/DisableFog.h"
#include "../function/EnableSetFps.h"
#include "../function/RemoveTeamProgress.h"
#include "../function/HideQuestBanner.h"
#include "../function/DisableCameraMove.h"
#include "../function/DisableDamageText.h"
#include "../function/TouchMode.h"
#include "../function/ResinItem.h"
#include "../function/DisplayPaimon.h"
#include "../function/HidePlayerInfo.h"
#include "../function/HideGrass.h"
#include "../function/GamepadHotSwitchFunc.h"
#include "../function/InLevelClockPageSpeedUp.h"
#include "../function/CombineHotkey.h"
#include "../function/WeakMapCheck.h"

#include "../MacroDetector.h"
#include "../Cache.h"
#include "../utils/Task.h"
#include "../Logger.h"

#include <vector>

// Offsets are defined in Constants.cpp (g_ChinaOffsets / g_OverseaOffsets)

// ===================================================================
// Shared globals (defined here, declared extern in HooksShared.h)
// ===================================================================

// Core utilities
LPVOID findString = nullptr;
LPVOID findGameObject = nullptr;
LPVOID setActive = nullptr;
LPVOID getActive = nullptr;
LPVOID getComponent = nullptr;
LPVOID getText = nullptr;
LPVOID getName = nullptr;

// Input switching
LPVOID switchInputDeviceToTouchScreen = nullptr;
LPVOID switchInputDeviceToKeyboardMouse = nullptr;
LPVOID switchInputDeviceToJoypad = nullptr;

// Craft / Combine
LPVOID craftEntryPartner = nullptr;
LPVOID checkCanOpenMap = nullptr;

// Team
LPVOID checkCanEnter = nullptr;
LPVOID openTeamPageAccordingly = nullptr;

// Paimon display
LPVOID avatarPaimonAppear = nullptr;

// InLevelClockPage
LPVOID inLevelClockPageCloseButtonClicked = nullptr;

// State flags
bool gameUpdateInit = false;
bool touchScreenInit = false;
bool gamepadHotSwitchInitialized = false;
bool isResistedLastFrame = false;

// Craft menu request flag
bool requestOpenCraft = false;

// ===================================================================
// Original trampolines (set by MH_CreateHook in function Initialize())
// ===================================================================
LPVOID originalGetFrameCount = nullptr;
LPVOID originalSetFov = nullptr;
LPVOID originalPlayerPerspective = nullptr;
LPVOID originalSetupQuestBanner = nullptr;
LPVOID originalEventCameraMove = nullptr;
LPVOID originalShowOneDamageTextEx = nullptr;
LPVOID originalCraftEntry = nullptr;
LPVOID originalCheckCanOpenMap = nullptr;
LPVOID originalOpenTeam = nullptr;
LPVOID originalSetUID = nullptr;
LPVOID originalSetActive = nullptr;
LPVOID originalSetupResinList = nullptr;
LPVOID originalInLevelClockPageOkButtonClicked = nullptr;
LPVOID originalGameUpdate = nullptr;

// Non-hooked call targets
LPVOID setFrameCount = nullptr;
LPVOID fnDisplayFog = nullptr;

// ===================================================================
// Function registry & dispatch
// ===================================================================
static std::vector<IFunction*> g_functions;
static bool macroDetectorInitialized = false;

typedef int (*SetFovFn)(void*, float);
typedef void (*UpdateFn)(void*);
typedef void (*SetUidFn)(void*, uint32_t);

static void DispatchUpdate()
{
	bool isResisted = CheckResistInBeyd();

	if (isResisted && !isResistedLastFrame)
	{
		MacroDetector::GetInstance().ShowLimitedMessage();
	}

	isResistedLastFrame = isResisted;

	if (!macroDetectorInitialized)
	{
		MacroDetector::GetInstance().Initialize();
		macroDetectorInitialized = true;
	}

	// Throttled (2000ms) operations — refresh resist (千星奇域) state
	static ULONGLONG lastExecutionTime = 0;
	ULONGLONG currentTime = GetTickCount64();

	if (currentTime - lastExecutionTime >= 2000)
	{
		lastExecutionTime = currentTime;
		CacheResistState();
	}

	// Dispatch OnUpdate to all registered functions
	for (auto* func : g_functions)
	{
		if (func->IsEnabled())
		{
			func->OnUpdate();
		}
	}
}

// ===================================================================
// Pattern-scan offset resolver
// Overrides whatever offsets the test or fallback tables provided
// with values obtained via pattern scanning. Functions that have no
// pattern remain at their fallback value (which may be 0 / nullptr).
// ===================================================================

static void ResolveOffsetsFromPatterns(HookFunctionOffsets& offsets)
{
	ZeroMemory(&offsets, sizeof(offsets));
    // ---- Direct-address patterns (scan result IS the function) ----

    auto ScanDirect = [&](const std::string& pattern, DWORD& out)
    {
        if (pattern.empty()) return;
        if (auto* addr = Scanner::Scan(pattern))
            out = (DWORD)GetVirtualAddress((INT64)addr);
    };

    ScanDirect(SetFovPattern,                        offsets.SetFov);
    ScanDirect(SwitchInputDeviceToTouchScreenPattern, offsets.TouchInput);
    ScanDirect(SwitchInputDeviceToJoypadPattern,      offsets.JoypadInput);
    ScanDirect(SwitchInputDeviceToKeyboardPattern,    offsets.KeyboardMouseInput);
    ScanDirect(SetupQuestBannerPattern,                offsets.QuestBanner);
    ScanDirect(FindGameObjectPattern,                  offsets.FindObject);
    ScanDirect(SetUIDPattern,                          offsets.SetUid);
    ScanDirect(EventCameraMovePattern,                 offsets.CameraMove);
    ScanDirect(ShowOneDamageTextExPattern,             offsets.DamageText);
    ScanDirect(FindStringPattern,                      offsets.FindString);
    ScanDirect(CraftEntryPartnerPattern,               offsets.CombineEntryPartner);
    ScanDirect(CraftEntryPattern,                      offsets.CombineEntry);
    ScanDirect(CheckCanEnterPattern,                   offsets.CheckEnter);
    ScanDirect(OpenTeamPageAccordinglyPattern,         offsets.OpenTeamAdvanced);
    ScanDirect(OpenTeamPattern,                        offsets.OpenTeam);
    ScanDirect(GetNamePattern,                         offsets.GetName);
    ScanDirect(GameUpdatePattern,                      offsets.GameUpdate);
    ScanDirect(InLevelClockPageOkButtonClickedPattern,  offsets.InLevelClockPageOkButtonClicked);
    ScanDirect(InLevelClockPageCloseButtonClickedPattern, offsets.InLevelClockPageCloseButtonClicked);

    // ---- REL (relative-call) patterns ----
    // Scan finds a CALL (E8) instruction; ResolveRelative gives the target.

    auto ScanRel = [&](const std::string& pattern, DWORD& out)
    {
        if (pattern.empty()) return;
        if (auto* addr = Scanner::Scan(pattern))
            if (auto* target = Scanner::ResolveRelative(addr))
                out = (DWORD)GetVirtualAddress((INT64)target);
    };

    ScanRel(GetFrameCountPattern,      offsets.GetFps);
    ScanRel(SetFrameCountPattern,      offsets.SetFps);
    ScanRel(SetActivePattern,          offsets.ObjectActive);
    ScanRel(IsActivePattern,           offsets.IsObjectActive);
    ScanRel(DisplayFogPattern,         offsets.SetFog);
    ScanRel(PlayerPerspectivePattern,  offsets.PlayerPerspective);
    ScanRel(SetupResinListPattern,     offsets.SetupResinList);
    ScanRel(CheckCanOpenMapPattern, offsets.CheckCanOpenMap);

    // ---- Derived data offsets (read from code at a fixed offset) ----

    // ClosePage = *(int32_t*)(ClosePageCallerPattern_result + 0x2A)
    if (!ClosePageCallerPattern.empty())
    {
        if (auto* addr = Scanner::Scan(ClosePageCallerPattern))
            offsets.ClosePage = Scanner::ReadFieldOffset(addr, 0x2A);
    }

    // ResinList = *(int32_t*)(SetupResinList_resolved + 0x27)
    // needs SetupResinListPattern scanned & resolved first.
    if (offsets.SetupResinList != 0)
    {
        auto* funcAddr = GetFunctionAddress(offsets.SetupResinList);
        if (funcAddr)
            offsets.ResinList = Scanner::ReadFieldOffset(funcAddr, 0x27);
    }
    // If SetupResinList couldn't be resolved, ResinList stays as fallback.
}

// ===================================================================
// Master SetFov hook — also serves as the main per-frame dispatch
// ===================================================================
static int MasterHookSetFov(void* a1, float changeFovValue)
{
	if (!gameUpdateInit)
	{
		gameUpdateInit = true;
	}

	DispatchUpdate();

	// FOV override (must be done here because it modifies the parameter)
	if (changeFovValue > 30.0f && g_pEnv->EnableSetFov && !CheckResistInBeyd())
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

// ===================================================================
// GameUpdate hook — Task ticking + resist monitoring
// ===================================================================
static void HookGameUpdate(void* pThis)
{
	bool isResisted = CheckResistInBeyd();

	if (isResisted && !isResistedLastFrame)
	{
		MacroDetector::GetInstance().ShowLimitedMessage();
	}

	isResistedLastFrame = isResisted;

	Task::Tick();

	if (originalGameUpdate)
	{
		UpdateFn original = (UpdateFn)originalGameUpdate;
		original(pThis);
	}
}

// ===================================================================
// SetUID hook — capture UID from game
// ===================================================================
static void HookSetUID(void* pThis, uint32_t uid)
{
	g_pEnv->Uid = uid;

	if (originalSetUID)
	{
		SetUidFn original = (SetUidFn)originalSetUID;
		original(pThis, uid);
	}
}

// ===================================================================
// Public API
// ===================================================================
void RequestOpenCraft()
{
	requestOpenCraft = true;
}

// ===================================================================
// SetupHooks — create all IFunction instances, initialize, set up hooks
// ===================================================================
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

	// Create and register all IFunction instances
	// Order does not matter; each reads from g_pEnv->Offsets in Initialize()
	g_functions.push_back(new FovOverride());
	g_functions.push_back(new DisablePlayerPerspective());
	g_functions.push_back(new DisableFog());
	g_functions.push_back(new EnableSetFps());
	g_functions.push_back(new RemoveTeamProgress());
	g_functions.push_back(new HideQuestBanner());
	g_functions.push_back(new DisableCameraMove());
	g_functions.push_back(new DisableDamageText());
	g_functions.push_back(new TouchMode());
	g_functions.push_back(new ResinItem());
	g_functions.push_back(new DisplayPaimon());
	g_functions.push_back(new HidePlayerInfo());
	g_functions.push_back(new HideGrass());
	g_functions.push_back(new GamepadHotSwitchFunc());
	g_functions.push_back(new InLevelClockPageSpeedUp());
	g_functions.push_back(new CombineHotkey());
	g_functions.push_back(new WeakMapCheck());

	// Initialize all functions (resolves offsets, creates MinHook hooks)
	for (auto* func : g_functions)
	{
		func->Initialize();
	}

	// Resolve core utility addresses used by Cache / resist detection
	if (offsets->GetComponent)
	{
		getComponent = GetFunctionAddress(offsets->GetComponent);
	}
	if (offsets->GetText)
	{
		getText = GetFunctionAddress(offsets->GetText);
	}

	// Set up the master SetFov dispatch hook
	if (offsets->SetFov)
	{
		LPVOID changeFovAddr = GetFunctionAddress(offsets->SetFov);
		if (changeFovAddr)
		{
			MH_CreateHook(changeFovAddr, MasterHookSetFov, &originalSetFov);
		}
	}

	// Set up the SetUID hook
	if (offsets->SetUid)
	{
		LPVOID setUIDAddr = GetFunctionAddress(offsets->SetUid);
		if (setUIDAddr)
		{
			MH_CreateHook(setUIDAddr, HookSetUID, &originalSetUID);
		}
	}

	// Set up the GameUpdate hook
	if (offsets->GameUpdate)
	{
		LPVOID gameUpdateAddr = GetFunctionAddress(offsets->GameUpdate);
		if (gameUpdateAddr)
		{
			MH_CreateHook(gameUpdateAddr, HookGameUpdate, &originalGameUpdate);
		}
	}
}
