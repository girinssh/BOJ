#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int arr[1000] = { 0 };

	int m;

	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> m;

	while (true) {
		double val;
		cin >> val;
		if (cin.eof()) {
			for (int i = 0; i < m; i++) {
				cout << arr[i] << ' ';
			}
			break;
		}
		for (int j = m-1; j >= 0; j--) {
			if ((double)j / m <= val) {
				arr[j]++;
				break;
			}
		}

	}

	return 0;
}