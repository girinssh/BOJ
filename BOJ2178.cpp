#include <iostream>
#include <algorithm>
#include <list>

#define X first
#define Y second

using namespace std;

typedef pair<char, char> Pos;

char map[100][100] = { 0 };
int n, m;

int BFS() {
	int x = 0, y = 0;
	int pass = 1;
	int nextPass = 0;
	int cnt = 0;

	list<int> xL, yL;
	xL.push_back(0);
	yL.push_back(0);

	while (xL.size() != 0) {
		bool isCounting = false;
		pass--;

		x = xL.front();
		y = yL.front();

		xL.pop_front();
		yL.pop_front();

		map[y][x] = 0;

		int l = x - 1;
		int r = x + 1;
		int d = y - 1;
		int u = y + 1;

		if (l >= 0) {
			if (map[y][l] == 1) {
				map[y][l] = 0;
				nextPass++;
				xL.push_back(l);
				yL.push_back(y);
			}
		}
		if (r < m) {
			if (map[y][r] == 1) {
				map[y][r] = 0;
				nextPass++;
				xL.push_back(r);
				yL.push_back(y);
			}
		}
		if (d >= 0) {
			if (map[d][x] == 1) {
				map[d][x] = 0;
				nextPass++;
				xL.push_back(x);
				yL.push_back(d);
			}
		}	
		if (u < n) {
			if (map[u][x] == 1) {
				map[u][x] = 0;
				nextPass++;
				xL.push_back(x);
				yL.push_back(u);
			}
		}
		if (pass == 0) {
			pass = nextPass;
			nextPass = 0;
			cnt++;
			isCounting = true;
		}
		if (x == m - 1 && y == n - 1) {
			if (!isCounting)
				cnt++;
			break;
		}
	}

	return cnt;
}

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			int value = s[j] - '0';
			map[i][j]= value;
		}
	}

	cout << BFS();
	return 0;
}