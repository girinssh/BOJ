#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> v, output(n);
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		v.push_back(val);
	}

	set<int> s(v.begin(), v.end());
	map<int, int> m;
	int cnt = 0;
	for (auto iter = s.begin(); iter != s.end(); iter++) {
		m[*iter] = cnt;
		cnt++;
	}

	for (int val : v) {
		cout << m[val] << ' ';
	}
	return 0;
}