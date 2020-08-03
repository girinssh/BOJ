#include<iostream>

using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int t;

	cin >> t;

	while (t--) {
		int position[2][2] = { 0 };
		int n;
		int planet[50][3] = { 0 };
		int cnt = 0;

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				cin >> position[i][j];
			}
		}

		cin >> n;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> planet[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			int temp = 0;
			for (int j = 0; j < 2; j++) {
				if ((planet[i][0] - position[j][0]) * (planet[i][0] - position[j][0])
					+ (planet[i][1] - position[j][1]) * (planet[i][1] - position[j][1])
					< planet[i][2] * planet[i][2])
					temp++;
			}

			if (temp == 1) {
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}