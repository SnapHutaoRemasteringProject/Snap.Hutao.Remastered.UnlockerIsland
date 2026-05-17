#include "Task.h"

#include <Windows.h>
#include <functional>
#include <list>
#include <utility>

std::list<Task::TaskItem> Task::m_tasks;
CRITICAL_SECTION Task::m_cs;
CriticalSectionInitializer g_csInitializer;


CriticalSectionInitializer::CriticalSectionInitializer()
{
	InitializeCriticalSection(&Task::m_cs);
}
CriticalSectionInitializer::~CriticalSectionInitializer()
{
	DeleteCriticalSection(&Task::m_cs);
}


void Task::RunLater(DWORD delayMs, std::function<void()> callback)
{
	if (!callback)
		return;

	ULONGLONG execTime = GetCurrentTimeMs() + static_cast<ULONGLONG>(delayMs);
	TaskItem item{ execTime, std::move(callback) };

	EnterCriticalSection(&m_cs);
	m_tasks.push_back(std::move(item));
	LeaveCriticalSection(&m_cs);
}

void Task::Tick()
{
	ULONGLONG now = GetCurrentTimeMs();
	std::list<TaskItem> readyList;

	EnterCriticalSection(&m_cs);
	for (auto it = m_tasks.begin(); it != m_tasks.end(); )
	{
		if (it->executeTime <= now)
		{
			readyList.push_back(std::move(*it));
			it = m_tasks.erase(it);
		}
		else
		{
			++it;
		}
	}
	LeaveCriticalSection(&m_cs);

	if (!readyList.empty())
	{
		for (auto& task : readyList)
		{
			if (task.callback)
				task.callback();
		}
	}
}

void Task::ClearAll()
{
	EnterCriticalSection(&m_cs);
	m_tasks.clear();
	LeaveCriticalSection(&m_cs);
}

ULONGLONG Task::GetCurrentTimeMs()
{
	return ::GetTickCount64();
}