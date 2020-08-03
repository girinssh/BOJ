#include <iostream>

using namespace std;

int arr[21] = { 0 };

void func(int a[10], int iter, int n, char s[10][10]) {
	static bool isClear = false;

	for (int i = 0; i < 21; i++) {
		a[iter] = arr[i];
		
		bool isFailed = true;
		for (int j = 0; j <= iter; j++) {
			int tot = 0;
			for (int k = j; k <= iter; k++) {
				tot += a[k];

				if((tot > 0 && s[j][k] == '+') 
					|| (tot < 0 && s[j][k] == '-')
					|| (tot == 0 && s[j][k] == '0')){
					isFailed = false;
				}
				else {
					isFailed = true;
					break;
				}
			}
			if (isFailed)
				break;
		}
		if (!isFailed) {
			if (iter == n - 1) {
				isClear = true;
				for (int j = 0; j < n; j++) {
					cout << a[j] << ' ';
				}
				break;
			}

			func(a, iter + 1, n, s);
		}
		if (isClear)
			break;
	}
}

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	for (int i = 0; i < 21; i++) {
		arr[i] = i - 10;
	}

	int n;
	char s[10][10];
	int A[10] = { 0 };

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			cin >> s[i][j];
		}
	}

	func(A, 0, n, s);
	return 0;

}