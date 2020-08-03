#include <iostream>
#include <algorithm>

using namespace std;

int arr[500][500] = { 0 };

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	int n;
	int maxVal = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			cin >> arr[i - 1][j];
			if (i != 1) {
				if (j == 0)
					arr[i - 1][j] += arr[i - 2][j];
				else if (j == i - 1) {
					arr[i - 1][j] += arr[i - 2][j - 1];
				}
				else
					arr[i - 1][j] += (arr[i - 2][j] > arr[i - 2][j - 1] ? arr[i - 2][j] : arr[i - 2][j - 1]);
			}
			if (i == n && arr[i - 1][j] > maxVal) {
				maxVal = arr[i - 1][j];
			}
		}
	}
	cout << maxVal;
	return 0;
}