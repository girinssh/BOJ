#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dir[4][2] = {
	{0, 1},
	{1, 0},
	{-1, 0},
	{0, -1}
};

typedef struct pos {
	int x;
	int y;
	bool isBroken;
	int dist;
}pos;

int bfs(vector<string>& map) {
	int n = map.size();
	int m = map[0].size();

	queue<pos> qp;
	vector<vector<int>> check(n, vector<int>(m, 0));
	// 0 - ���� ����
	// 1 - �� �μ��ְ� ����
	// 2 - �� ���� �� �μ��ְ� ����

	qp.push({ 0, 0, false, 1 });
	check[0][0] = 2;

	int minCnt = n * m;

	while (!qp.empty()) {
		pos p = qp.front();
		qp.pop();

		if (p.x == m - 1 && p.y == n - 1) {
			return p.dist;
		}
		if (check[p.y][p.x] == 2 && p.isBroken)
			continue;

		for (int i = 0; i < 4; i++) {
			int dx = p.x + dir[i][1];
			int dy = p.y + dir[i][0];

			// ������ ����� ��ŵ
			if (dx < 0 || dx >= m || dy < 0 || dy >= n) {
				continue;
			}

			if (map[dy][dx] == '0') {
				// ���� ��ĭ���� ����
				if (check[dy][dx] == 0) {
					check[dy][dx] = check[p.y][p.x];
					qp.push({ dx, dy, p.isBroken, p.dist + 1 });
				}
				// �� �μ��ְ� �μ��ְ� ������ ��� �� ��.
				else if (check[dy][dx] < check[p.y][p.x] && !p.isBroken) {
					check[dy][dx] = 2;
					qp.push({ dx, dy, false, p.dist + 1 });
				}
			}
			//�������� �� ��
			else {
				// ���� ���� �ѹ��� �μ��� �ʾҴٸ�?
				if (!p.isBroken) {
					check[dy][dx] = 1;
					qp.push({ dx, dy, true, p.dist + 1 }); // �μ���.
				}
			}
		}
	}
	if(minCnt == n*m)
		return -1;
	return minCnt;
}

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n, m;

	cin >> n >> m;

	vector<string> v;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}

	int cnt = bfs(v);

	cout << cnt;

	return 0;
}