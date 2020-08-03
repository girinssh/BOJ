#include <iostream>

using namespace std;

int main(void) {

	int n;
	int total = 1;


	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		total += 3 * i + 1;
		total %= 45678;
	}

	cout << total;

	return 0;
}