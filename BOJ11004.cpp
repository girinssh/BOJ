#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n, k;

	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> n >> k;

	vector<long long> v;

	for (int i = 0; i < n; i++) {
		long long val;
		cin >> val;
		v.push_back(val);
	}

	sort(v.begin(), v.end());
	cout << v[k-1];
	return 0;
}