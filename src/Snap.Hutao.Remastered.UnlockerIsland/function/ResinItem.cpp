#include "ResinItem.h"
#include "../framework.h"
#include "../dllmain.h"
#include "../Logger.h"
#include "HooksShared.h"

#include <vector>
#include <string>

typedef void (*SetupResinListFn)(void*);

void ResinItem::Initialize()
{
    if (g_pEnv->Offsets.SetupResinList)
    {
        LPVOID setupResinListAddr = GetFunctionAddress(g_pEnv->Offsets.SetupResinList);
        if (setupResinListAddr)
        {
            MH_CreateHook(setupResinListAddr, &ResinItem::HookSetupResinList, &originalSetupResinList);
        }
    }
}

void* ResinItem::GetHookFunction()
{
    return (void*)&ResinItem::HookSetupResinList;
}

bool ResinItem::IsEnabled()
{
    // Resin filtering is enabled if any resin item toggle is active
    return !g_pEnv->ResinItem000106 || !g_pEnv->ResinItem000201 ||
           !g_pEnv->ResinItem107009 || !g_pEnv->ResinItem107012 ||
           !g_pEnv->ResinItem220007;
}

void ResinItem::HookSetupResinList(void* pThis)
{
    SetupResinListFn original = (SetupResinListFn)originalSetupResinList;
    original(pThis);

    Il2CppList<ULONG64>* resinList = *(Il2CppList<ULONG64>**)((intptr_t)pThis + g_pEnv->Offsets.ResinList);
    std::vector<ULONG64> toRemove;

    for (int i = 0; i < resinList->Count(); i++)
    {
        ULONG64 item = resinList->Get(i);
        Log("item=" + std::to_string(item) + ";len=" + std::to_string(resinList->Count()));

        UINT32 hight = (UINT32)(item >> 32);
        UINT32 low = (UINT32)(item & 0xFFFFFFFF);

        if ((hight == 106 || low == 106) && !g_pEnv->ResinItem000106
            || (hight == 201 || low == 201) && !g_pEnv->ResinItem000201
            || (hight == 107009 || low == 107009) && !g_pEnv->ResinItem107009
            || (hight == 107012 || low == 107012) && !g_pEnv->ResinItem107012
            || (hight == 220007 || low == 220007) && !g_pEnv->ResinItem220007)
        {
            toRemove.push_back(item);
        }
    }

    for (ULONG64 item : toRemove)
    {
        if (item == 0) continue;
        resinList->Remove(item);
        Log(std::to_string(item) + " was Removed");
    }
}
