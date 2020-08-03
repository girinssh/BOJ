#include <iostream>
#include <map>
#include <vector>
using namespace std;


int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n;

	map<pair<int, int>, int> v;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;

		v[make_pair(s, e)] = i;
	}

	vector<int> score(n);

	for (auto fighter : v) {
		map<pair<int, int>, int>::iterator iter = v.begin();

		while (iter != v.end()) {
			if (iter->first.first < fighter.first.first && iter->first.second > fighter.first.first) {
				score[fighter.second]++;
			}
			if (iter->first.first >= fighter.first.first) {
				break;
			}
			iter++;
		}

	}
	
	for (int s : score) {
		cout << s << '\n';
	}

	return 0;
}