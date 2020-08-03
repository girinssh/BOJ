#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int viruses[10][2] = { 0 };
int virusSize = 0;
int arr[8][8] = { 0 };
int w, h;
int safe = 0;
int wall = 0;

void BFS() {
	int iter = 0;
	int temp[8][8];
	int infection = 0;
	memcpy(temp, arr, sizeof(int) * 64);

	//for (int i = 0; i < h; i++) {
	//	for (int j = 0; j < w; j++) {
	//		cout << temp[i][j] << ' ';
	//	}
	//	cout << '\n';
	//}

	while (iter < virusSize) {
		queue<int> xL, yL;
		xL.push(viruses[iter][0]);
		yL.push(viruses[iter][1]);

		while (xL.size() != 0) {
			int x = xL.front();
			int y = yL.front();

			xL.pop();
			yL.pop();

			int up = y + 1;
			int down = y - 1;
			int right = x + 1;
			int left = x - 1;
			if (right < w)
				if (temp[y][right] == 0) {
					temp[y][right] = 2;
					xL.push(right);
					yL.push(y);
					infection++;
				}
			if (left >= 0)
				if (temp[y][left] == 0) {
					temp[y][left] = 2;
					xL.push(left);
					yL.push(y);
					infection++;
				}
			if (up < h)
				if (temp[up][x] == 0) {
					temp[up][x] = 2;
					xL.push(x);
					yL.push(up);
					infection++;
				}
			if (0 <= down)
				if (temp[down][x] == 0) {
					temp[down][x] = 2;
					xL.push(x);
					yL.push(down);
					infection++;
				}
		}
		iter++;
	}
	if (w * h - infection - wall - virusSize - 3 > safe) {

		safe = w * h - infection - wall - virusSize - 3;
		//cout << safe << ' ' << infection << ' ' << wall << ' ' << virusSize << "\n\n";
	}

	return;
}

void Mapping(int left, int x, int y) {
	if (left != 0) {
		for (int i = y ; i < h; i++) {
			for (int j = x; j < w; j++) {
				if (arr[i][j] == 0) {
					arr[i][j] = 1;
					Mapping(left-1, j+1, i);

					arr[i][j] = 0;
				}
			}
			if (i == y) {
				x = 0;
			}
		}
	}
	else {
		BFS();
	}
}

int main(void) {


	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> h >> w;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				viruses[virusSize][0] = j;
				viruses[virusSize][1] = i;
				virusSize++;
			}
			else if (arr[i][j] == 1)
				wall++;
		}
	}

	Mapping(3, 0, 0);
	cout << safe;
	return 0;
}


// 맵의 크기만 더 커지면 네트워크 플로우
// Min Cut Max Flow