#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main(void) {
	map<short, short> s;
	int t = 0;

	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> t;
	while (t--) {
		short a = 0;
		cin >> a;
		s[a]++;
	}
	for (pair<short, short> a : s) {
		for (int i = 0; i < a.second; i++)
			cout << a.first << "\n";
	}
	return 0;
}