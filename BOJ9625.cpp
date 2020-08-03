#include <iostream>

using namespace std;

long long dp[46] = { 0, 1, 1, 2, 3 };

int main(void) {
	int k;

	cin >> k;

	for (int i = 5; i <= k; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[k - 1] << ' ' << dp[k];

	return 0;
}

// 1 0, 0 1, 1 1, 1 2, 2 3
//BABBA -> BABBABAB(3, 5)