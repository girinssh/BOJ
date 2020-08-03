#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n;

	set<pair<int, int>> nodes;
	
	cin >> n;

	vector<int> v(n + 1);
	v[1] = 1;

	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;

		nodes.insert(make_pair(b, a));
		nodes.insert(make_pair(a, b));
	}
	
	auto iter = nodes.begin();

	while (!nodes.empty()) {
		pair<int, int> temp = *iter;

		
		
		iter++;
		nodes.erase(temp);

		if (iter == nodes.end())
			iter = nodes.begin();
	}

	for (int i = 2; i <= n; i++) {
		cout << v[i] << '\n';
	}

	return 0;
}