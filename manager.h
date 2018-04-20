#ifndef MANAGER_H
#define MANAGER_H
#include <vector>
#include <iostream>
#include "settings.h"
#include "day.h"
#include "task.h"

class manager {
public:
	bool mem_schedule[N][M];
	day day_schedule[N];
	manager();
	void show();
	void add_conc_poss(task&& new_task);///concrete task in concrete day if possible(works)
	void add_in_week(task&& new_task);///find a day and add if possible(doesnt work yet)
	void manage();////(doesnt work yet)
};
#endif