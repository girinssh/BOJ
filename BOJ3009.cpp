#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(void) {
	map<int, int> (pos[2]);
	int p[2] = { 0 };
	for (int i = 0; i < 3; i++) {
		int tx, ty;
		cin >> tx >> ty;

		pos[0][tx]++;
		pos[1][ty]++;
	}
	
	map<int, int>::iterator iter;

	for (int i = 0; i < 2; i++) {
		iter = pos[i].begin();
		while (iter != (pos[i]).end()) {
			if (iter->second == 1) {
				p[i] = iter->first;
				break;
			}
			iter++;
		}
	}
	
	cout << p[0] << ' ' << p[1];

	return 0;
}