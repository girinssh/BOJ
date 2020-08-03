#include <iostream>

using namespace std;

#define R 0
#define G 1
#define B 2

int costs[1001][3] = { 0 };
int dp[1001][3] = { 0 };

int min(int a, int b) {
	return a > b ? b : a;
}

int main(void) {
	int n;

	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> costs[i][R] >> costs[i][G] >> costs[i][B];
		if (i != 0) {
			dp[i][0] = costs[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
			dp[i][1] = costs[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
			dp[i][2] = costs[i][2] + min(dp[i - 1][1], dp[i - 1][0]);
		}
		else {
			dp[i][0] = costs[i][0];
			dp[i][1] = costs[i][1];
			dp[i][2] = costs[i][2];
		}
	}

	cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
	return 0;
	
}