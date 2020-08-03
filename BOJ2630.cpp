#include <iostream>

using namespace std;

int n;
int bCnt = 0;
int wCnt = 0;
int arr[128][128] = { 0 };

void func(int x, int y, int size) {
	bool isClear = true;
	int s = arr[y][x];

	for (int i = y; (i < y + size) && isClear; i++) {
		for (int j = x; (j < x + size) && isClear; j++) {
			if (arr[i][j] != s) 
				isClear = false;
		}
	}
	if (isClear) {
		if (s == 1)
			bCnt++;
		else
			wCnt++;
	}
	else {
		int newSize = size / 2;
		func(x, y, newSize);
		func(x + newSize, y, newSize);
		func(x , y + newSize, newSize);
		func(x + newSize, y + newSize, newSize);
	}
}

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	func(0, 0, n);
	cout << wCnt << '\n';
	cout << bCnt;
	return 0;
}