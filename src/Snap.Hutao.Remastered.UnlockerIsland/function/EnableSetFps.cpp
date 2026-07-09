#include "EnableSetFps.h"
#include "../framework.h"
#include "../dllmain.h"
#include "../Cache.h"
#include "../Logger.h"
#include "../hook/HookWndProc.h"
#include "HooksShared.h"

typedef int(*GetFrameCountFn)();
typedef int(*SetFrameCountFn)(int);

void EnableSetFps::Initialize()
{
	if (g_pEnv->Offsets.GetFps)
	{
		LPVOID getFrameCountAddr = GetFunctionAddress(g_pEnv->Offsets.GetFps);
		if (getFrameCountAddr)
		{
			MH_CreateHook(getFrameCountAddr, &EnableSetFps::HookGetFrameCount, &originalGetFrameCount);
		}
	}

	if (g_pEnv->Offsets.SetFps)
	{
		setFrameCount = GetFunctionAddress(g_pEnv->Offsets.SetFps);
	}
}

void EnableSetFps::OnUpdate()
{
	if (!setFrameCount)
		return;

	SetFrameCountFn setFrameCountFunc = (SetFrameCountFn)setFrameCount;

	static bool lastResisted = false;
	bool isResisted = CheckResistInBeyd();

	if (isResisted && !lastResisted)
	{
		Log("[EnableSetFps] fps was resisted");
	}
	lastResisted = isResisted;

	if (g_pEnv->EnableSetFps)
	{
		HWND hWnd = GetUnityMainWindow();
		if (hWnd && IsIconic(hWnd))
		{
			// 窗口最小化时限制10帧
			setFrameCountFunc(10);
		}
		else if (isResisted)
		{
			// 千星奇域内锁60帧
			setFrameCountFunc(60);
		}
		else
		{
			setFrameCountFunc(g_pEnv->TargetFps);
		}
	}
}

void* EnableSetFps::GetHookFunction()
{
	return (void*)&EnableSetFps::HookGetFrameCount;
}

bool EnableSetFps::IsEnabled()
{
	return g_pEnv->EnableSetFps != FALSE;
}

int EnableSetFps::HookGetFrameCount()
{
	if (originalGetFrameCount)
	{
		GetFrameCountFn original = (GetFrameCountFn)originalGetFrameCount;
		int ret = original();
		if (ret >= 60) return 60;
		else if (ret >= 45) return 45;
		else if (ret >= 30) return 30;
		else return ret;
	}
	return 60;
}
