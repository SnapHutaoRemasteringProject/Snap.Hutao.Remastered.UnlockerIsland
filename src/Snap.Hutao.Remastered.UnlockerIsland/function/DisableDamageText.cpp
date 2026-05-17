#include "DisableDamageText.h"
#include "../framework.h"
#include "../dllmain.h"
#include "../Cache.h"
#include "HooksShared.h"

typedef void(*ShowOneDamageTextExFn)(void*, int, int, int, float, Il2CppString*, void*, void*, int);

void DisableDamageText::Initialize()
{
    if (g_pEnv->Offsets.DamageText)
    {
        LPVOID showOneDamageTextExAddr = GetFunctionAddress(g_pEnv->Offsets.DamageText);
        if (showOneDamageTextExAddr)
        {
            MH_CreateHook(showOneDamageTextExAddr, &DisableDamageText::HookShowOneDamageTextEx, &originalShowOneDamageTextEx);
        }
    }
}

void* DisableDamageText::GetHookFunction()
{
    return (void*)&DisableDamageText::HookShowOneDamageTextEx;
}

bool DisableDamageText::IsEnabled()
{
    return g_pEnv->DisableDamageText != FALSE;
}

void DisableDamageText::HookShowOneDamageTextEx(void* pThis, int type_, int damageType, int showType, float damage, Il2CppString* showText, void* worldPos, void* attackee, int elementReactionType)
{
    if (g_pEnv->DisableDamageText && !CheckResistInBeyd())
    {
        return;
    }

    if (originalShowOneDamageTextEx)
    {
        ShowOneDamageTextExFn original = (ShowOneDamageTextExFn)originalShowOneDamageTextEx;
        original(pThis, type_, damageType, showType, damage, showText, worldPos, attackee, elementReactionType);
    }
}
