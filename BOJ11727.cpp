#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int arr[1001] = {1, 2, 3 };

	for (int i = 3; i <= 1000; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]);
		cout << arr[i] << '\n';
	}
	int n = 0;
	cin >> n;
	cout << arr[n];
	return 0;
}

2541 - 1998