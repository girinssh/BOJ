#include <iostream>
#include <algorithm>
#include <list>
#include <cmath>

using namespace std;

typedef struct Ant {
	int pos;
	int direction;
	int num;
}Ant;

bool cmp(const Ant& pos1, const Ant& pos2) {
	return pos1.pos < pos2.pos;
}

int main(void) {
	int N, L, t = 0;
	list<Ant> ants;
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> N >> L;

	for (int iter = 0; iter < N; iter++) {
		int ant;
		cin >> ant;
		Ant a = { abs(ant), ant < 0 ? -1 : 1, iter + 1 };
		ants.push_back(a);
	}
	ants.sort(cmp);

	while (1) {
		int size = ants.size();
		int distance = 1e9;
		for (list<Ant>::iterator iter = ants.begin(); iter != ants.end(); iter++) {
			int temp = 0;
			list<Ant>::iterator delta = iter;
			delta++;
			if (iter->direction == 1) {
				if (delta == ants.end()) {
					temp = L - iter->pos;
					if (temp < distance)
						distance = temp;
					continue;
				}
				else {
					while (delta != ants.end() && delta->direction != -1) {
						delta++;
					}
				}
			}
			else {
				if (iter == ants.begin()) {
					temp = iter->pos;
					if (temp < distance)
						distance = temp;
				}
				continue;
			}
			if (delta != ants.end()) {
				temp = (delta->pos - iter->pos) / 2;
				if (temp < distance)
					distance = temp;
			}
		}

		t += distance;

		for (list<Ant>::iterator iter = ants.begin(); iter != ants.end(); iter++) {
			list<Ant>::iterator delta = iter;
			delta++;
			if (delta != ants.end()) {
				int tempD = (delta->pos - iter->pos);
				if (tempD / 2 == distance && tempD % 2 == 1
					&& iter->direction == 1
					&& delta->direction == -1) {
					Ant newAnt1 = { iter->pos + distance, iter->direction * -1, iter->num };
					Ant newAnt2 = { iter->pos + distance, delta->direction * -1, delta->num };
					*iter = newAnt1;
					*delta = newAnt2;
					iter = delta;
					continue;
				}
				else if (iter->direction == 1
					&& delta->direction == -1) {
					Ant newAnt1 = { iter->pos + distance, iter->direction * -1, iter->num };
					Ant newAnt2 = { delta->pos - distance, delta->direction * -1, delta->num };
					*iter = newAnt1;
					*delta = newAnt2;
					iter = delta;
					continue;
				}
			}
			Ant newAnt1 = { iter->pos + distance * iter->direction, iter->direction, iter->num };
			*iter = newAnt1;

			if (iter->pos < 1 || iter->pos >= L) {
				if (ants.size() == 1) {
					cout << iter->num << ' ' << t;
				}
				list<Ant>::iterator temp = iter;
				if (ants.size() > 1) {
					if (iter == ants.begin())
						iter++;
					else
						iter--;
				}
				ants.erase(temp);
			}
			if (ants.size() == 0)
				break;
		}
		if (ants.size() == 0)
			break;
	}

	return 0;
}