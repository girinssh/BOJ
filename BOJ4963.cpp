#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

void BFS(int(*map)[50], int w, int h, int _x, int _y ) {
	queue<int> xL, yL;
	xL.push(_x);
	yL.push(_y);

	while (!xL.empty()) {
		int x = xL.front();
		int y = yL.front();

		map[y][x] = 0;

		xL.pop();
		yL.pop();

		for (int i = -1; i <= 1; i++) {
			if (i + y >= h || i + y < 0) 
				continue;
			for (int j = -1; j <= 1; j++) {
				if (j + x >= w || j + x < 0)
					continue;
				if (map[i + y][j + x] == 1) {
					map[i + y][j + x] = 0;
					xL.push(j + x);
					yL.push(i + y);
				}

			}
		}
	}
}

int search(int(*map)[50], int w, int h) {
	int count = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j] == 1) {
				BFS(map, w, h, j, i);
				count++;
			}
		}
	}
	return count;
}

int main(void) {

	cin.tie(NULL);
	cin.sync_with_stdio(false);

	while (true) {
		int w = 50, h= 50;
		int map[50][50] = { 0 };
		cin >> w >> h;

		if (w == 0 && h == 0)
			break;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				int val = 0;
				cin >> val;
				map[i][j] = val;
			}
		}

		cout << search(map, w, h) << '\n';
	}
	return 0;
}

// Flood Fill type problem