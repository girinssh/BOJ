#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
	int n = 0;
	cin >> n;

	while (true) {
		int cnt = 3;
		int index = 0;
		while (n > cnt) {
			index++;
			cnt += cnt + index + 3;
		}

		n = n - (cnt - (index + 3)) / 2;
		
		if (n <= index + 3) {
			if (n == 1)
				cout << 'm';
			else
				cout << 'o';
			break;
		}
		n -= index + 3;
	}

	return 0;
}

// 1 
// 1 2 1
// 1 2 1 3 1 2 1
// 1 2 1 3 1 4 1 3 1 2 1