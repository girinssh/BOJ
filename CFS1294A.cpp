#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {

	int t;
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> t;

	while (t--) {

		int arr[3];

		int n;

		cin >> arr[0] >> arr[1] >> arr[2] >> n;

		sort(arr, arr+3);

		if (2 * arr[2] - arr[0] - arr[1] > n) {
			cout << "NO";
		}
		else {
			int da1 = arr[2] - arr[0];
			arr[0] = arr[2];
			n -= da1;
			int da2 = arr[2] - arr[1];
			arr[1] = arr[2];
			n -= da2;

			if (n % 3 != 0) {
				cout << "NO";
			}
			else {
				cout << "YES";
			}
		}
		cout << '\n';
	}
	return 0;
}