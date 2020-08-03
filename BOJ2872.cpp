#include <iostream>

using namespace std;

int arr[300000] = { 0 };



int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	int num = 1;
	int max = 0;
	int cnt = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[max] < arr[i]) {
			max = i;
		}
	}
	num = arr[max] - 1;
	cnt += n - max - 1;

	for (int i = max - 1; i >= 0; i--) {
		if (arr[i] != num) {
			cnt++;
		}
		else
			num--;
	}

	cout << cnt;
	return 0;
}