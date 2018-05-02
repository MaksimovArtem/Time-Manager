#include "day.h"
#include <iostream>
#include <vector>
Day::Day()
{
	for (auto &i : arr)
		i = false;
	for (auto &i : arr2)
		i = 0;
	day_congestion = 0;
	
}

void Day::set_num(int num)
{
	this->day_number = num;
}

void Day::show()
{

	std::cout << std::endl << "Day number: " << this->day_number << "; Congestion: " << this->day_congestion << std::endl;
	for (auto &i : arr2)
		std::cout << i << std::flush;

	std::cout << std::endl;

	
	std::cout << "Vec at all" << std::endl;
	for (auto &i : vec_tasks_at_all)
	{
		if (i.day_time == 0 || i.day_time == 1 || i.day_time == 2)
			i.print_abstract();
		else
			i.print();
	}
	std::cout << "Not processed" << std::endl;
	for (auto &i : not_processed)
	{
		if (i.day_time == 0 || i.day_time == 1 || i.day_time == 2)
			i.print_abstract();
		else
			i.print();
	}
	
	std::cout << "Processed" << std::endl;
	for (auto &i : processed)
	{
		if (i.day_time == 0 || i.day_time == 1 || i.day_time == 2)
			i.print_abstract();
		else
			i.print();
	}
	std::cout << std::endl;
}

void Day::add_task_concrete_time(Task &some_task)
{
	bool already_added = false;
	int sum = 0;

	for (int i = some_task.left; i < some_task.left + some_task.duration; ++i)
		sum += arr2[i];//проверка есть ли что-то
	
	if (sum == 0)//нет
	{
		for (int i = some_task.left; i < some_task.left + some_task.duration; ++i)
			arr2[i] = some_task.importance;
		not_processed.erase(not_processed.end() - 1);
		processed.push_back(some_task);
	}
	else if (sum != 0)//есть
	{
		int j = some_task.left;
		while (j < some_task.left + some_task.duration)
		{
			if (some_task.importance > arr2[j])//imp2 > imp1
			{
				arr2[j] = some_task.importance;
				for (std::vector<Task>::iterator it = processed.begin(); it < processed.end(); ++it)//то, что закрыл - вернуть в вектор необработанных
				{
					if (j == it->left)
					{
						for (j = it->left; j < it->left + it->duration; ++j)
							arr2[j] = some_task.importance;

						j = it->left + it->duration; //-1?

						not_processed.push_back(*it);
						processed.erase(it);
						
						for (std::vector<Task>::iterator jt = processed.begin(); jt < processed.end(); ++jt)
						{
							if (*jt == some_task)
								++already_added;
						}
						if (!already_added)
							processed.push_back(some_task);

						for (std::vector<Task>::iterator qt = not_processed.begin(); qt < not_processed.end(); ++qt)
						{
							if (*qt == some_task)
							{
								not_processed.erase(qt);
								break;
							}
						}
						goto mark;
					}
				}

				//еще обработка
			}
			else if (some_task.importance < arr2[j])//imp2 < imp1
			{

			}
			++j;
		mark:;
		}
		
	}
}

