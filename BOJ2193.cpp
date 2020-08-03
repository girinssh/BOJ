#include <iostream>
#include <algorithm>

using namespace std;
long long arr[91] = { 0 , 1, 1, 2 };

int main(void) {
	int n;

	cin >> n;

	for (int i = 4; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	cout << arr[n];
	return 0;
}