#include <iostream>
#include "manager.h"

int main()
{
	Manager man;
	//man.add_concrete_time(std::move(Task(5, 0, 10, 0, 1, 1, "some shit2")));
	//man.show_schedule();

	man.add_concrete_time(std::move(Task(7, 0, 4, 4, 1, 1, "some shit3")));
	//man.show_schedule();

	man.add_concrete_time(std::move(Task(5, 0, 5, 8, 1, 1, "some shit2")));
	man.add_concrete_time(std::move(Task(3, 0, 3, 9, 1, 1, "some shit4")));
	man.show_schedule();
	man.add_concrete_time(std::move(Task(9, 0, 9, 3, 0, 1,"some shit")));
	man.show_schedule();
	
	//man.add_abstract_task(std::move(Task(7, 1, 10, 0, 1, "shit")));

	//man.show_schedule();
	std::cin.get();
	return 0;
}