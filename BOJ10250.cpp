#include <iostream>

using namespace std;

int main(void) {

	int t = 0;

	cin >> t;

	while (t--) {
		int h, w, n;
		int floor;
		int number;
		
		cin >> h >> w >> n;

		floor = n % h == 0 ? h : n % h;
		number = n / h  + (n % h == 0 ? 0 : 1);

		cout << floor << (number / 10 < 1 ? "0" : "") << number << '\n';
	}
	return 0;
}