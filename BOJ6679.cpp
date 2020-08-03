#include <iostream>
#include <cmath>
using namespace std;

int main(void) {

	int val = 1000;
	int arr[3] = { 10, 12, 16 };
	while (val <= 9999) {
		int total[3] = { 0 };
		int temp[3] = { val, val, val };
		for (int i = 1; i <= 4; i++) {
			for (int j = 0; j < 3; j++) {
				if (temp[j] > 0) {
					total[j] += temp[j] % arr[j];
					temp[j] /= arr[j];
				}
			}
		}
		//cout << val << total[0] << ' ' << total[1] << ' ' << total[2] << '\n';
		if (total[0] == total[1] && total[1] == total[2])
			cout << val << '\n';
		val++;
	}
	return 0;
}