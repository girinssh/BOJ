#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

bool check(string s) {
	int i = 0;
	while (s[i] != 'A') {
		i++;
		if (i == s.size())
			break;
	}
	if (i < s.size()) {
		while (s[i] != 'P') {
			i++;
			if (i == s.size())
				break;
		}
		while (i < s.size()) {
			if (s[i] == 'P')
				return false;
		}
	}
	return true;
}



int main(void) {
	int t = 0;

	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> t;

	while (t--) {
		int l = 0;
		string s;
		cin >> l;
		cin >> s;

		int m = 0;

		while (true) {
			if (check(s)) {
				cout << m << '\n';
				break;
			}
			m++;
			for (int i = 0; i < l - 1; i++) {
				if (s[i] == 'A' && s[i + 1] == 'P') {
					s[i + 1] = 'A';
					i++;
				}
			}

		}
	}
}
/*

APPAPPPAPPPP
AAPAAPPAAPPP

*/