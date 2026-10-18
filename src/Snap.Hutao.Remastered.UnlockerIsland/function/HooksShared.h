#pragma once

#include <Windows.h>
#include "../utils/MemoryUtils.h"
#include "../framework.h"

// ============================================================
// Shared function pointers resolved from offsets.
// These are used across multiple IFunction implementations
// and by BeyondResist.cpp / HookWndProc.cpp.
// ============================================================

// --- Core utilities used by many features ---
extern LPVOID findString;       // FindStringFn
extern LPVOID findGameObject;   // FindGameObjectFn
extern LPVOID setActive;        // SetActiveFn (also hooked by HideGrass)
extern LPVOID getActive;        // GetActiveFn
extern LPVOID getName;          // GetNameFn (used by HideGrass)

// --- Input device switching (used by TouchMode, GamepadHotSwitch) ---
extern LPVOID switchInputDeviceToTouchScreen;
extern LPVOID switchInputDeviceToKeyboardMouse;
extern LPVOID switchInputDeviceToJoypad;

// --- Craft / Combine (used by CombineHotkey) ---
extern LPVOID craftEntryPartner;
extern LPVOID checkCanOpenMap;

// --- Team (used by RemoveTeamProgress) ---
extern LPVOID checkCanEnter;
extern LPVOID openTeamPageAccordingly;

// --- Paimon display (used by DisplayPaimon) ---
extern LPVOID avatarPaimonAppear;

// --- InLevelClockPage (used by InLevelClockPageSpeedUp) ---
extern LPVOID inLevelClockPageCloseButtonClicked;

// --- State flags ---
extern bool gameUpdateInit;
extern bool touchScreenInit;
extern bool gamepadHotSwitchInitialized;
extern bool isResistedLastFrame;

// --- Craft menu request flag ---
extern bool requestOpenCraft;

// --- Original hook trampolines (needed by function hooks) ---
extern LPVOID originalGetFrameCount;
extern LPVOID originalSetFov;
extern LPVOID originalPlayerPerspective;
extern LPVOID originalPlayerDiveMosaic;
extern LPVOID originalSetupQuestBanner;
extern LPVOID originalEventCameraMove;
extern LPVOID originalShowOneDamageTextEx;
extern LPVOID originalCraftEntry;
extern LPVOID originalCheckCanOpenMap;
extern LPVOID originalOpenTeam;
extern LPVOID originalSetUID;
extern LPVOID originalSetActive;
extern LPVOID originalSetupResinList;
extern LPVOID originalInLevelClockPageOkButtonClicked;
extern LPVOID originalGameUpdate;
extern LPVOID originalSetWaterMaskUID;
extern LPVOID originalSetupPlayerProfilePage;

// --- Non-hooked function call targets ---
extern LPVOID setFrameCount;
extern LPVOID fnDisplayFog;

// --- Catherine redirect（每日委托入口 → 凯瑟琳委托奖励确认弹窗）---
// 签名与 trampoline 都跟着 hook 一起放这里，定义在 Hooks.cpp。
typedef void (*CatherineEntryFn)(void* self);                              // BJLLHHFDAEM::JEFBGNIMIHF（虚调用，只有 this）
typedef bool (*CatherineOpenDialogFn)(void* self, int32_t idx);             // BLMOGIINPEM::LNJINJKFFHK
typedef void (*CatherineDialogCtorFn)(void* self, void* method);            // BLMOGIINPEM::.ctor
typedef bool (*ExplorationEntryFn)(void* action, Il2CppString* text);       // HGPJJCNAHLB(UIFactory)::BKJHPFINMPE（静态）
typedef Il2CppString* (*FindStringFn)(const char* text);                    // 字符串 helper（UTF-8 -> Il2CppString）

extern LPVOID catherineOpenDialog;            // LNJINJKFFHK 本体（开窗逻辑的调用目标）
extern LPVOID explorationPageEntry;           // UIFactory::BKJHPFINMPE（偶数次调用目标）
extern LPVOID originalCatherineEntry;         // 以下两个是 MH_CreateHook 的 trampoline
extern LPVOID originalCatherineDialogCtor;
