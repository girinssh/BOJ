#include <iostream>
#include <set>

using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	
	multiset<int> s;
	int n;
	cin >> n;

	while (n--) {
		int val;
		cin >> val;

		if (val == 0) {
			if (s.empty())
				cout << 0 << '\n';
			else {
				cout << *s.rbegin() << '\n';
				auto iter = s.end();
				iter--;
				s.erase(iter);
			}
		}
		else {
			s.insert(val);
		}
	}
	return 0;
}