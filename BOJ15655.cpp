#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

void func(set<int>& s, vector<int>& v, int left) {
	if (left == 0) {
		for (int i : v) {
			cout << i << ' ';
		}
		cout << '\n';
	}
	else {
		set<int>::iterator iter = s.begin();
		if (v.size() != 0) {
			iter = s.upper_bound(v.back());
		}

		while (iter != s.end()) {
			int t = *iter;
			s.erase(t);
			v.push_back(t);
			func(s, v, left - 1);
			v.pop_back();
			s.insert(t);
			iter = s.find(t);
			iter++;
		}
	}
}

int main(void) {
	int n, m;
	vector<int> v;
	set<int> s;
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		s.insert(val);
	}

	func(s, v, m);
	return 0;
}