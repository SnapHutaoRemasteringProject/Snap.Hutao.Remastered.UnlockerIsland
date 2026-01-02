#pragma once

#include "HookFunctionOffsets.h"
#include <Windows.h>

struct HookEnvironment
{
    DWORD Size;
    DWORD State;
    DWORD LastError;
    DWORD Uid;
    HookFunctionOffsets Offsets;
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
};