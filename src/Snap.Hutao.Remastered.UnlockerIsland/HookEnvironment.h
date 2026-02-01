#pragma once

#include "HookFunctionOffsets.h"
#include "IslandState.h"
#include <Windows.h>

struct HookEnvironment
{
    DWORD Size;
    IslandState State;
    DWORD LastError;
    DWORD Uid;
    BOOL IsOversea;
    BOOL ProvideOffsets;
    
    BOOL  EnableSetFov;
    FLOAT FieldOfView;
    BOOL  FixLowFov;
    BOOL  DisableFog;
    BOOL  EnableSetFps;
    DWORD TargetFps;
    BOOL  RemoveTeamProgress;
    BOOL  HideQuestBanner;
    BOOL  DisableCameraMove;
    BOOL  DisableDamageText;
    BOOL  TouchMode;
    BOOL  RedirectCombine;
    BOOL  ResinItem000106;
    BOOL  ResinItem000201;
    BOOL  ResinItem107009;
    BOOL  ResinItem107012;
    BOOL  ResinItem220007;
	BOOL  DisplayPaimon;
	BOOL  DebugMode;
    BOOL  HidePlayerInfo;

    HookFunctionOffsets Offsets;
};