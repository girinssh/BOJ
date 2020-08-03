#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(void) {
	int n, m;
	int cnt = 0;
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> n;
	cin >> m;

	vector<vector<int>> comp(n);
	vector<bool> check(n);
	queue<int> q;

	fill(check.begin(), check.end(), false);

	for (int i = 0; i < m; i++) {
		int p, v;
		cin >> p >> v;
		comp[p-1].push_back(v-1);
		comp[v-1].push_back(p-1);
	}

	q.push(0);
	check[0] = true;

	while (!q.empty()) {
		int pos = q.front();
		q.pop();

		for (int p : comp[pos]) {
			if (!check[p]) {
				check[p] = true;
				q.push(p);
				cnt++;
			}
		}
	}

	cout << cnt;

	return 0;
}