#include<iostream>
#include <cmath>

using namespace std;

void hanoi(int n, int from, int by, int dest) {
	if (n == 1) {
		cout << from << ' ' << dest << '\n';
	}
	else {
		hanoi(n - 1, from, dest, by);
		cout << from << ' ' << dest << '\n';
		hanoi(n - 1, by, from, dest);
	}
}

int main(void) {
	int n; 

	cin >> n;
	cout.setf(ios::fixed);
	cout.precision(0);
	cout << long double (pow(2, n) - 1) << '\n';

	if (n > 20)
		return 0;

	hanoi(n, 1, 2, 3);

	return 0;
}