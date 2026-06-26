#pragma once

class Patch
{
public:
	Patch(void* address, const char* patch, size_t count);
	void Apply();
	void Revert();
	void SetIsPatched(bool isPatched);

private:
	void* m_address;
	size_t m_count;
	const char* m_patchBytes;
	char* m_originalBytes;
	bool m_isPatched;
};