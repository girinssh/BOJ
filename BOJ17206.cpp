#include <iostream>

using namespace std;

int main(void) {
	int t = 0;

	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> t;
	while (t--) {
		int lim;
		cin >> lim;

		long long total = 0;

		long long l1 = (lim - lim % 3)/3;
		long long l2 = (lim - lim % 7)/7;
		long long l3 = (lim - lim % 21)/21;

		total = (3 * (l1 * (l1 + 1)) + 7 * (l2 * (l2 + 1)) - 21 * (l3 * (l3 + 1))) / 2;
			cout << total << '\n';
	}
	return 0;
}