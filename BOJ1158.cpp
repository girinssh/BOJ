#include <iostream>

using namespace std;

int arr[5000] = { 0 };
bool check[5000] = { false };

int main(void) {

	int n, k;
	int totalCnt = 0;
	cin >> n >> k;

	int iter = k - 1;

	while (totalCnt != n) {
		arr[totalCnt] = iter;
		check[iter] = true;
		int cnt = 0;
		totalCnt++;

		while (cnt != k && totalCnt != n) {
			iter++;
			iter %= n;
			if (!check[iter])
				cnt++;
		}
		
	}
	cout << '<';
	for (int i = 0; i < n; i++) {
		cout << arr[i] + 1; 
		if(i != n-1)
			cout << ", ";
	}
	cout << '>';
	return 0;
}