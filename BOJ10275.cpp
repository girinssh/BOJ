#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(void) {
	int t = 0;
	vector<long long> binary;
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> t;

	for (int i = 0; i <= 62; i++) {
		binary.push_back(pow(2, i));
	}

	while (t--) {
		long long a, b;
		int n;
		long long pivot = 0;
		cin >> n >> a >> b;

		pivot = a < b ? a : b;

		vector<long long>::iterator iter;
		while (pivot != 0) {
			iter = lower_bound(binary.begin(), binary.end(), pivot);
			if (*iter > pivot)
				iter--;
			pivot -= *iter;
		}

		int e1, e2;
		e1 = n;
		e2 = (int)log2(*iter);
		cout << e1 - e2;
		if (t != 0)
			cout << '\n';
	}
	return 0;
}

// 2305843009213693952