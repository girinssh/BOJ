#include <iostream>

using namespace std;

int arr[1000][5] = { 0 };
int cls[5][9][1000] = { 0 };
int sum[1000] = { 0 };
int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	int student = 0;
	int maxVal = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
			cls[j][arr[i][j] - 1][i]++;
		}
	}

	for (int i = 0; i < n; i++) {
		int temp[1000] = { 0 };
		for (int j = 0; j < 5; j++) {
			for(int k = 0; k < n; k++){
				if (cls[j][arr[i][j] - 1][k] != 0) {
					temp[k] = 1;
				}
			}
		}
		for (int v : temp) {
			sum[i] += v;
		}
	}

	for (int i = 0; i < n; i++) {
		if (sum[i] > maxVal) {
			maxVal = sum[i];
			student = i + 1;
		}
	}
	cout << student;
	return 0;
}