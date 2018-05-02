#ifndef DAY_H
#define DAY_H

#include <array>
#include <vector>

#include  "settings.h"
#include "task.h"
class Day
{
public:
	std::array<bool, M> arr;
	std::array<int, M> arr2;
	int day_number;
	float day_congestion;
	std::vector<Task> vec_tasks_at_all{};
	std::vector<Task> not_processed{};
	std::vector<Task> processed{};
public:
	Day();
	void show();
	void add_task_concrete_time(Task &);
	void set_num(int);


};
#endif