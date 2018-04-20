#include "manager.h"

using namespace std;

manager::manager() {
	for (int i = 0; i < N; ++i) {
		day_schedule[i].set_num(i);
		for (int j = 0; j < M; ++j)
			mem_schedule[i][j] = false;
	}
};

void manager::add_conc_poss(task&& new_task) {
	int current_day = new_task.date;
	int current_dur = new_task.duration;
	int last = day_schedule[current_day].last_position;

	if (last + current_dur - M * (congestion + error) <= 0) {
		for (int p = last; p < current_dur + last; ++p)
			mem_schedule[current_day][p] = true;////manager mem
		day_schedule[current_day].add(new_task);////add in day

	} else {
		int new_time = day_schedule[current_day].manage(new_task);///rebuilding day schedule

		if (new_time >= 0)
			for (int y = 0; y < M; ++y) {
				if (y < new_time)
					mem_schedule[current_day][y] = true;
				else
					mem_schedule[current_day][y] = false;
			}
		else
			cout << "cant insert/manage the task " << new_task.description << " dur "
			     << current_dur << " importance " << new_task.importance << " in day " << current_day << endl;
	}
};

void manager::show() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			if (mem_schedule[i][j])
				cout << "\e[41m\e[30m" << mem_schedule[i][j] << "\e[0m";
			else
				cout << "\e[42m\e[37m" << mem_schedule[i][j] << "\e[0m";
		cout << endl;
	}
	for (int i = 0; i < N; ++i)
		day_schedule[i].show();
};
