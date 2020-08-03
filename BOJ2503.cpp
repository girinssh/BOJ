#include <iostream>

using namespace std;

int main(void) {
	
	int arr[1000] = { 0 };
	int n;

	cin >> n;

	for (int iter = 0; iter < n; iter++) {
		int val, s, b;
		cin >> val >> s >> b;

		int num[3] = { val / 100, (val % 100) / 10 , val % 10 };

		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				for (int k = 1; k <= 9; k++) {
					if (i == j || j == k || k == i)
						continue;

					int temp[3] = { i, j, k };
					int st = 0, ba = 0;

					for (int l = 0; l < 3; l++) {
						for (int m = 0; m < 3; m++) {
							if (temp[l] == num[m] && l == m) st++;
							else if (temp[l] == num[m] && l != m) ba++;
						}
					}

					int now = i * 100 + j * 10 + k;

					if (s == st && b == ba && arr[now] != -1) {
						arr[now] = 1;
					}
					else {
						arr[now] = -1;
					}
				}
			}
		}
	}
	int cnt = 0;

	for (int i = 123; i < 988; i++) {
		if (arr[i] == 1)
			cnt++;
	}
	cout << cnt;
	return 0;
}