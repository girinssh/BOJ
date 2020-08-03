#include <iostream>

using namespace std;

int cmp(const void* a, const void* b) {
	int aa = *(int*)a;
	int bb = *(int*)b;

	if (aa < bb) return -1;
	else if (aa == bb) return 0;
	else return 1;
}

int main(void) {
	int arr[50] = { 0 };
	int l;
	int n;

	cin >> l;
	for (int i = 0; i < l; i++) 
		cin >> arr[i];
	
	qsort(arr, l + 1, sizeof(int), cmp);

	cin >> n;

	if (l <= 1) {
		cout << 0;
		return 0;
	}

	int i = 0;
	while (!(arr[i] <= n && arr[i + 1] >= n)) {
		i++;
	}
	if (arr[i] == n || arr[i + 1] == n)
		cout << 0;
	else {
		int cnt = (n - arr[i]) * ((arr[i + 1]) - n) - 1;

		cout << cnt;
	}
	return 0;
}