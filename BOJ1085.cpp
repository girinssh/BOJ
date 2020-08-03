#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int x, y, w, h;
	int dx, dy;
	cin >> x >> y >> w >> h;

	dx = (w - x > x ? x : w - x);
	dy = (h - y > y ? y : h - y);

	cout << (dx > dy ? dy : dx);
	return 0;
}