#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void) {
	int count = 0;
	int n;

	cin >> n;

	int length = log10(n);

	for (int i = 1; i <= length; i++) {
		count += 9 * i * (int)pow(10, i - 1);
		n -= 9 * pow(10, i - 1);
		//cout << count << '\n';

	}

	count += n * (length + 1);

	cout << count;
	return 0;
}