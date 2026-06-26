#include "Patch.h"
#include "MemoryUtils.h"

Patch::Patch(void* address, const char* patch, size_t count)
{
	this->m_address = address;
	this->m_patchBytes = patch;
	this->m_originalBytes = new char[count];
	this->m_count = count;
	this->m_isPatched = false;

	DWORD oldProtect;
	VirtualProtect(address, count, PAGE_EXECUTE_READWRITE, &oldProtect);

	memcpy(this->m_originalBytes, address, count);
}

void Patch::Apply()
{
	if (!m_isPatched)
	{
		memcpy(m_address, m_patchBytes, m_count);
		m_isPatched = true;
	}
}

void Patch::Revert()
{
	if (m_isPatched)
	{
		memcpy(m_address, m_originalBytes, m_count);
		m_isPatched = false;
	}
}

void Patch::SetIsPatched(bool isPatched)
{
	if (isPatched)
	{
		Apply();
	}
	else
	{
		Revert();
	}
}
