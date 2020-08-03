#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(void) {
	int m, n;
	map<int, int> a, b;
	int x = 0;
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		a[v]++;
	}

	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		b[v]++;
	}
	for (x = 0; x < m; x++) {
		map<int, int> temp;
		bool isSame = true;
		for (pair<int, int> p : a) {
			int i = (p.first + x) % m;
			temp[i] = p.second;
			map<int, int>::iterator iter = b.find(i);
			if (iter != b.end()) {
				if (iter->second != temp[i]) {
					isSame = false;
					break;
				}
			}
			else {
				isSame = false;
				break;
			}
		}
		if (isSame) {
			cout << x;
			break;
		}
	}
	return 0;
}