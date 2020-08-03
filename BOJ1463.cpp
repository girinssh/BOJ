#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n;
	vector<int> cnt;

	cin >> n;
	if (n == 1) {
		cout << 0;
	}
	else {

		for (int i = 1; i <= n; i++) {
			int val = 1e9;

			if (i <= 3) {
				val = 0;
			}
			else {
				if (i % 2 == 0) {
					val = val > cnt[i / 2 - 1] ? cnt[i / 2 - 1] : val;
				}
				if (i % 3 == 0) {
					val = val > cnt[i / 3 - 1] ? cnt[i / 3 - 1] : val;
				}
				val = val > cnt[i - 1 - 1] ? cnt[i - 1 - 1] : val;
			}
			val++;
			//cout << i << ' ' << val << '\n';
			cnt.push_back(val);
		}

		cout << cnt.back();
	}

	return 0;
}