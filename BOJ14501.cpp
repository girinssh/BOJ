#include <iostream>
#include <algorithm>
using namespace std;

int arr[15][2]; // [T, P]
int maxPrice = 0;

void func(int nowDay, int nowPrice, int maxDay) {

	if (nowDay > maxDay){
		if (nowPrice > maxPrice) {
			maxPrice = nowPrice;
		}
	}


	else {
		int nextDay = nowDay + arr[nowDay - 1][0];
		int price = nowPrice;

		if (nextDay - 1 <= maxDay)
			price += arr[nowDay - 1][1];

		do {
			func(nextDay, price, maxDay);
			nextDay++;
		} while (nextDay <= maxDay);
	}
}

int main(void) {

	int n = 0;

	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	for (int day = 1; day <= n; day++) {
		func(day, 0, n);
	}
	cout << maxPrice;
	return 0;
}