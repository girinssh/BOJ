#include <iostream>
#include <list>

using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;

	list<pair<int, int>> v;

	int maxDay = 0;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;

		v.push_back(make_pair(e, s));
		if (e > maxDay) {
			maxDay = e;
		}
	}

	v.sort();

	list<pair<int, int>>::iterator iter = v.begin();

	int cnt = 0;
	int last = 0;
	while (iter != v.end()) {
		while(iter != v.end()) {
			if (iter->second >= last) {
				last = iter->first;
				cnt++;
				iter++;
				break;
			}
			iter++;
		}
	}
	cout << cnt;
	return 0;
}

