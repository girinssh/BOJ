#include <iostream>
#include <algorithm>

using namespace std;

int cmp(const void *a, const void *b) {
	if (*(int*)a < *(int*)b) return -1;
	if (*(int*)a ==*(int*)b) return 0;
	if (*(int*)a > *(int*)b) return 1;
}

int main(void) {
	int n;
	int p[50] = { 0 };
	int a[50] = { 0 };
	int b[50] = { 0 };

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}

	qsort(b, n, sizeof(int), cmp);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i] == b[j]) {
				//cout << b[j] << '\n';
				p[i] = j;
				b[j] = -1;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << p[i] << ' ';
	}
	return 0;
}