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
	bool smaller_b_imp = false;
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
						++smaller_b_imp;
						if (some_task.left + some_task.duration < it->left + it->duration)
							for (int q = some_task.left+some_task.duration; q < it->left + it->duration; ++q)
								arr2[q] = 0;
						for (int q = it->left; q < it->left + it->duration; ++q)
						{
							if (q < some_task.left + some_task.duration)
								arr2[q] = some_task.importance;
						}
						if(some_task.left > it->left)
							it->duration = some_task.left - 1;
						j = it->left + it->duration;

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
				
				if (!smaller_b_imp)//делимое задание!!!!!!! 5559999555
					//попадание в большое задание
				{
					++smaller_b_imp;
					int k = some_task.left;
					while (k > 0)
					{
						if (arr2[k - 1] != 0)
						{
							for (std::vector<Task>::iterator jt = processed.begin(); jt < processed.end(); ++jt)
							{
								if (k - 1 == jt->left)
								{
									if (jt->divisibility == 0)
									{
										int old_dur = jt->duration;
										jt->duration = some_task.left;

										for (int q = some_task.left; q < some_task.left + some_task.duration; ++q)
											arr2[q] = some_task.importance;
										for (int q = some_task.left + some_task.duration; q < jt->left + old_dur; ++q)
											arr2[q] = 0;
									}
									break;
								}
							}
						}
						--k;
					}

					
					for (std::vector<Task>::iterator qt = not_processed.begin(); qt < not_processed.end(); ++qt)
					{
						if (*qt == some_task)
						{
							not_processed.erase(qt);
							break;
						}
					}
					for (std::vector<Task>::iterator jt = processed.begin(); jt < processed.end(); ++jt)
					{
						if (*jt == some_task)
							++already_added;
					}
					if (!already_added)
						processed.push_back(some_task);
					
				}
			}
			else if (some_task.importance < arr2[j])//imp2 < imp1
			{

			}
			++j;
		mark:;
		}
		
	}
}

