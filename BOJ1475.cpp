#include <iostream>

using namespace std;

int main(void) {
	int arr[9] = { 0 };
	int maxCnt = 1;
	string n;

	cin >> n;

	for (char c : n ) {
		c -= '0';
		if (c == 6 || c == 9) {
			if (maxCnt * 2 == arr[6]) {
				maxCnt++;
			}
			arr[6]++;
		}
		else {
			if (maxCnt == arr[c]) {
				maxCnt++;
			}
			arr[c]++;
		}
	}
	cout << maxCnt;
	return 0;
}