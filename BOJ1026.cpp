#include <iostream>

using namespace std;

int cmp(const void* a, const void* b) {
	int n1 = *(int*)a;
	int n2 = *(int*)b;

	if (n1 < n2) return -1;
	else if (n1 == n2) return 0;
	else return 1;
}

int main(void) {

	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int a[50] = { 0 };
	int b[50] = { 0 };
	int s = 0;
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	qsort(a, n, sizeof(int), cmp);

	for (int i = 0; i < n; i++) {
		int max = 0;
		int index = 0;

		for (int j = 0; j < n; j++) {
			if (b[j] > max) {
				max = b[j];
				index = j;
			}
		}

		s += max * a[i];
		b[index] = -1;
	}

	cout << s;
	return 0;
}