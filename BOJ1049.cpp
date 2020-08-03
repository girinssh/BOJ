#include <iostream>

using namespace std;

int main(void) {
	cin.tie(NULL);	
	cin.sync_with_stdio(false);

	int n, m;
	int cost = 0;
	int a = 1000, b = 1000;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;

		if (v1 < a)
			a = v1;
		if (v2 < b)
			b = v2;
	}

	if (b * 6 <= a) {
		cost = b * n;
	}
	else {
		while (n >= 6) {
			n -= 6;
			cost += a;
		}
		if (a < b * n) {
			cost += a;
		}
		else {
			cost += b * n;
		}
	}
	cout << cost;
	return 0;
}