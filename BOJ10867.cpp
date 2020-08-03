#include <iostream>
#include <set>

using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n;
	set<int> s;

	cin >> n;

	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;

		s.insert(val);
	}

	for (int i : s) {
		cout << i << ' ';
	}
	return 0;
}