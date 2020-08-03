#include <iostream>

using namespace std;

long long arr[31][31] = { };

void func(int n, int r) {
	if (n == r || r == 0) {
		arr[n][n - r] = arr[n][r] = 1;
	}
	else {
		if (arr[n - 1][r - 1] == 0) 
			func(n - 1, r - 1);
		
		if(arr[n - 1][r] == 0)
			func(n - 1, r);

		arr[n][n - r] = arr[n][r] = arr[n - 1][r - 1] + arr[n - 1][r];
	}
}

int main(void) {
	int t;

	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> t;

	for (int j = 0; j < 31; j++) {
		func(30, j);
	}

	while (t--) {
		int n, m;

		cin >> n >> m;

		cout << arr[m][n] << '\n';
	}

	return 0;
}