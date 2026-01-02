#pragma once

#include <Windows.h>

struct HookFunctionOffsets
{
    DWORD GameManagerAwake;
    DWORD MickeyWonderMethod;
    DWORD MickeyWonderMethodPartner;
    DWORD MickeyWonderMethodPartner2;
    DWORD SetLastUid;
    DWORD SetFieldOfView;
    DWORD SetEnableFogRendering;
    DWORD GetTargetFrameRate;
    DWORD SetTargetFrameRate;
    DWORD OpenTeam;
    DWORD OpenTeamPageAccordingly;
    DWORD CheckCanEnter;
    DWORD SetupQuestBanner;
    DWORD FindGameObject;
    DWORD SetActive;
    DWORD EventCameraMove;
    DWORD ShowOneDamageTextEx;
    DWORD SwitchInputDeviceToTouchScreen;
    DWORD MickeyWonderCombineEntryMethod;
    DWORD MickeyWonderCombineEntryMethodPartner;
    DWORD SetupResinList;
    DWORD ResinList;
    DWORD ResinListGetCount;
    DWORD ResinListGetItem;
    DWORD ResinListRemove;
};