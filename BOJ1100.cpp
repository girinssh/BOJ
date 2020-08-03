#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int cnt = 0;

	for (int i = 0; i < 8; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < 8; j++) {
			if ((i % 2 == 0 && j % 2 == 0)
				|| (i % 2 != 0 && j % 2 != 0)) {
				if(s[j] == 'F')
					cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}