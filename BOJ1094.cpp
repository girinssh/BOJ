#include <iostream>

using namespace std;

int main(void) {
	int x;
	int stick = 64;
	int cnt = 0;
	cin >> x;


	while (x > 0) {
		while (stick > x)stick /= 2;

		x -= stick;
		cnt++;
	}
	cout << cnt;
	return 0;
}