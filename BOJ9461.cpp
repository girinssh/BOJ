#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	long long arr[101] = { 0, 1, 1, 1, 2 };
	int t;

	cin.tie(NULL);
	cin.sync_with_stdio(false);

	for (int i = 4; i <= 100; i++) {
		arr[i] = arr[i - 2] + arr[i - 3];
	}

	cin >> t;

	while (t--) {
		int n = 0;
		cin >> n;
		cout << arr[n] << '\n';
	}
	return 0;
}