#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void DFS(vector<vector<int>>& g, int s) {
	vector<int> stk;
	vector<bool> check(g.size());

	stk.emplace_back(s);

	while (!stk.empty()) {
		int now = stk.back();
		stk.pop_back();
		if (check[now])
			continue;
		check[now] = true;

		cout << now+1 << " ";

		for (int i = g.size() - 1; i >= 0; i--) {
			if (g[now][i] == 1 && !check[i]) {
				stk.emplace_back(i);
			}
		}
	}

	cout << '\n';
}
void BFS(vector<vector<int>>& g, int s) {
	queue<int> q;
	vector<bool> check(g.size());

	q.emplace(s);
	check[s] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		cout << now+1 << " ";

		for (int i = 0; i < g.size(); i++) {
			if (g[now][i] == 1 && !check[i]) {
				check[i] = true;
				q.emplace(i);
			}
		}
	}
	cout << '\n';
}

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n, m, v;

	vector<vector<int>> g;

	cin >> n >> m >> v;

	v -= 1;

	for (int i = 0; i < n; i++) {
		g.push_back(vector<int>(n));
	}

	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		s -= 1; e -= 1;

		g[s][e] = g[e][s] = 1;
	}

	DFS(g, v);
	BFS(g, v);
	return 0;
}