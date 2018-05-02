#include "manager.h"
#include <iostream>


Manager::Manager()
{
	for (int i = 0; i < N; ++i)
		schedule[i].set_num(i);
}

void Manager::show_schedule()
{
	for (auto &i : schedule)
		i.show();
}

void Manager::add_concrete_time(Task &&some_task)
{
	try
	{
		if (some_task.left < 0)
			throw 1;
		if (some_task.left + some_task.duration > M)
			throw 2;
	}
	catch (int i)
	{
		if (i == 1)
		{
			std::cout << "Bad input" << std::endl;
			some_task.left = 0;
		}
		if (i == 2)
		{
			std::cout << "Not enough space" << std::endl;
			some_task.duration = M - some_task.left;
		}
	}
	schedule[some_task.day].vec_tasks_at_all.push_back(some_task);
	schedule[some_task.day].not_processed.push_back(some_task);
	schedule[some_task.day].add_task_concrete_time(some_task);
}

void Manager::add_abstract_task(Task &&some_task)
{
	if (some_task.day_time == 0)
	{
		for (int j = 0; j < M / 2; ++j)
		{
			if (schedule[some_task.day].arr2[j] == 0)
				some_task.left = j;
		}
	}

	schedule[some_task.day].vec_tasks_at_all.push_back(some_task);
	schedule[some_task.day].not_processed.push_back(some_task);
}