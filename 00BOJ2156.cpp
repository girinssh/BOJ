#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	int n;
	int maxVal = -1;
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	//cin >> n;

	n = 10000;

	vector<int> v(n);
	vector<int> dp(n);

	fill(v.begin(), v.end(), 1000);
	fill(dp.begin(), dp.end(), 0);

	//for (int i = 0; i < n; i++) {
	//	cin >> v[i];
	//}

	for (int i = 0; i < n; i++) {
		if (i < 3) {
			if (i == 0)
				dp[i] = v[i];
			else if (i == 1)
				dp[i] = v[i - 1] + v[i];
			else
				dp[i] = max(v[i] + v[i - 1], v[i - 2] + v[i]);
		}
		else {
			dp[i] = max(v[i - 1] + v[i] + dp[i - 3], v[i] + dp[i - 2]);
		}
		//cout << dp[i] << ' ';
		if (dp[i] > maxVal)
			maxVal = dp[i];
	}

	cout << maxVal;
	return 0;
}