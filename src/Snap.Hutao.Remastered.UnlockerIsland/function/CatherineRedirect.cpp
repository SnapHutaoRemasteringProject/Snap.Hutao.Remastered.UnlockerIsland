#include "CatherineRedirect.h"
#include "../framework.h"
#include "../dllmain.h"
#include "../BeyondResist.h"
#include "../Logger.h"
#include "HooksShared.h"
#include "../utils/MemoryUtils.h"

#include <cstddef>

bool CatherineRedirect::s_redirecting = false;
void* CatherineRedirect::s_dialogSystem = nullptr;
uint32_t CatherineRedirect::s_callCount = 0;

void CatherineRedirect::Initialize()
{
    if (g_pEnv->Offsets.CatherineEntry)
    {
        LPVOID catherineEntryAddr = GetFunctionAddress(g_pEnv->Offsets.CatherineEntry);
        if (catherineEntryAddr)
        {
            MH_CreateHook(catherineEntryAddr, &CatherineRedirect::HookCatherineEntry, &originalCatherineEntry);
        }
    }

    if (g_pEnv->Offsets.CatherineOpenDialog)
    {
        catherineOpenDialog = GetFunctionAddress(g_pEnv->Offsets.CatherineOpenDialog);
    }

    if (g_pEnv->Offsets.CatherineDialogCtor)
    {
        LPVOID catherineDialogCtorAddr = GetFunctionAddress(g_pEnv->Offsets.CatherineDialogCtor);
        if (catherineDialogCtorAddr)
        {
            MH_CreateHook(catherineDialogCtorAddr, &CatherineRedirect::HookDialogCtor, &originalCatherineDialogCtor);
        }
    }

    if (g_pEnv->Offsets.ExplorationEntry)
    {
        explorationPageEntry = GetFunctionAddress(g_pEnv->Offsets.ExplorationEntry);
    }

    if (!findString && g_pEnv->Offsets.FindString)
    {
        findString = GetFunctionAddress(g_pEnv->Offsets.FindString);
    }
}

void* CatherineRedirect::GetHookFunction()
{
    return (void*)&CatherineRedirect::HookCatherineEntry;
}

bool CatherineRedirect::IsEnabled()
{
    return IsRedirectEnabled();
}

bool CatherineRedirect::IsRedirectEnabled()
{
    if (g_pEnv == nullptr)
    {
        return false;
    }

    return g_pEnv->RedirectCatherine != FALSE;
}


bool CatherineRedirect::OpenDialog()
{
    if (s_dialogSystem == nullptr)
    {
        Log("CatherineRedirect: dialog system not captured yet - falling back to the original flow");
        return false;
    }

    if (catherineOpenDialog == nullptr)
    {
        return false;
    }

    const int32_t idx = 0;

    __try
    {
        ((CatherineOpenDialogFn)catherineOpenDialog)(s_dialogSystem, idx);
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        return false;
    }
    return true;
}

bool CatherineRedirect::OpenExplorationPage()
{
    if (explorationPageEntry == nullptr)
    {
        return false;
    }

    if (findString == nullptr)
    {
        return false;
    }

    Il2CppString* pageId = ((FindStringFn)findString)(EXPLORATION_PAGE_ID);
    if (pageId == nullptr)
    {
        return false;
    }

    bool opened = false;

    __try
    {
        opened = ((ExplorationEntryFn)explorationPageEntry)(nullptr, pageId);
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
        return false;
    }

    return opened;
}

void CatherineRedirect::HookCatherineEntry(void* self)
{
    const bool odd = ((++s_callCount) & 1u) != 0u;
    bool handled = false;

    if (IsRedirectEnabled() && !s_redirecting && !CheckResistInBeyd())
    {
        s_redirecting = true;
        handled = odd ? OpenExplorationPage() : OpenDialog();
        s_redirecting = false;
    }


    if (!handled && originalCatherineEntry != nullptr)
    {
        ((CatherineEntryFn)originalCatherineEntry)(self);
    }
}

void CatherineRedirect::HookDialogCtor(void* self, void* method)
{
    if (self != nullptr && s_dialogSystem == nullptr)
    {
        s_dialogSystem = self;
        Logf("CatherineRedirect: dialog system captured from ctor (%p)", self);
    }

    if (originalCatherineDialogCtor != nullptr)
    {
        ((CatherineDialogCtorFn)originalCatherineDialogCtor)(self, method);
    }
}
