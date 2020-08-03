#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

int main(void) {
	int n;
	long long v1[1000] = { 3, 7 }, v2[1000] = { 2, 5 };
	cin >> n;
	
	for (int i = 2; i < n; i++) {
		v1[(i % 1000)] = (v1[(i - 1) % 1000] + v2[(i - 1) % 1000] * 2) % 9901;
		v2[(i % 1000)] = (v1[(i - 1) % 1000] + v2[(i - 1) % 1000]) % 9901;

		//cout << v1[i % 1000] << '\n';
	}

	cout << v1[(n-1) % 1000];
	return 0;
}
