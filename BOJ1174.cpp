#include <iostream>

using namespace std;

int main(void) {
	int n;
	int cnt = 0;
	int size = 1;
	int arr[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	cin >> n;
	
	while(cnt != n){
		arr[0]++;
		for (int i = 0; i < size; i++) {
			if (i < size - 1) {
				if (arr[i] >= arr[i + 1]) {
					arr[i + 1]++;
					for (int j = 0; j <= i; j++) {
						arr[j] = j;
					}
					i = 0;
				}
			}
			else {
				if (arr[i] > 9) {
					if (size == 10) {
						cout << -1;
						return 0;
					}
					size++;
					for (int j = 0; j < size; j++) {
						arr[j] = j;
					}
				}
			}
		}
		cnt++;
	}
	
	for (int i = size - 1; i >= 0; i--) {
		if (arr[i] != -1)
			cout << arr[i];
	}
	
	return 0;
}