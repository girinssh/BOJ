#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> Pos;

int main(void) {
	int t;

	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> t;

	while (t--) {
		vector<Pos> positions;
		string s = "";
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			Pos p;
			cin >> p.first >> p.second;
			positions.push_back(p);
		}

		sort(positions.begin(), positions.end());

		int nowX = 0;
		int maxY = 0;
		bool isFailed = false;
		for (Pos p : positions) {
			if (p.first > nowX) {
				for (int i = 0; i < p.first - nowX; i++) {
					s.push_back('R');
				}
				nowX = p.first;
			}
			if (p.second < maxY) {
				cout << "NO\n";
				isFailed = true;
				break;
			}
			else {
				for (int i = 0; i < p.second - maxY; i++) {
					s.push_back('U');
				}
				maxY = p.second;
			}
		}
		if (!isFailed) {
			cout << "YES\n" << s << '\n';
		}
	}
	return 0;
}