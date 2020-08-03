#include <iostream>

using namespace std;

int main(void) {
	int r, b;

	cin >> r >> b;

	for (int innerWidth = 1; innerWidth <= b / 2 + b % 2; innerWidth++) {
		if (b % innerWidth != 0) 
			continue;
		
		int w = innerWidth + 2;
		int l = b / innerWidth + 2;

		if (w * l == r + b) {
			cout << l << ' ' << w;
			break;
		}
	}
	return 0;
}