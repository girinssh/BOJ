#include <iostream>
#include <algorithm>

using namespace std;

int map[100][100] = { 0 };

int main(void) {
	int count = 0;
	int t;

	cin >> t;

	while (t--) {
		int x, y;
		cin >> x >> y;

		x -= 1;
		y -= 1;

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (map[y + i][x + j] == 0)
					count++;
				map[y + i][x + j] = 1;
			}
		}
	}

	cout << count;
	return 0;
}