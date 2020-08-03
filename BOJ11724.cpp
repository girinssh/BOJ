#include <iostream>
#include <queue>

using namespace std;

int graph[1000][1000] = { 0 };
bool check[1000] = { 0 };

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a -= 1;
		b -= 1;
		graph[a][b] = 1;
		graph[b][a] = 1;
		
	}

	int cnt = 0;

	for (int line = 0; line < n; line++) {
		if (check[line])
			continue;
		cnt++;
		graph[line][line] = 0;
		check[line] = true;
		
		queue<int> q;
		q.push(line);

		while (!q.empty()) {
			int l = q.front();
			q.pop();

			for (int i = 0; i < n; i++) {
				if (graph[l][i] == 1) {
					graph[l][i] = 0;
					if (!check[i]) {
						q.push(i);
						check[i] = true;
					}
				}
			}
		}
	}
	cout << cnt;
	return 0;
}