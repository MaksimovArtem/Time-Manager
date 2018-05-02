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

	for (int i = some_task.left; i < some_task.left + some_task.duration; ++i)//проверка есть ли что-то
		sum += arr2[i];
	
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
						++smaller_b_imp;//не часть большего. Случай 1
						if (some_task.left + some_task.duration < it->left + it->duration)
							for (int q = some_task.left+some_task.duration; q < it->left + it->duration; ++q)
								arr2[q] = 0;
						for (int q = it->left; q < it->left + it->duration; ++q)
						{
							if (q < some_task.left + some_task.duration)
								arr2[q] = some_task.importance;
						}
						if(some_task.left > it->left)
							it->duration = some_task.left;

						j = it->left + it->duration;

						not_processed.push_back(*it);
						processed.erase(it);
						
						for (std::vector<Task>::iterator jt = processed.begin(); jt < processed.end(); ++jt)//добавление в вектор обработанных
						{
							if (*jt == some_task)
								++already_added;
						}
						if (!already_added)
							processed.push_back(some_task);

						for (std::vector<Task>::iterator qt = not_processed.begin(); qt < not_processed.end(); ++qt)//удаление из вектора необработанных
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
				
				if (!smaller_b_imp)//попадание в большое задание Случай 2
				{
					++smaller_b_imp;
					int k = some_task.left;
					while (k > 0)//иду влево, определяю задание, куда попал
					{
						if (arr2[k - 1] != 0)
						{
							for (std::vector<Task>::iterator jt = processed.begin(); jt < processed.end(); ++jt)
							{
								if (k - 1 == jt->left)
								{
									if (jt->divisibility == 0)//если неделимое, то режь
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
					j = some_task.left + some_task.duration;
					for (std::vector<Task>::iterator qt = not_processed.begin(); qt < not_processed.end(); ++qt)//удаление из вектора необр
					{
						if (*qt == some_task)
						{
							not_processed.erase(qt);
							break;
						}
					}
					for (std::vector<Task>::iterator jt = processed.begin(); jt < processed.end(); ++jt)//добавление в вектор обработанных
					{
						if (*jt == some_task)
							++already_added;
					}
					if (!already_added)
						processed.push_back(some_task);
					
				}
			}
			else if (some_task.importance == arr2[j])//imp2 = imp1
			{
				char choice;
				bool found = false;
				for (std::vector<Task>::iterator it = processed.begin(); it < processed.end(); ++it)
				{
					if (some_task.importance == it->importance && it->day_time == 228)//вставка по времени
					{
						std::cout << "Do you want to stay:\n" << some_task.description << "\nor \n" << it->description << " ?\n" << std::endl;
						std::cout << "Press 1 to choose " << it->description << ". Press 2 to choose " << some_task.description << ". Press F to pay respect." << std::endl;
						std::cin >> choice;
						switch (choice)
						{
						case '1':
							
							break;
						case '2':
							if (some_task.left == it->left)
							{
								if (some_task.left + some_task.duration < it->left + it->duration)
									for (int q = some_task.left + some_task.duration; q < it->left + it->duration; ++q)
										arr2[q] = 0;

								if (it->duration < some_task.duration)
									j = some_task.left + it->duration;
								else
									j = some_task.left + some_task.duration;

								not_processed.push_back(*it);//удаления/добавления
								processed.erase(it);
								not_processed.erase(not_processed.end() - 1);
								processed.push_back(some_task);
								
								++found;
								break;
							}
							else if (some_task.left > it->left)
							{
								j =  it->left + it->duration-1;
								it->duration = some_task.left;
								if(it->divisibility == 0)
									for (int q = it->left; q < it->left + it->duration; ++q)
										arr2[q] == 0;
								for (int q = some_task.left; q < it->left+it->duration; ++q)
									arr2[q] = some_task.importance;
								not_processed.erase(not_processed.end() - 1);
								processed.push_back(some_task);
								
								
								++found;
								break;
							}
							else if (some_task.left < it->left)
							{
								for (int q = some_task.left; q < some_task.left + some_task.duration; ++q)
									arr2[q] = some_task.importance;
								for (int q = some_task.left + some_task.duration; q < it->left + it->duration; ++q)
									arr2[q] = 0;
								not_processed.push_back(*it);
								processed.erase(it);
								not_processed.erase(not_processed.end() - 1);
								processed.push_back(some_task);
								j = some_task.left + some_task.duration;
								++found;
								break;
							}
							break;
						}
					}
					if (found)
						break;
				}
			}
			++j;
		mark:;
		}
		
	}
}

