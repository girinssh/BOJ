#include <iostream>

using namespace std;

int main(void) {
	int len;
	long long hash = 0;
	long long r = 1;
	string s;
	cin >> len;
	cin >> s;

	for (char c : s) {
		hash += (((c - 'a') + 1) * (r % 1234567891)) % 1234567891;
		hash %= 1234567891;
		r *= 31;
	}

	cout << hash;
	return 0;
}