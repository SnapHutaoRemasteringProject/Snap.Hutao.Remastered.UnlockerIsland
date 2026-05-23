#include "dllmain.h"
#include "hook/Hooks.h"
#include "MacroDetector.h"
#include "GamepadHotSwitch.h"
#include <cstdio>
#include <iostream>

HookEnvironment* g_pEnv = nullptr;

void CreateConsole()
{
	if (AllocConsole())
	{
		FILE* f;
		freopen_s(&f, "CONOUT$", "w", stdout);
		freopen_s(&f, "CONOUT$", "w", stderr);
		freopen_s(&f, "CONIN$", "r", stdin);
	}
}

DWORD WINAPI WorkerThread(LPVOID lpParam);

BOOL APIENTRY DllMain(HMODULE hModule,
					  DWORD  ul_reason_for_call,
					  LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH:
			DisableThreadLibraryCalls(hModule);

			CreateThread(NULL, 0, WorkerThread, hModule, 0, NULL);
			break;

		case DLL_THREAD_ATTACH:
			break;

		case DLL_THREAD_DETACH:
			break;

		case DLL_PROCESS_DETACH:
			MH_DisableHook(MH_ALL_HOOKS);
			MH_Uninitialize();

			if (g_pEnv)
			{
				g_pEnv->State = IslandState::Stopped;
				UnmapViewOfFile(g_pEnv);
			}

			break;
	}
	return TRUE;
}

DWORD WINAPI WorkerThread(LPVOID lpParam)
{
	InitializeHookEnvironment();

	g_pEnv->State = IslandState::Started;
	g_pEnv->Size = sizeof(HookEnvironment);

	HMODULE module = GetModuleHandleW(L"YuanShen.exe");
	HMODULE module2 = GetModuleHandleW(L"GenshinImpact.exe");

	if (module == 0 && module2 == 0)
	{
		g_pEnv->State = IslandState::Error;
		return -1;
	}

	if (MH_Initialize() != MH_OK)
	{
		g_pEnv->State = IslandState::Error;
		return -1;
	}

	if (g_pEnv->DebugMode)
	{
		CreateConsole();
		//SetupAntiAntiDebugHooks();
		std::cout << "Snap.Hutao.Remastered.UnlockerIsland loaded in debug mode." << std::endl;
		std::cout << "ProvideOffsets = " << g_pEnv->ProvideOffsets << std::endl;
	}

	SetupHooks();

	if (g_pEnv->DebugMode)
	{
		auto& o = g_pEnv->Offsets;
		std::cout << "HookFunctionOffsets g_Offsets = {" << std::endl;
		std::cout << "    /* SetUid */ 0x" << std::hex << o.SetUid << "," << std::endl;
		std::cout << "    /* SetFov */ 0x" << std::hex << o.SetFov << "," << std::endl;
		std::cout << "    /* SetFog */ 0x" << std::hex << o.SetFog << "," << std::endl;
		std::cout << "    /* GetFps */ 0x" << std::hex << o.GetFps << "," << std::endl;
		std::cout << "    /* SetFps */ 0x" << std::hex << o.SetFps << "," << std::endl;
		std::cout << "    /* OpenTeam */ 0x" << std::hex << o.OpenTeam << "," << std::endl;
		std::cout << "    /* OpenTeamAdvanced */ 0x" << std::hex << o.OpenTeamAdvanced << "," << std::endl;
		std::cout << "    /* CheckEnter */ 0x" << std::hex << o.CheckEnter << "," << std::endl;
		std::cout << "    /* QuestBanner */ 0x" << std::hex << o.QuestBanner << "," << std::endl;
		std::cout << "    /* FindObject */ 0x" << std::hex << o.FindObject << "," << std::endl;
		std::cout << "    /* ObjectActive */ 0x" << std::hex << o.ObjectActive << "," << std::endl;
		std::cout << "    /* CameraMove */ 0x" << std::hex << o.CameraMove << "," << std::endl;
		std::cout << "    /* DamageText */ 0x" << std::hex << o.DamageText << "," << std::endl;
		std::cout << "    /* TouchInput */ 0x" << std::hex << o.TouchInput << "," << std::endl;
		std::cout << "    /* KeyboardMouseInput */ 0x" << std::hex << o.KeyboardMouseInput << "," << std::endl;
		std::cout << "    /* JoypadInput */ 0x" << std::hex << o.JoypadInput << "," << std::endl;
		std::cout << "    /* CombineEntry */ 0x" << std::hex << o.CombineEntry << "," << std::endl;
		std::cout << "    /* CombineEntryPartner */ 0x" << std::hex << o.CombineEntryPartner << "," << std::endl;
		std::cout << "    /* SetupResinList */ 0x" << std::hex << o.SetupResinList << "," << std::endl;
		std::cout << "    /* ResinList */ 0x" << std::hex << o.ResinList << "," << std::endl;
		std::cout << "    /* FindString */ 0x" << std::hex << o.FindString << "," << std::endl;
		std::cout << "    /* PlayerPerspective */ 0x" << std::hex << o.PlayerPerspective << "," << std::endl;
		std::cout << "    /* IsObjectActive */ 0x" << std::hex << o.IsObjectActive << "," << std::endl;
		std::cout << "    /* GameUpdate */ 0x" << std::hex << o.GameUpdate << "," << std::endl;
		std::cout << "    /* Reserved */ 0, 0, 0, 0," << std::endl;
		std::cout << "    /* ActorManagerCtor */ 0x" << std::hex << o.ActorManagerCtor << "," << std::endl;
		std::cout << "    /* GetGlobalActor */ 0x" << std::hex << o.GetGlobalActor << "," << std::endl;
		std::cout << "    /* AvatarPaimonAppear */ 0x" << std::hex << o.AvatarPaimonAppear << "," << std::endl;
		std::cout << "    /* GetComponent */ 0x" << std::hex << o.GetComponent << "," << std::endl;
		std::cout << "    /* GetText */ 0x" << std::hex << o.GetText << "," << std::endl;
		std::cout << "    /* GetName */ 0x" << std::hex << o.GetName << "," << std::endl;
		std::cout << "    /* CheckCanOpenMap */ 0x" << std::hex << o.CheckCanOpenMap << "," << std::endl;
		std::cout << "    /* InLevelClockPageOkButtonClicked */ 0x" << std::hex << o.InLevelClockPageOkButtonClicked << "," << std::endl;
		std::cout << "    /* InLevelClockPageCloseButtonClicked */ 0x" << std::hex << o.InLevelClockPageCloseButtonClicked << "," << std::endl;
		std::cout << "    /* ClosePage */ 0x" << std::hex << o.ClosePage << "," << std::endl;
		std::cout << "};" << std::endl;
	}

	if (MH_EnableHook(MH_ALL_HOOKS) != MH_OK)
	{
		MH_Uninitialize();
		g_pEnv->State = IslandState::Error;
		return -1;
	}

	return 0;
}

void InitializeHookEnvironment()
{
	HANDLE hMapFile = OpenFileMappingW(FILE_MAP_READ | FILE_MAP_WRITE, FALSE, L"4F3E8543-40F7-4808-82DC-21E48A6037A7");
	if (hMapFile != NULL)
	{
		g_pEnv = (HookEnvironment*)MapViewOfFile(hMapFile, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, 0);
	}
}
