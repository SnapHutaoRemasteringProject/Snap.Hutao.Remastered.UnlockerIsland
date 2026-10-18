#include "Hooks.h"

#include "../framework.h"
#include "../function/HooksShared.h"
#include "../function/FovOverride.h"
#include "../function/DisablePlayerPerspective.h"
#include "../function/DisablePlayerDiveMosaic.h"
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
#include "../function/FastSkipTalk.h"
#include "../function/CatherineRedirect.h"

#include "../BeyondResist.h"
#include "../utils/Task.h"
#include "../utils/Scanner.h"
#include "../Logger.h"
#include "../hook/HookWndProc.h"

#include <vector>
#include <Windows.h>

// Offsets are defined in Constants.cpp (g_ChinaOffsets / g_OverseaOffsets)

// ===================================================================
// Shared globals (defined here, declared extern in HooksShared.h)
// ===================================================================

// Core utilities
LPVOID findString = nullptr;
LPVOID findGameObject = nullptr;
LPVOID setActive = nullptr;
LPVOID getActive = nullptr;
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
LPVOID originalPlayerDiveMosaic = nullptr;
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
LPVOID originalSetWaterMaskUID = nullptr;
LPVOID originalSetupPlayerProfilePage = nullptr;

// Non-hooked call targets
LPVOID setFrameCount = nullptr;
LPVOID fnDisplayFog = nullptr;

// Catherine redirect（定义在这里，声明在 function/HooksShared.h）
LPVOID catherineOpenDialog = nullptr;
LPVOID explorationPageEntry = nullptr;
LPVOID originalCatherineEntry = nullptr;
LPVOID originalCatherineDialogCtor = nullptr;

// ===================================================================
// Function registry & dispatch
// ===================================================================
static std::vector<IFunction*> g_functions;

typedef int (*SetFovFn)(void*, float);
typedef void (*UpdateFn)(void*);
typedef void (*SetUidFn)(void*, uint32_t);
typedef void (*SetWaterMaskUIDFn)(void*, Il2CppString*, bool);

static void DispatchUpdate()
{
	bool isResisted = CheckResistInBeyd();

	isResistedLastFrame = isResisted;

	// Dispatch OnUpdate to all registered functions
	for (auto* func : g_functions)
	{
		if (func->IsEnabled())
		{
			func->OnUpdate();
		}
	}
}

DWORD ScanPlayerDiveMosaic()
{
	void* caller = Scanner::Scan(PlayerDiveMosaicPattern);
	void* displayEffect = Scanner::Scan(DisplayEffectPattern);

	if (!caller || !displayEffect)
		return 0;

	int window = 0x800;
	void* lastCall = nullptr;

	for (int i = 0; i < window - 4; ++i)
	{
		uint8_t* currentByte = (uint8_t*)caller + i;

		if (IsCallOpcode(currentByte))
		{
			void* target = Scanner::ResolveRelative(currentByte, 1, 5);
			if (target == displayEffect)
			{
				lastCall = currentByte;
			}
		}
	}

	if (lastCall)
	{
		return (DWORD)GetVirtualAddress((INT64)lastCall);
	}

	return 0;
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
    ScanDirect(SetWaterMaskUIDPattern,                 offsets.SetWaterMaskUID);
    ScanDirect(SetupPlayerProfilePagePattern,          offsets.SetupPlayerProfilePage);
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
	ScanDirect(GetComponentPattern,                     offsets.GetComponent);
	ScanDirect(AvatarPaimonAppearPattern,               offsets.AvatarPaimonAppear);
	ScanDirect(PlayerPerspectivePattern,                offsets.PlayerPerspective);
	ScanDirect(SetTextPattern,                          offsets.SetText);
    offsets.PlayerDiveMosaic = ScanPlayerDiveMosaic();

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
    //ScanRel(PlayerPerspectivePattern,  offsets.PlayerPerspective);
    ScanRel(SetupResinListPattern,     offsets.SetupResinList);
    ScanRel(CheckCanOpenMapPattern, offsets.CheckCanOpenMap);

    // ---- Derived data offsets (read from code at a fixed offset) ----

    // ClosePage = *(int32_t*)(ClosePageCallerPattern_result + 0x2A)
    if (!ClosePageCallerPattern.empty())
    {
        if (auto* addr = Scanner::Scan(ClosePageCallerPattern))
            offsets.ClosePage = Scanner::ReadFieldOffset(addr, 0x2A);
    }

    // FastSkipTalk = scan_result + 0x37E
    if (!FastSkipTalkPattern.empty())
    {
        if (auto* addr = Scanner::Scan(FastSkipTalkPattern))
            offsets.FastSkipTalk = (DWORD)(GetVirtualAddress((INT64)addr) + 0x37E);
    }

    // ResinList = *(int32_t*)(SetupResinList_resolved + 0x27)
    // needs SetupResinListPattern scanned & resolved first.
    if (offsets.SetupResinList != 0)
    {
        auto* funcAddr = GetFunctionAddress(offsets.SetupResinList);
        if (funcAddr)
            offsets.ResinList = Scanner::ReadFieldOffset(funcAddr, 0x1A);
    }
    // If SetupResinList couldn't be resolved, ResinList stays as fallback.
}

