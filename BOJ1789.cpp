#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	long long n;

	cin >> n;

	cout << (long long)((-1 + sqrt(1 + 8 * n)) / 2);
	return 0;
}