#include <iostream>
using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int t;
	cin >> t;

	for (int Case = 1; Case <= t; Case++) {
		int n, k;
		cin >> n >> k;

		cout << "Case #" << Case << ": ";
		int pos = -1;
		int** arr = new int* [n];

		for (int i = 0; i < n; i++) {
			arr[i] = new int[n] {0};
			for (int j = 0; j < n; j++) {
				arr[i][(j + i) % n] = j + 1;
			}
		}

		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = 0; j < n; j++) {
				sum += arr[j][(j + i) % n];
				if (sum > k)
					break;
			}
			if (sum == k) {
				pos = i;
				break;
			}
		}

		if (pos == -1) {
			cout << "IMPOSSIBLE\n";
		}
		else {
			cout << "POSSIBLE\n";

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cout << arr[i][(j + pos) % n] << ' ';
				}
				cout << '\n';
			}
		}
	}
	return 0;
}