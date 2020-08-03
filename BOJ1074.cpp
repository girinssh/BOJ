#include <iostream>
#include <cmath>

using namespace std;

int n, r, c;
int cnt = 0;

bool isClear = false;

void zSearch(int x, int y, int length) {
	if (isClear)
		return;
	if (length == 1) {
		if (r == y && c == x) {
			cout << cnt;
			isClear = true;
		}
		cnt++;
		return;
	}
	else {
		length /= 2;
		int val = length * length;
		if (x <= c && c < x + length && y <= r && r < y + length) 
			zSearch(x, y, length);
		else 
			cnt += val;
		if (x + length <= c && c < x + length + length && y <= r && r < y + length) 
			zSearch(x + length, y, length);
		else
			cnt += val;
		if (x <= c && c < x + length && y+ length <= r && r  < y + length + length)
			zSearch(x, y + length, length);
		else
			cnt += val;
		if (x + length <= c && c < x + length + length && y+ length <= r && r  < y + length + length)
			zSearch(x + length, y + length, length);
		else
			cnt += val;
	}
}


int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n >> r >> c;

	zSearch(0, 0, pow(2, n));
	return 0;
}