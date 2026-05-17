#include "InLevelClockPageSpeedUp.h"
#include "../framework.h"
#include "../dllmain.h"
#include "../Logger.h"
#include "../utils/Task.h"
#include "HooksShared.h"

typedef void (*ButtonClickedFn)(void*);

void InLevelClockPageSpeedUp::Initialize()
{
    if (g_pEnv->Offsets.InLevelClockPageOkButtonClicked)
    {
        LPVOID inLevelClockPageOkButtonClickedAddr = GetFunctionAddress(g_pEnv->Offsets.InLevelClockPageOkButtonClicked);
        if (inLevelClockPageOkButtonClickedAddr)
        {
            MH_CreateHook(inLevelClockPageOkButtonClickedAddr, &InLevelClockPageSpeedUp::HookInLevelClockPageOkButtonClicked, &originalInLevelClockPageOkButtonClicked);
        }
    }

    if (g_pEnv->Offsets.InLevelClockPageCloseButtonClicked)
    {
        inLevelClockPageCloseButtonClicked = GetFunctionAddress(g_pEnv->Offsets.InLevelClockPageCloseButtonClicked);
    }
}

void* InLevelClockPageSpeedUp::GetHookFunction()
{
    return (void*)&InLevelClockPageSpeedUp::HookInLevelClockPageOkButtonClicked;
}

bool InLevelClockPageSpeedUp::IsEnabled()
{
    return g_pEnv->InLevelClockPageSpeedUp != FALSE;
}

void InLevelClockPageSpeedUp::HookInLevelClockPageOkButtonClicked(void* pThis)
{
    ButtonClickedFn original = (ButtonClickedFn)originalInLevelClockPageOkButtonClicked;

    if (g_pEnv->InLevelClockPageSpeedUp && inLevelClockPageCloseButtonClicked)
    {
        ButtonClickedFn inLevelClockPageCloseButtonClickedFunc = (ButtonClickedFn)inLevelClockPageCloseButtonClicked;
        Log("InLevelClockPage Speed Up");
        Task::RunLater(100, [pThis]()
            {
                (*(void(__fastcall**)(void*, int64_t))(*(int64_t*)pThis + g_pEnv->Offsets.ClosePage))(pThis, 0i64);
            });
    }
    original(pThis);
}
