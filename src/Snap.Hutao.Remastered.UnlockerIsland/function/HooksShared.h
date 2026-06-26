#pragma once

#include <Windows.h>
#include "../utils/MemoryUtils.h"
#include "../framework.h"

// ============================================================
// Shared function pointers resolved from offsets.
// These are used across multiple IFunction implementations
// and by Cache.cpp / HookWndProc.cpp.
// ============================================================

// --- Core utilities used by many features ---
extern LPVOID findString;       // FindStringFn
extern LPVOID findGameObject;   // FindGameObjectFn
extern LPVOID setActive;        // SetActiveFn (also hooked by HideGrass)
extern LPVOID getActive;        // GetActiveFn
extern LPVOID getComponent;     // GetComponentFn (used by Cache)
extern LPVOID getText;          // GetTextFn (used by Cache)
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
extern LPVOID originalPlayerPerspective2;
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

// --- Non-hooked function call targets ---
extern LPVOID setFrameCount;
extern LPVOID fnDisplayFog;
