#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int t;
	cin >> t;

	for (int Case = 1; Case <= t; Case++) {
		int n;
		int cameron = 0;
		int jamie = 0;
		bool isFailed = false;
		multimap<pair<int, int>, char> m;
		vector<pair<int, int>> v;
		cin >> n;

		for (int i = 0; i < n; i++) {
			int s, e;
			cin >> s >> e;
			pair<int, int> p = make_pair(s, e);
			m.insert(make_pair(p, '0'));
			v.push_back(p);
		}
		cout << "Case #" << Case << ": ";
		for (auto iter = m.begin(); iter != m.end(); iter++) {
			if (iter->first.first >= cameron) {
				cameron = iter->first.second;
				iter->second = 'C';
			}
			else if (iter->first.first >= jamie) {
				jamie = iter->first.second;
				iter->second = 'J';
			}
			else {
				isFailed = true;
				cout << "IMPOSSIBLE";
				break;
			}
		}

		if (!isFailed) {
			for (pair<int, int> p : v) {
				auto temp = m.find(p);
				cout << temp->second;
				m.erase(temp);
			}
		}
		cout << '\n';
	}
	return 0;
}