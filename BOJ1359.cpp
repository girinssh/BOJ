#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	int n, m, k;

	int up = 0;
	int down = 0;

	long double probablity = 0.0;

	cin >> n >> m >> k;

	for (int i = k; i <= m; i++) {
		int u1 = 1, d1 = 1;

		for (int j = 0; j < i; j++) {
			u1 *= m - j;
			d1 *= i - j;
		}

		int u2 = 1, d2 = 1;

		for (int j = 0; j < m - i; j++) {
			u2 *= (n - m) - j;
			d2 *= (m - i) - j;
		}

		up += (u1 / d1) * (u2 / d2);
	}

	int u = 1, d = 1;

	for (int j = 0; j < m; j++) {
		u *= n - j;
		d *= m - j;
	}
	down += u / d;

	probablity = (long double)up / (long double)down;

	cout.setf(ios::fixed);
	cout.precision(9);
	cout << probablity;

	return 0;
}