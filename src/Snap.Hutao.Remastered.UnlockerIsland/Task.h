#pragma once

#include <Windows.h>
#include <list>
#include <functional>

struct CriticalSectionInitializer
{
	CriticalSectionInitializer();
	~CriticalSectionInitializer();
};


class Task
{
public:
	static void RunLater(DWORD delayMs, std::function<void()> callback);
	static void Tick();
	static void ClearAll();

private:
	struct TaskItem
	{
		ULONGLONG executeTime;
		std::function<void()> callback;
	};

	static std::list<TaskItem> m_tasks;
	static CRITICAL_SECTION m_cs;

	static ULONGLONG GetCurrentTimeMs();
	static void ExecuteTasks(const std::list<TaskItem>& items);

	friend CriticalSectionInitializer;
};