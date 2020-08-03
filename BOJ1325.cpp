#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <list>

using namespace std;

int main(void) {

	cin.tie(NULL);
	cin.sync_with_stdio(false);
	vector<vector<int>> v;
	set<int> s;
	int maxCnt = 0;
	int n, m;

	cin >> n >> m;

	v = vector<vector<int>>(n);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a -= 1;
		b -= 1;
		v[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		vector<bool> check(n);
		queue<int> next;
		int cnt = 0;
		next.push(i);
		check[i] = true;

		while (!next.empty()) {
			int pos = next.front();
			next.pop();

			for (int j : v[pos]) {
				if (!check[j]) {
					cnt++;
					next.push(j);
					check[j] = true;
				}
			}
		}
		if (cnt > maxCnt) {
			maxCnt = cnt;
			s.clear();
			s.insert(i);
		}
		if (cnt == maxCnt)
			s.insert(i);
	}

	for (int v : s)
		cout << v + 1 << ' ';
	return 0;
}
// arr[a][b]
// a가 b를 신뢰한다.
// b를 탐색하면 