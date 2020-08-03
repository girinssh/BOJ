#include <iostream>
#include <set>

using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	while (true) {
		bool isEnd = false;
		int cnt = 0;
		set<int> s;

		while (true) {
			int val;
			cin >> val;
			if (val <= 0)
				break;
			s.insert(val);
		}

		if (s.empty())
			break;

		for (int val : s) {
			if (s.find(val * 2) != s.end())
				cnt++;
		}
		cout << cnt << '\n';
	}
	return 0;
}