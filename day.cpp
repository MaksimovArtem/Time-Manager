#include "day.h"

using namespace std;

void day::show() {
	sort(vec_tasks.begin(), vec_tasks.end());

	cout << "day " << day_number << ' ' << day_congestion << ": ";
	for (auto& a : vec_tasks)
		cout << a.description << '-' << a.duration << '-' << a.importance << ' ';
	cout << endl;
};

void day::add(task& new_task) {
	vec_tasks.push_back(new_task);///push into task vector
	day_congestion += (float)new_task.duration / M;
	last_position += new_task.duration;
};

int day::manage(task& new_task) {
	sort(vec_tasks.begin(), vec_tasks.end());

	int tmp = 0;
	int time = last_position;
	while (vec_tasks[tmp] < new_task) {///overloaded
		if (time + new_task.duration - vec_tasks[tmp].duration - M * (congestion + error) <= 0) {

			vec_tasks.erase(vec_tasks.begin(), vec_tasks.begin() + tmp);

			vec_tasks.push_back(new_task);
			last_position = time + new_task.duration - vec_tasks[tmp].duration;
			day_congestion = (float)last_position / M;

			return last_position;
		} else {
			time -= vec_tasks[tmp].duration;
			tmp++;
		}
	}
	return -1;
};