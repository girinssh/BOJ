#include <iostream>

using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;

	int maxCnt = 0;

	int cnt = 0;
	int nowVal = 0;

	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;

		if (val > nowVal) {
			if (cnt > maxCnt)
				maxCnt = cnt;
			cnt = 0;
			nowVal = val;
		}
		else
			cnt++;
	}
	
	if (cnt > maxCnt)
		maxCnt = cnt;

	cout << maxCnt;
	return 0;
}