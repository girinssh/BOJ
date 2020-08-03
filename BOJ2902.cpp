#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (i == 0) {
			cout << s[i];
		}
		else {
			if (s[i - 1] == '-') {
				cout << s[i];
			}
		}
	}
	return 0;
}