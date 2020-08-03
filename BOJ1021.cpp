#include <iostream>

using namespace std;

int main(void) {

	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int arr[50] = { 0 };

	int size = 0;
	int m = 0;
	int iter = 0;
	int cnt = 0;

	cin >> size >> m;

	for (int i = 0; i < m; i++) {
		int p;
		cin >> p;

		int l = 0, r = 0;
		int lCnt = 0, rCnt = 0;
		while (true) {
			if ((iter + l) % size == p-1) {
				break;
			}
			if (arr[(iter + l) % size] == 0)
				lCnt++;
			l++;
		}
		while (true) {
			if ((size + iter - r) % size == p - 1) {
				break;
			}
			if (arr[(size + iter - r) % size] == 0)
				rCnt++;
			r++;
		}

		if (lCnt > rCnt) {
			iter = (size + iter - r) % size;
			cnt += rCnt;
		}
		else {
			iter = (iter + l) % size;
			cnt += lCnt;
		}
		arr[iter]++;

		int temp = 0;
		while (arr[iter] != 0) {
			iter = (iter + 1) % size;
			temp++;
			if (temp >= size)
				break;
		}
	}

	cout << cnt;
	return 0;
}