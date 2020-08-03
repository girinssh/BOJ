#include <iostream>

using namespace std;

int main(void) {
	int n;
	int cnt = 0;
	cin >> n;

	n /= 3;

	for (int i = 1; i <= n - 2; i++) {
		for (int j = 1; j <= n - 1 - i; j++) {
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}
