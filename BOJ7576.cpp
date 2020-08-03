#include <iostream>
#include <queue>

using namespace std;

int arr[1001][1001] = { 0 };
int day = 0;
int c, r;

void BFS(queue<int> & x, queue<int>& y) {
	queue<int> qx(x), qy(y);
	int val = 0;
	while (qx.size() > 0) {

		bool isChecked = false;
		int nx = qx.front();
		int ny = qy.front();
		val = arr[ny][nx];
		qx.pop();
		qy.pop();

		if (nx + 1 < c && arr[ny][nx+1] == 0) {
			arr[ny][nx + 1] = val + 1;
			qx.push(nx + 1);
			qy.push(ny);
			isChecked = true;
		}
		if (nx - 1 >= 0) {
			if (arr[ny][nx - 1] == 0) {
				arr[ny][nx - 1] = val + 1;
				qx.push(nx - 1);
				qy.push(ny);
				isChecked = true;

			}
		}
		if (ny + 1 < r && arr[ny + 1][nx] == 0) {
			arr[ny + 1][nx] = val + 1;
			qx.push(nx);
			qy.push(ny + 1);
			isChecked = true;
		}
		if (ny - 1 >= 0) {
			if (arr[ny - 1][nx] == 0) {
				arr[ny - 1][nx] = val + 1;
				qx.push(nx);
				qy.push(ny - 1);
				isChecked = true;
			}
		}

		if (isChecked) {
			day = val;
		}
	}
}

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	queue<int> x;
	queue<int> y;

	cin >> c >> r;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 1) {
				x.push(j);
				y.push(i);
			}
		}
	}

	BFS(x, y);

	bool isClear = true;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 0) {
				isClear = false;
				goto END;
			}
		}
	}

END:
	if (isClear) {
		cout << day;
	}
	else
		cout << -1;

	return 0;
}