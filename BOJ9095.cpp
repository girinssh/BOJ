#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[12] = { 0, 1, 2, 4 };

void func(int num) {
	if (dp[num] != 0)
		return;
	for (int i = 1; i <= 3; i++) {
		if (dp[num - i] == 0)
			func(num - i);
		dp[num] += dp[num - i];
	}
}

int main(void) {
	int t;

	cin.tie(NULL);
	cin.sync_with_stdio(false);

	func(11);

	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}