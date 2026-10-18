#pragma once

#include <Windows.h>

struct HookFunctionOffsets
{
	DWORD SetUid;                              // MonoUIWaterMask.SetUID
	DWORD SetFov;                              // [pattern scan]
	DWORD SetFog;
	DWORD GetFps;
	DWORD SetFps;                              // 双层跳板

	DWORD OpenTeam;                            // JGDDADKMLDL.DDFODLGCHGM  [pattern scan]
	DWORD OpenTeamAdvanced;                    // JGDDADKMLDL.LBLECKJEGOI  [pattern scan]
	DWORD CheckEnter;                          // [pattern scan]

	DWORD QuestBanner;
	DWORD FindObject;                          // GameObject.Find
	DWORD ObjectActive;                        // GameObject.set_active

	DWORD CameraMove;                          // BOFBPKLPKOK.DNIJOJKIOIF  [pattern scan]
	DWORD DamageText;                          // MonoParticleDamageTextContainer.ShowOneDamageText
	DWORD TouchInput;                          // CNGPNBOAIKK.FGKNOKNIIPL  [pattern scan]
	DWORD KeyboardMouseInput;                  // [pattern scan]
	DWORD JoypadInput;                         // [pattern scan]

	DWORD CombineEntry;                        // NBJLAEKBCIM.DNJNIKDKECD  [pattern scan]
	DWORD CombineEntryPartner;                 // FGPIAOKFJCE.NJCOCBAONEC  [pattern scan]

	DWORD SetupResinList;
	DWORD ResinList;

	DWORD FindString;                          // internal method  [pattern scan]
	DWORD PlayerPerspective;

	DWORD IsObjectActive;                      // GameObject.get_active
	DWORD GameUpdate;                          // MainThreadDispatcher.Update
	DWORD CatherineEntry;                      // BJLLHHFDAEM::JEFBGNIMIHF 每日委托入口（凯瑟琳重定向源）[pattern scan] (was Reserved1)
	DWORD SetupPlayerProfilePage;               // [pattern scan] (was Reserved2)
	DWORD SetWaterMaskUID;                     // MonoUIWaterMask.SetWaterMaskUID  [pattern scan] (was Reserved3)
	DWORD FastSkipTalk;                        // 跳过对话冷却（NOP 补丁地址，特征码扫描结果 + 0x37E，国服/外服通用）(was Reserved4)
	DWORD SetText;                             // UnityEngine.UI.Text.set_text
	DWORD AvatarPaimonAppear;                  // GlobalActor.AvatarPaimonAppear

	DWORD GetComponent;                        // GameObject.GetComponent(String type)

	DWORD PlayerDiveMosaic;

	DWORD GetName;                             // Object.get_name

	DWORD CheckCanOpenMap;                     // [pattern scan]

	DWORD InLevelClockPageOkButtonClicked;
	DWORD InLevelClockPageCloseButtonClicked;
	DWORD ClosePage;

	// 凯瑟琳重定向的两个 hook 目标（追加在末尾，已有字段偏移不变）
	DWORD CatherineOpenDialog;                 // BLMOGIINPEM::LNJINJKFFHK  [pattern scan]
	DWORD CatherineDialogCtor;                 // BLMOGIINPEM::.ctor         [pattern scan]
	DWORD ExplorationEntry;                    // HGPJJCNAHLB(UIFactory)::BKJHPFINMPE [pattern scan]
};
