#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int arr[3] = { 0 };

	for (int i = 0; i < 3; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + 3);

	cout << arr[1];

	return 0;
}