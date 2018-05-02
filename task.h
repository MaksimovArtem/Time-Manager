#ifndef TASK_H
#define TASK_H

#include <string>
class Task
{
public:
	int importance;
	int day;
	int duration;
	int left;
	int day_time;
	bool divisibility;
	std::string description;

public:
	Task(int imp, int day, int dur, int l, int day_t, bool div, std::string);
	Task(int imp, int day, int dur, int day_t, bool div, std::string);
	bool operator<(const Task &other_task) const;
	bool operator==(const Task &other_task) const;
	void print();
	void print_abstract();

};

#endif