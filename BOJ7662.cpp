#include <iostream>
#include <set>

using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int t;
	cin >> t;
	int start = t;
	while (t) {
		if (start != t) {
			cout << '\n';
		}
		multiset<int> s;
		int k;
		cin >> k;

		while (k--) {
			char c;
			int n;

			cin >> c >> n;

			if (c == 'I') {
				s.insert(n);
			}
			else {
				if (s.empty())
					continue;
				else {
					if (n == 1) {
						auto iter = s.end();
						iter--;
						s.erase(iter);
					}
					else
						s.erase(s.begin());
				}
			}

		}
		if (s.empty())
			cout << "EMPTY";
		else
			cout << *s.rbegin() << ' ' << *s.begin();
		t--;
		s.clear();
	}
	return 0;
}