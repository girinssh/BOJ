#include <iostream>
#include <cmath>

using namespace std;

int main(void) {
	long long val;
	int bin[34] = { 0 };
	long long ver[2][34] = {
		{0, 0, 2, 2, 10, 10, 42, 42, }, // 2^1, 2^3, 2^5...
		{0, 1, 1, 5, 5, 21, 21, 85, } // 2^0, 2^2, 2^4...
	};

	long long temp = 128;
	for (int i = 8; i < 34; i+=2) {
		ver[0][i] = ver[0][i + 1] = ver[0][i - 1] + temp;
		ver[1][i - 1] = ver[1][i] = ver[1][i - 2] + temp / 2;
		temp *= 4;
	}
	ver[1][0] = 0;
	int sign = 0;
	cin >> val;

	if (val > 0) {
		sign = 0;
	}
	else if (val == 0) {
		cout << 0;
		return 0;
	}
	else {
		sign = 1;
		val *= -1;
	}

	temp = 1;

	for (int i = 0; i < 34; i++) {
		long long v = val + ver[sign][i];
		if ((v / temp) % 2 == 1) {
			bin[i] = 1;
		}
		temp *= 2;
	}

	bool start = false;
	for (int i = 33; i >= 0; i--) {
		if (bin[i] == 1)
			start = true;
		if (start)
			cout << bin[i];
	}
	return 0;
}