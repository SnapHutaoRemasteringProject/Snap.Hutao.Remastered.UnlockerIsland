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
	DWORD KeyboardMouseInput;
	DWORD JoypadInput;

	DWORD CombineEntry;
	DWORD CombineEntryPartner;

	DWORD SetupResinList;
	DWORD ResinList;

	DWORD FindString;
	DWORD PlayerPerspective;

	DWORD IsObjectActive;
	DWORD GameUpdate;
	DWORD Reserved1;
	DWORD Reserved2;
	DWORD Reserved3;
	DWORD Reserved4;
	DWORD ActorManagerCtor;
	DWORD GetGlobalActor;
	DWORD AvatarPaimonAppear;

	DWORD GetComponent;
	DWORD GetText;

	DWORD GetName;

	DWORD CheckCanOpenMap;

	DWORD InLevelClockPageOkButtonClicked;
	DWORD InLevelClockPageCloseButtonClicked;
	DWORD ClosePage;
};
