#pragma once

#include <Windows.h>

struct HookFunctionOffsets
{
    DWORD GameManagerAwake;
    
    DWORD MainEntryPoint;
    DWORD MainEntryPartner1;
    DWORD MainEntryPartner2;
    
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
    
    DWORD SetupResin;
    DWORD ResinList;
    DWORD ResinCount;
    DWORD ResinItem;
    DWORD ResinRemove;
    
    DWORD FindString;
    DWORD PlayerPerspective;
};
