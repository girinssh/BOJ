#include <iostream>

using namespace std;

int main(void) {
	string s;
	int arr[10] = { 0 };
	int checkTotal = 0;
	cin >> s;

	for (char c : s) {
		checkTotal += (int)(c - '0');
		arr[c - '0']++;
	}

	if (checkTotal % 3 != 0 || arr[0] == 0)
		cout << -1;
	else {
		for (int i = 9; i >= 0; i--) {
			while (arr[i]-- > 0)
				cout << i;
		}
	}
	return 0;
}