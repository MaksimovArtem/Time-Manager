#include <iostream>
#include "manager.h"

int main()
{
	Manager man;
	man.add_concrete_time(std::move(Task(5, 0, 10, 0, 1, 0, "some shit1")));
	//man.show_schedule();
	man.add_concrete_time(std::move(Task(7, 0, 5, 3, 1, 1, "some shit2")));
	//man.show_schedule();
	man.add_concrete_time(std::move(Task(3, 0, 3, 9, 1, 1, "some shit3")));
	//man.show_schedule();
	man.add_concrete_time(std::move(Task(8, 0, 5, 3, 0, 1,"some shit4")));
	//man.show_schedule();
	man.add_concrete_time(std::move(Task(9, 0, 3, 0, 1, 1, "some shit5")));
	man.show_schedule();
	man.add_concrete_time(std::move(Task(9, 0, 5, 1, 1, 1, "some shit6")));
	//man.show_schedule();
	


	man.show_schedule();
	std::cin.get();
	std::cin.get();
	return 0;
}