// ===================================================================
// 凯瑟琳重定向用到的偏移
//
// 一条特征码同时适配国服/国际服（同版本）；换版本要重新生成，
// 方法见 docs/catherine-redirect-version-guide.md。
// 这四个字段是后加的，外部 Provider 通常不填；所以无论 ProvideOffsets 与否，
// 这里都补扫一遍（只补 0 值的，已有就跳过）。
// ===================================================================
static void ResolveCatherineOffsetsFromPatterns(HookFunctionOffsets& offsets)
{
	auto ScanIfMissing = [&](const std::string& pattern, DWORD& out)
	{
		if (out != 0 || pattern.empty())
		{
			return;
		}

		if (auto* addr = Scanner::Scan(pattern))
		{
			out = (DWORD)GetVirtualAddress((INT64)addr);
		}
	};

	ScanIfMissing(CatherineEntryPattern,      offsets.CatherineEntry);
	ScanIfMissing(CatherineOpenDialogPattern, offsets.CatherineOpenDialog);
	ScanIfMissing(CatherineDialogCtorPattern, offsets.CatherineDialogCtor);
	ScanIfMissing(ExplorationEntryPattern,    offsets.ExplorationEntry);

	// 特征码是按游戏版本写死的（只跨服务器通用）：遇到新版本会全部扫不到，
	// 用一条明确的日志提示去重新生成，而不是让功能静默失效。
	if (offsets.CatherineEntry == 0 || offsets.CatherineOpenDialog == 0 ||
		offsets.CatherineDialogCtor == 0 || offsets.ExplorationEntry == 0)
	{
		Logf("CatherineRedirect: signature miss (entry=0x%08lX open=0x%08lX ctor=0x%08lX exploration=0x%08lX)"
			" - 游戏版本可能已更新，需要按 docs/catherine-redirect-version-guide.md 重新生成特征码",
			(unsigned long)offsets.CatherineEntry, (unsigned long)offsets.CatherineOpenDialog,
			(unsigned long)offsets.CatherineDialogCtor, (unsigned long)offsets.ExplorationEntry);
	}
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

	isResistedLastFrame = isResisted;

	if (!GetUnityMainWindow())
	{
		InitializeWndProcHooks();
	}

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
// SetWaterMaskUID hook — string-driven resist detection
// ===================================================================
static void HookSetWaterMaskUID(void* pThis, Il2CppString* text, bool flag)
{
	// Run even when text is null: exiting 千星奇域 may clear the watermark
	// UID (null), which must also lift the resist state.
	CacheResistState(text);

	if (originalSetWaterMaskUID)
	{
		SetWaterMaskUIDFn original = (SetWaterMaskUIDFn)originalSetWaterMaskUID;
		original(pThis, text, flag);
	}

	// Hide the watermark UID object after it has been (re)set.
	HidePlayerInfo::HideUidWatermark();
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
		ResolveOffsetsFromPatterns(*offsets);
	}

	// 四个凯瑟琳字段两种模式都要补（外部 Provider 一般不认识这几个新字段）
	ResolveCatherineOffsetsFromPatterns(*offsets);

	g_pEnv->Offsets = *offsets;

	// Create and register all IFunction instances
	// Order does not matter; each reads from g_pEnv->Offsets in Initialize()
	g_functions.push_back(new FovOverride());
	g_functions.push_back(new DisablePlayerPerspective());
	g_functions.push_back(new DisablePlayerDiveMosaic());
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
	g_functions.push_back(new FastSkipTalk());
	g_functions.push_back(new CatherineRedirect());

	// Initialize all functions (resolves offsets, creates MinHook hooks)
	for (auto* func : g_functions)
	{
		func->Initialize();
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

	// Set up the SetWaterMaskUID hook (string-driven resist detection)
	if (offsets->SetWaterMaskUID)
	{
		LPVOID setWaterMaskUIDAddr = GetFunctionAddress(offsets->SetWaterMaskUID);
		if (setWaterMaskUIDAddr)
		{
			MH_CreateHook(setWaterMaskUIDAddr, HookSetWaterMaskUID, &originalSetWaterMaskUID);
		}
	}
}
