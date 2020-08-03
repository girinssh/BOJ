#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int minCantSeeArea = 1e9;

void paint(int(*map)[8], int direction, int x, int y, int isX, int h, int w) {
	int deltaPos = 1;
	if (isX == 1) {
		while (x + deltaPos * direction >= 0 && x + deltaPos * direction < w) {
			if (map[y][x + deltaPos * direction] == 6)
				break;
			else if (map[y][x + deltaPos * direction] == 0) {
				map[y][x + deltaPos * direction] = -1;
			}
			deltaPos++;
		}
	}
	else {
		while (y + deltaPos * direction >= 0 && y + deltaPos * direction < h) {
			if (map[y + deltaPos * direction][x] == 6)
				break;
			else if (map[y + deltaPos * direction][x] == 0) {
				map[y + deltaPos * direction][x] = -1;
			}
			deltaPos++;
		}
	}
}

void rec(int(*map)[8], vector<pair<int, int>> cctvPos, int h, int w) {
	if (cctvPos.size() == 0) {
		int count = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 0)
					count++;
			}
		}
		if (count < minCantSeeArea)
			minCantSeeArea = count;
	}
	else {
		int x = cctvPos.front().first;
		int y = cctvPos.front().second;
		cctvPos.erase(cctvPos.begin());

		int cctv = map[y][x];

		if (cctv == 1) {
			int direction = 1;
			for (int i = 0; i < 4; i++) {
				int tempMap[8][8] = { 0 };

				memcpy(tempMap, map, sizeof(int) * 8 * 8);

				if (i % 2 == 0) {
					if (i / 2 == 1)
						direction = -1;
					paint(tempMap, direction, x, y, 1, h, w);
				}
				else {
					paint(tempMap, direction, x, y, 0, h, w);
				}
				rec(tempMap, cctvPos, h, w);
			}
		}

		else if (cctv == 2) {
			int axis = 1;

			for (int i = 0; i < 2; i++) {
				int tempMap[8][8] = { 0 };

				memcpy(tempMap, map, sizeof(int) * 8 * 8);

				paint(tempMap, 1, x, y, axis, h, w);
				paint(tempMap, -1, x, y, axis, h, w);
				rec(tempMap, cctvPos, h, w);

				axis *= -1;
			}
		}
		else if (cctv == 3) {
			int directionX = 1, directionY = -1;
			for (int i = 0; i < 4; i++) {
				int tempMap[8][8] = { 0 };

				memcpy(tempMap, map, sizeof(int) * 8 * 8);

				if (i % 2 == 1) {
					directionX *= -1;
				}
				else {
					directionY *= -1;
				}

				paint(tempMap, directionX, x, y, 1, h, w);
				paint(tempMap, directionY, x, y, 0, h, w);

				rec(tempMap, cctvPos, h, w);
			}
		}
		else if (cctv == 4) {
			int direction1 = 1, direction2 = -1;
			int axis = 1;

			for (int i = 0; i < 4; i++) {
				int tempMap[8][8] = { 0 };

				memcpy(tempMap, map, sizeof(int) * 8 * 8);

				if (i % 2 == 1) {
					direction1 *= -1;
				}
				else {
					direction2 *= -1;
				}

				paint(tempMap, direction1, x, y, axis, h, w);
				paint(tempMap, direction2, x, y, axis * -1, h, w);
				paint(tempMap, direction1 * -1, x, y, axis, h, w);

				rec(tempMap, cctvPos, h, w);
				axis *= -1;
			}
			
		}
		else {
			paint(map, 1, x, y, 1, h, w);
			paint(map, 1, x, y, -1, h, w);
			paint(map, -1, x, y, 1, h, w);
			paint(map, -1, x, y, -1, h, w);
			rec(map, cctvPos, h, w);
		}
	}
}

int main(void) {
	int map[8][8]={ 0 };
	vector<pair<int, int>> cctvPos;
	int n, m;

	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0 && map[i][j] < 6)
				cctvPos.push_back(make_pair(j, i));
		}
	}
	rec(map, cctvPos, n, m);

	cout << minCantSeeArea;
	return 0;
}