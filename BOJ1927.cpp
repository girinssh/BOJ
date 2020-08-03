#include <iostream>
#include <set>

using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;

	multiset<int> s;

	while (n--) {
		int val;
		cin >> val;

		if (val == 0) {
			if (s.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << *s.begin() << '\n';
				s.erase(s.begin());
			}
		}
		else {
			s.insert(val);
		}
	}
	return 0;
}