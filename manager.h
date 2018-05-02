#ifndef MANAGER_H
#define MANAGER_H

#include <array>
#include "settings.h"
#include "day.h"
#include "task.h"

class Manager 
{
	std::array<Day, N> schedule; // array of days
public:
	Manager();
	void show_schedule();
	void add_concrete_time(Task &&new_task);
	void add_abstract_task(Task &&new_task);

};

#endif