#include <iostream>

using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	string arr[50];
	int n;
	int maxCnt = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			char temp = arr[i][j];
			arr[i][j] = arr[i][j + 1];
			arr[i][j + 1] = temp;

			char before = 0;
			int maxTempCnt = 0;

			for (int x = 0; x < n; x++) {
				int cnt = 0;
				for (int y = 0; y < n; y++) {
					if (before != arr[y][x]) {
						if (cnt > maxTempCnt) {
							maxTempCnt = cnt;
						}
						cnt = 1;
					}
					else {
						cnt++;
					}
					before = arr[y][x];
				}
				if (cnt > maxTempCnt) {
					maxTempCnt = cnt;
				}
			}

			temp = arr[i][j];
			arr[i][j] = arr[i][j + 1];
			arr[i][j + 1] = temp;

			if (maxTempCnt > maxCnt)
				maxCnt = maxTempCnt;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			char temp = arr[j][i];
			arr[j][i] = arr[j+1][i];
			arr[j+1][i] = temp;

			char before = 0;
			int maxTempCnt = 0;

			for (int y = 0; y < n; y++) {
				int cnt = 0;
				for (int x = 0; x < n; x++) {
					if (before != arr[y][x]) {
						if (cnt > maxTempCnt) {
							maxTempCnt = cnt;
						}
						cnt = 1;
					}
					else {
						cnt++;
					}
					before = arr[y][x];
				}
				if (cnt > maxTempCnt) {
					maxTempCnt = cnt;
				}
			}

			temp = arr[j][i];
			arr[j][i] = arr[j+1][i];
			arr[j+1][i] = temp;

			if (maxTempCnt > maxCnt)
				maxCnt = maxTempCnt;
		}
	}
	cout << maxCnt;
	return 0;
}