#include "manager.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

	manager man;
	string s{ "taskX" };
	srand(time(0));
	for (int i = 0; i < 100; ++i) {
		s[s.size() - 1] = char(i + 65);
		man.add_conc_poss(move(task(rand() % 5 + 1, rand() % N, rand() % 20 + 1, s)));
	}
	/*man.add_conc_poss(move(task(0, 0, 20, s)));
	man.add_conc_poss(move(task(1, 0, 20, s)));
	man.add_conc_poss(move(task(1, 0, 12, s)));
	man.add_conc_poss(move(task(4, 0, 20, s)));

	man.add_conc_poss(move(task(3, 0, 35, s)));*/

	man.show();
	cin.get();
	return 0;
}