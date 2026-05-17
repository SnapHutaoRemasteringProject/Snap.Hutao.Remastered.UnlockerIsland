#include "FovOverride.h"
#include "../dllmain.h"

void FovOverride::Initialize()
{
    // SetFov hook is managed by Hooks.cpp (master dispatch hook)
}

void FovOverride::OnUpdate()
{
    // FOV override is applied directly in the master HookSetFov
    // because it modifies the function parameter before calling the original.
    // FPS and fog overrides from the same hook are handled by
    // EnableSetFps and DisableFog respectively.
}

bool FovOverride::IsEnabled()
{
    return g_pEnv->EnableSetFov != FALSE;
}
