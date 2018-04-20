#ifndef TASK_H
#define TASK_H
#include <string>

class task {
public:
	task(int imp, int dat, int dur, std::string des):
		importance(imp), date(dat), duration(dur), ended(false), description(des) {};
	int importance;
	int date;
	int duration;
	bool ended;
	std::string description;
	bool operator<(const task &other) const {
		if (this->importance == other.importance)
			return this->duration > other.duration;
		else
			return this->importance < other.importance;
	};
	void make_done() {ended = true;};
};

#endif