#ifndef DAY_H
#define DAY_H
#include <vector>
#include <iostream>
#include <algorithm>
#include "settings.h"
#include "task.h"

class day {
public:
	int day_number;
	float day_congestion;
	int last_position;
	std::vector <task> vec_tasks;
	day(): day_number(0), day_congestion(0.0), last_position(0) {};
	void show();
	void set_num(int num) {day_number = num;};
	void add(task& new_task);
	int manage(task& new_task);///(doesnt work as it should yet)
};
#endif