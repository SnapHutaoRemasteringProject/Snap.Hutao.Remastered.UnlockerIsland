#include "UnityUtils.h"
#include "../function/HooksShared.h"

typedef Il2CppString* (*FindStringFn)(const char*);
typedef void* (*FindGameObjectFn)(void*);

void* FindGameObject(const char* name)
{
    if (!findString || !findGameObject)
    {
        return nullptr;
    }

    FindStringFn findStringFunc = (FindStringFn)findString;
    void* strObj = findStringFunc(name);
    if (!strObj)
    {
        return nullptr;
    }

    FindGameObjectFn findGameObjectFunc = (FindGameObjectFn)findGameObject;
    return findGameObjectFunc(strObj);
}
