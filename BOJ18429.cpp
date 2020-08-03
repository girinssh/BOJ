#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;

void backtrack(int n, int k, int weight, vector<int>& data, int outCnt) {
	if (weight < 500) {
		return;
	}
	else {
		if (outCnt == n) {
			cnt++;
			return;
		}

		vector<int>::iterator dIter = data.begin();
		while (dIter != data.end()) {
			while (*dIter == -1) {
				dIter++;
				if (dIter == data.end())
					break;
			}
			if (dIter == data.end())
				break;
			int d = *dIter;
			*dIter = -1;

			backtrack(n, k, weight - k + d, data, outCnt + 1);
			
			*dIter = d;
			dIter++;
		}
	}
}

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n, k;
	int weight = 500;
	cin >> n >> k;

	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	backtrack(n, k, weight, v, 0);

	cout << cnt;
	return 0;
}