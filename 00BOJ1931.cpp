#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;

	set<pair<int, int>> times;

	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;

		times.insert({ s, e });
	}

	int maxCnt = 0;

	vector< set<pair<int, int>>::iterator> ic;
	ic.push_back(times.begin());
	int temp = 0;
	while (ic.back() != times.end()) {
		temp = ic.back()->second;
		ic.push_back(times.lower_bound({ temp, temp }));
	}
	ic.pop_back();

	maxCnt = ic.size();

	while (!ic.empty()) {
		int cnt = 1;
		ic.back()++;
		if (ic.back() == times.end()) {
			ic.pop_back();
			if (ic.empty())
				break;
			ic.back()++;
		}
		while (ic.back() != times.end()) {
			temp = ic.back()->second;
			ic.push_back(times.lower_bound({ temp, temp }));
		}
		ic.pop_back();
		cnt = ic.size();
		if (maxCnt < cnt)
			maxCnt = cnt;
		//cout << cnt << '\n';
	}

	cout << maxCnt;
	return 0;
}