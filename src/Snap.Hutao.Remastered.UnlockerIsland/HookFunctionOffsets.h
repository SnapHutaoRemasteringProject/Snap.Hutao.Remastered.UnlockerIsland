#pragma once

#include <Windows.h>

struct HookFunctionOffsets
{
	DWORD SetUid;                              // MonoUIWaterMask.SetUID
	DWORD SetFov;                              // [pattern scan]
	DWORD SetFog;                              //
	DWORD GetFps;                              //
	DWORD SetFps;                              // 双层跳板

	DWORD OpenTeam;                            // JGDDADKMLDL.DDFODLGCHGM  [pattern scan]
	DWORD OpenTeamAdvanced;                    // JGDDADKMLDL.LBLECKJEGOI  [pattern scan]
	DWORD CheckEnter;                          // [pattern scan]

	DWORD QuestBanner;                         //
	DWORD FindObject;                          // GameObject.Find
	DWORD ObjectActive;                        // GameObject.set_active

	DWORD CameraMove;                          // BOFBPKLPKOK.DNIJOJKIOIF  [pattern scan]
	DWORD DamageText;                          // MonoParticleDamageTextContainer.ShowOneDamageText
	DWORD TouchInput;                          // CNGPNBOAIKK.FGKNOKNIIPL  [pattern scan]
	DWORD KeyboardMouseInput;                  // [pattern scan]
	DWORD JoypadInput;                         // [pattern scan]

	DWORD CombineEntry;                        // NBJLAEKBCIM.DNJNIKDKECD  [pattern scan]
	DWORD CombineEntryPartner;                 // FGPIAOKFJCE.NJCOCBAONEC  [pattern scan]

	DWORD SetupResinList;                      //
	DWORD ResinList;                           //

	DWORD FindString;                          // internal method  [pattern scan]
	DWORD PlayerPerspective;                   //

	DWORD IsObjectActive;                      // GameObject.get_active
	DWORD GameUpdate;                          // MainThreadDispatcher.Update
	DWORD Reserved1;
	DWORD Reserved2;
	DWORD Reserved3;
	DWORD Reserved4;
	DWORD Reserved5;
	DWORD PlayerPerspective2;
	DWORD AvatarPaimonAppear;                  // GlobalActor.AvatarPaimonAppear

	DWORD GetComponent;                        // GameObject.GetComponent(String type)
	DWORD GetText;                             // Text.get_text

	DWORD GetName;                             // Object.get_name

	DWORD CheckCanOpenMap;                     // [pattern scan]

	DWORD InLevelClockPageOkButtonClicked;     //
	DWORD InLevelClockPageCloseButtonClicked;  //
	DWORD ClosePage;                           //
};
