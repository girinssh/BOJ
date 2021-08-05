#include  <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dir[4][2] = {
	{0, 1},
	{-1, 0},
	{0, -1},
	{1, 0}
};

int bfs(vector<string>& map) {
	int n = map.size();
	int m = map[0].size();

	int cnt = 0;

	vector<vector<int>> check(n, vector<int>(m, 0));

	queue<int> qx, qy, qs, qdist;

	qx.push(0);
	qy.push(0);
	qs.push(0);
	
	qdist.push(1);

	check[0][0] = 2;

	while (!qx.empty()) {
		int j = qx.front();
		int i = qy.front();
		int s = qs.front();
		int dist = qdist.front() + 1;

		if (j == m - 1 && i == n - 1) {
			break;
		}

		qx.pop();
		qy.pop();
		qs.pop();
		qdist.pop();

		for (int k = 0; k < 4; k++) {
			int dx = j + dir[k][1];
			int dy = i + dir[k][0];

			if (dx < 0 || dx >= m || dy < 0 || dy >= n) {
				continue;
			}
			if ((map[dy][dx] == '0' 
				|| (map[dy][dx] == '1' 
					&& s == 0)) 
				&& (check[dy][dx] == 0 
					|| (check[dy][dx] % 2 == 1 
						&& check[i][j] % 2 == 0))) {
				qx.push(dx);
				qy.push(dy);
				if (map[dy][dx] == '1') {
					qs.push(1);
					check[dy][dx] = (dist) * 2 + 1;
				}
				else {
					qs.push(s);
					check[dy][dx] = (dist) * 2 + s;
				}
				qdist.push(dist);

			}
		}
	}
	if (check[n - 1][m - 1]) {
		return qdist.front();
	}
	else
		return -1;
}

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n, m;

	cin >> n >> m;

	vector<string> map;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		map.push_back(s);
	}

	cout << bfs(map);
	return 0;
}

/*
8 8
01000100
01010100
01010100
01010100
01010100
01010100
01010100
00010100

*/