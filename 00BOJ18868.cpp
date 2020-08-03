#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>

using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n, m;
	int cnt = 0;
	map<string, int> univ;
	cin >> n >> m;

	set<vector<int>> universe;

	for (int i = 0; i < n; i++) {
		int bef = 0;
		string s = "";
		vector<int> v(m);
		map<int, int> temp;
		for (int j = 0; j < m; j++) {
			cin >> v[j];
			temp[v[j]] = 0;
		}
		int rank = 1;
		for (auto iter = temp.begin(); iter != temp.end(); iter++) {
			iter->second = rank;
			rank++;
		}

		for (int val : v) {
			s += (to_string(temp[val]))+" ";
		}
		
		if (universe.find(v) == universe.end()) {
			universe.insert(v);
			univ[s]++;
		}
	}

	for (auto iter = univ.begin(); iter != univ.end(); iter++) {
		cout << iter->first << ' ' << iter->second << '\n';
		if (iter->second > 1)
			cnt+= iter->second / 2;
	}
	cout << cnt;
	return 0;
}