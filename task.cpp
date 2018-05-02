#include "task.h"
#include "iostream"
Task::Task(int prior_, int day_, int duration_, int left_,int day_time_, bool div_, std::string description_) :
	importance(prior_), day(day_), duration(duration_), left(left_), day_time(228), divisibility(div_),  description(description_)
{}
Task::Task(int prior_, int day_, int duration_, int day_time_, bool div_, std::string description_) :
	importance(prior_), day(day_), duration(duration_), day_time(day_time_), divisibility(div_), description(description_)
{}

bool Task::operator<( const Task &other_task) const
{
	if (this->importance == other_task.importance)
		return this->duration > other_task.duration;
	else
		return this->importance < other_task.importance;
}

bool Task::operator==(const Task &other_task) const
{
	if (this->day == other_task.day &&
		this->day_time == other_task.day_time &&
		this->description == other_task.description &&
		this->divisibility == other_task.divisibility &&
		this->duration == other_task.duration &&
		this->importance == other_task.importance &&
		this->left == other_task.left)
		return true;
	else
		return false;
}

void Task::print()
{
	std::cout << this->description << "; Time:" << this->left << "; Duration: " << this->duration << std::endl;
}

void Task::print_abstract()
{
	if (this->day_time == 0)
		std::cout << this->description << "; Day time: Morning; Duration: " << this->duration << std::endl;
	else if (this->day_time == 1)
		std::cout << this->description << "; Day time: Evening; Duration: " << this->duration << std::endl;
	else if (this->day_time == 2)
		std::cout << this->description << "; Day time: Who cares; Duration: " << this->duration << std::endl;
}