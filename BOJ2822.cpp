#include <iostream>

using namespace std;

int main(void) {
	int arr[8] = { 0 };
	int score = 0;

	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 5; i++) {
		int max = 0;
		int index = 0;
		for (int j = 0; j < 8; j++) {
			if (max < arr[j]) {
				max = arr[j];
				index = j;
			}
		}

		score += max;
		arr[index] = -1;
	}

	cout << score << '\n';

	for (int i = 0; i < 8; i++) {
		if (arr[i] == -1) {
			cout << i + 1 << ' ';
		}
	}
	return 0;
}