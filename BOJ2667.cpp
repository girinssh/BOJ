#include  <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int bfs(vector<string>& map, int x, int y) {
	int n = map.size();

	queue<int> qx, qy;
	vector<vector<bool>> check(n, vector<bool>(n));

	qx.push(x);
	qy.push(y);

	check[y][x] = true;

	int cnt = 0;

	while (!qx.empty()) {
		cnt++;
		int i = qy.front();
		int j = qx.front();

		map[i][j] = '0';

		qx.pop();
		qy.pop();

		if ((i - 1) >= 0)
			if (map[i - 1][j] == '1' && !check[i - 1][j]) {
				qx.push(j);
				qy.push(i - 1);
				check[i - 1][j] = true;
			}
		if ((i + 1) < n)
			if (map[i + 1][j] == '1' && !check[i + 1][j]) {
				qx.push(j);
				qy.push(i + 1);
				check[i + 1][j] = true;
			}
		if ((j - 1) >= 0)
			if (map[i][j - 1] == '1' && !check[i][j - 1]) {
				qx.push(j - 1);
				qy.push(i);
				check[i][j - 1] = true;
			}
		if ((j + 1) < n)
			if (map[i][j + 1] == '1' && !check[i][j + 1]) {
				qx.push(j + 1);
				qy.push(i);
				check[i][j + 1] = true;
			}
	}
	return cnt;
}

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;

	vector<string> map;
	multiset<int> ms;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		map.emplace_back(s);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] != '0') {
				ms.insert(bfs(map, j, i));
			}
		}
	}

	cout << ms.size() << '\n';

	for (int cnt : ms) {
		cout << cnt << '\n';
	}
	return 0;
}