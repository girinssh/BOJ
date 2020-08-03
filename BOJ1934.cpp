#include <iostream>

using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int t;
	cin >> t;

	while (t--) {
		int a, b;
		int add;
		cin >> a >> b;
		if (a < b) {
			int temp = a;
			a = b;
			b = temp;
		}

		add = a;
		while (a % b != 0) {
			a += add;
		}
		cout << a << '\n';
	}
	return 0;
}