#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int a, b;

	int num[16];

	cin >> a;
	cin >> b;

	for (int i = 0; i < 8; i++) {
		num[(7 - i) * 2] = a % 10;
		num[(7 - i) * 2 + 1] = b % 10;
		a /= 10;
		b /= 10;
	}

	for (int i = 0; i < 14; i++) {
		for (int j = 0; j < 15 - i; j++) {
			num[j] = (num[j] + num[j + 1]) % 10;
			//cout << num[j];
		}
		//cout << '\n';
	}
	cout << num[0] << num[1];
	return 0;
}