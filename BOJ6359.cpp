#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int t = 0;

	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> t;

	while (t--) {
		int arr[100] = { 0 };
		int n = 0;
		int count = 0;
		cin >> n;

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j <= n; j += i + 1) {
				arr[j-1] = !arr[j-1];
			}
		}

		for (int i = 0; i < n; i++) {
			if (arr[i])
				count++;
		}
		cout << count << '\n';
	}
	return 0;
}
