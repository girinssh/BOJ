#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int t;
	cin >> t;

	for (int Case = 1; Case <= t; Case++) {
		int n, k=0, r=0, c=0;
		cin >> n;

		int** arr = new int* [n];
		for (int i = 0; i < n; i++) {
			int* temp = new int[n] {0};
			arr[i] = new int[n];
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				temp[arr[i][j] - 1]++;
				if (i == j)
					k += arr[i][j];
			}
			for (int j = 0; j < n; j++) {
				if (temp[j] != 1) {
					r++;
					break;
				}
			}
		}

		for (int j = 0; j < n; j++) {
			int* temp = new int[n] {0};
			for (int i = 0; i < n; i++) {
				temp[arr[i][j] - 1]++;
			}
			for (int j = 0; j < n; j++) {
				if (temp[j] != 1) {
					c++;
					break;
				}
			}
		}
		cout << "Case #" << Case << ": " << k << ' ' << r << ' ' << c << '\n';
	}
	return 0;
}