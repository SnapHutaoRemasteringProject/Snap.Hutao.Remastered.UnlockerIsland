#include "DisableCameraMove.h"
#include "../framework.h"
#include "../dllmain.h"
#include "../Cache.h"
#include "HooksShared.h"

typedef bool(*EventCameraMoveFn)(void*, void*);

void DisableCameraMove::Initialize()
{
    if (g_pEnv->Offsets.CameraMove)
    {
        LPVOID eventCameraMoveAddr = GetFunctionAddress(g_pEnv->Offsets.CameraMove);
        if (eventCameraMoveAddr)
        {
            MH_CreateHook(eventCameraMoveAddr, &DisableCameraMove::HookEventCameraMove, &originalEventCameraMove);
        }
    }
}

void* DisableCameraMove::GetHookFunction()
{
    return (void*)&DisableCameraMove::HookEventCameraMove;
}

bool DisableCameraMove::IsEnabled()
{
    return g_pEnv->DisableCameraMove != FALSE;
}

bool DisableCameraMove::HookEventCameraMove(void* pThis, void* event)
{
    if (g_pEnv->DisableCameraMove && !CheckResistInBeyd())
    {
        return true;
    }

    if (originalEventCameraMove)
    {
        EventCameraMoveFn original = (EventCameraMoveFn)originalEventCameraMove;
        return original(pThis, event);
    }
    return true;
}
