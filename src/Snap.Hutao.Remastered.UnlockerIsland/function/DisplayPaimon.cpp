#include "DisplayPaimon.h"
#include "../framework.h"
#include "../dllmain.h"
#include "../Constants.h"
#include "../utils/UnityUtils.h"
#include "../Logger.h"
#include "HooksShared.h"

typedef void(*CtorFn)(void*);
typedef void* (*GetGlobalActorFn)(void*);
typedef void(*AvatarPaimonAppearFn)(void*, void*, bool);
typedef void(*SetActiveFn)(void*, bool);
typedef bool(*GetActiveFn)(void*);

void DisplayPaimon::Initialize()
{
    if (g_pEnv->Offsets.IsObjectActive)
    {
        getActive = GetFunctionAddress(g_pEnv->Offsets.IsObjectActive);
    }

    if (g_pEnv->Offsets.ActorManagerCtor)
    {
        LPVOID actorManagerCtorAddr = GetFunctionAddress(g_pEnv->Offsets.ActorManagerCtor);
        if (actorManagerCtorAddr)
        {
            MH_CreateHook(actorManagerCtorAddr, &DisplayPaimon::HookActorManagerCtor, &originalActorManagerCtor);
        }
    }

    if (g_pEnv->Offsets.GetGlobalActor)
    {
        getGlobalActor = GetFunctionAddress(g_pEnv->Offsets.GetGlobalActor);
    }

    if (g_pEnv->Offsets.AvatarPaimonAppear)
    {
        avatarPaimonAppear = GetFunctionAddress(g_pEnv->Offsets.AvatarPaimonAppear);
    }
}

void DisplayPaimon::OnUpdate()
{
    if (!g_pEnv->DisplayPaimon)
    {
        return;
    }

    if (!getGlobalActor || !getActive || !avatarPaimonAppear)
    {
        return;
    }

    if (!actorManager)
    {
        return;
    }

    GetGlobalActorFn getGlobalActorFunc = (GetGlobalActorFn)getGlobalActor;
    GetActiveFn getActiveFunc = (GetActiveFn)getActive;

    void* paimonObj = FindGameObject(PAIMON_PATH);
    void* divePaimonObj = FindGameObject(DIVE_PAIMON_PATH);
    void* beydPaimonObj = FindGameObject(BEYD_PAIMON_PATH);

    if (!paimonObj || !divePaimonObj || !beydPaimonObj)
    {
        return;
    }

    if (getActiveFunc(paimonObj) || getActiveFunc(divePaimonObj) || getActiveFunc(beydPaimonObj))
    {
        return;
    }

    void* globalActor = getGlobalActorFunc(actorManager);

    if (globalActor)
    {
        AvatarPaimonAppearFn avatarPaimonAppearFunc = (AvatarPaimonAppearFn)avatarPaimonAppear;
        avatarPaimonAppearFunc(globalActor, nullptr, true);
    }
}

void* DisplayPaimon::GetHookFunction()
{
    return (void*)&DisplayPaimon::HookActorManagerCtor;
}

bool DisplayPaimon::IsEnabled()
{
    return g_pEnv->DisplayPaimon != FALSE;
}

void DisplayPaimon::HookActorManagerCtor(void* pThis)
{
    CtorFn original = (CtorFn)originalActorManagerCtor;
    actorManager = pThis;
    original(pThis);
}
