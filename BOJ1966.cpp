#include <iostream>
#include <list>

using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int t;
	cin >> t;

	while (t--) {
		list<int> l;
		int n, m;
		int cnt = 0;
		bool isClear = false;
		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			int val;
			cin >> val;
			l.push_back(val);
		}

		while (!isClear) {
			bool isPrint = true;
			int val = l.front();

			for (int nVal : l) {
				if (nVal > val) {
					isPrint = false;
					break;
				}
			}

			if (isPrint) {
				cnt++;
				if (m == 0)
					isClear = true;
				else 
					m--;
				
				l.pop_front();
			}
			else {
				l.push_back(l.front());
				l.pop_front();
				if (m == 0)
					m = l.size() - 1;
				else
					m--;
			}
		}
		cout << cnt << '\n';
	}

	return 0;
}