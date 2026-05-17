#include "CombineHotkey.h"
#include "../framework.h"
#include "../dllmain.h"
#include "../Cache.h"
#include "../Constants.h"
#include "HooksShared.h"

typedef Il2CppString* (*FindStringFn)(const char*);
typedef bool(*CraftEntryPartnerFn)(Il2CppString*, void*, void*, void*, void*);
typedef void(*CraftEntryFn)(void*);
typedef bool(*CheckCanOpenMapFn)(void*);
typedef bool(*CheckCanEnterFn)();

// Forward declarations for static helpers
static bool OpenCraftMenuCheck();
static bool DoOpenCraftMenu(bool check = false);

void CombineHotkey::Initialize()
{
    if (g_pEnv->Offsets.FindString)
    {
        findString = GetFunctionAddress(g_pEnv->Offsets.FindString);
    }

    if (g_pEnv->Offsets.CombineEntryPartner)
    {
        craftEntryPartner = GetFunctionAddress(g_pEnv->Offsets.CombineEntryPartner);
    }

    if (g_pEnv->Offsets.CombineEntry)
    {
        LPVOID craftEntryAddr = GetFunctionAddress(g_pEnv->Offsets.CombineEntry);
        if (craftEntryAddr)
        {
            MH_CreateHook(craftEntryAddr, &CombineHotkey::HookCraftEntry, &originalCraftEntry);
        }
    }

    if (g_pEnv->Offsets.CheckEnter)
    {
        checkCanEnter = GetFunctionAddress(g_pEnv->Offsets.CheckEnter);
    }

    // CheckCanOpenMap hook is managed by WeakMapCheck.
    // originalCheckCanOpenMap (set by WeakMapCheck::Initialize)
    // is used here via OpenCraftMenuCheck().
}

void CombineHotkey::OnUpdate()
{
    if (requestOpenCraft)
    {
        requestOpenCraft = false;
        DoOpenCraftMenu(true);
    }
}

void* CombineHotkey::GetHookFunction()
{
    return (void*)&CombineHotkey::HookCraftEntry;
}

bool CombineHotkey::IsEnabled()
{
    return g_pEnv->RedirectCombine != FALSE;
}

static bool OpenCraftMenuCheck()
{
    if (!originalCheckCanOpenMap || !checkCanEnter)
    {
        return false;
    }

    CheckCanOpenMapFn checkCanOpenMapFunc = (CheckCanOpenMapFn)originalCheckCanOpenMap;
    CheckCanEnterFn checkCanEnterFunc = (CheckCanEnterFn)checkCanEnter;

    return !(checkCanOpenMapFunc(nullptr) || !checkCanEnterFunc());
}

static bool DoOpenCraftMenu(bool check)
{
    if (check && !OpenCraftMenuCheck())
    {
        return false;
    }

    if (!findString || !craftEntryPartner)
    {
        return false;
    }

    FindStringFn findStringFunc = (FindStringFn)findString;
    CraftEntryPartnerFn craftEntryPartnerFunc = (CraftEntryPartnerFn)craftEntryPartner;

    Il2CppString* strObj = findStringFunc(SYNTHESIS_PAGE_NAME);

    if (strObj)
    {
        craftEntryPartnerFunc(strObj, nullptr, nullptr, nullptr, nullptr);
        return true;
    }

    return false;
}

void CombineHotkey::HookCraftEntry(void* pThis)
{
    if (g_pEnv->RedirectCombine && !CheckResistInBeyd() && DoOpenCraftMenu())
    {
        return;
    }

    if (originalCraftEntry)
    {
        CraftEntryFn original = (CraftEntryFn)originalCraftEntry;
        original(pThis);
    }
}
