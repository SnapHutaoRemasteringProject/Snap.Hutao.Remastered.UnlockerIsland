#pragma once

#include <Windows.h>

struct HookFunctionOffsets
{
    DWORD SetUid;
    DWORD SetFov;
    DWORD SetFog;
    DWORD GetFps;
    DWORD SetFps;
    
    DWORD OpenTeam;
    DWORD OpenTeamAdvanced;
    DWORD CheckEnter;
    
    DWORD QuestBanner;
    DWORD FindObject;
    DWORD ObjectActive;
    
    DWORD CameraMove;
    DWORD DamageText;
    DWORD TouchInput;
    
    DWORD CombineEntry;
    DWORD CombineEntryPartner;
    
    DWORD SetupResinList;
    DWORD ResinList;
    DWORD ResinCount;
    DWORD ResinItem;
    DWORD ResinRemove;
    
    DWORD FindString;
    DWORD PlayerPerspective;

    DWORD IsObjectActive;
	DWORD GameUpdate;
    DWORD PtrToStringAnsi;
    DWORD GetPlayerID;
    DWORD SetText;
    DWORD MonoInLevelPlayerProfilePageV3Ctor;
    DWORD GetPlayerName;
    DWORD ActorManagerCtor;
    DWORD GetGlobalActor;
    DWORD AvatarPaimonAppear;

	DWORD GetComponent;
    DWORD GetText;
};
