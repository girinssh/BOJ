#include <iostream>

using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	long long x, y;

	cin >> x >> y;

	if (x == y)
		cout << -1;
	else {
		long long ratio = y * 100 / x;
		long long z = ratio + 1;

		if (z == 100)
			cout << -1;
		else {
			long long cnt = 0;
			
			cnt = (x * z - 100 * y) / (100 - z) + ((x * z - 100 * y) % (100 - z) > 0 ? 1 : 0);

			cout << cnt;
		}
	}
	return 0;
}