#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int cVal(char c) {
	if (c >= 'a')
		return c - 'a' + 10;
	return c - '0';
}

int main(void) {
	string s;
	int n;
	int iter = 0;

	vector<string> v;

	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> s;
	cin >> n;

	for (int j = 0; j < n; j++) {
		string t;
		cin >> t;

		if (t == "char") {
			char val = 0;

			val += 16 * cVal(s[iter++]);
			val += cVal(s[iter++]);
			cout << (int)val << ' ';
		}
		else if (t == "int") {
			int val = 0;

			for (int i = 7; i >= 0; i--) {
				val += (int)pow(16, i) * cVal(s[iter++]);
			}
			cout << val << ' ';

		}
		else {
			long long val = 0;

			for (int i = 15; i >= 0; i--) {
				val += (long long)pow(16, i) * cVal(s[iter++]);
			}
			cout << val << ' ';
		}
	}
	return 0;
}