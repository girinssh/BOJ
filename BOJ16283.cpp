#include <iostream>

using namespace std;

int main(void) {
	int a, b, n, w;
	int rA = -1, rB = -1;

	bool isFailed = false;

	cin >> a >> b >> n >> w;

	for (int i = 1; i < n; i++) {
		if (a * i + b * (n - i) == w) {
			if (rA != -1) {
				isFailed = true;
				break;
			}
			rA = i;
			rB = n - i;
		}
	}

	if (isFailed || rA == -1) {
		cout << -1;
	}
	else {
		cout << rA << ' ' << rB;
	}
	return 0;
}