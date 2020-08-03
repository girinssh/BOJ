#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int t = 0;
	int arr[2]{ 0 };

	scanf("%d", &t);

	while (t--) {
		char n = getchar();
		if (n == 'L')
			arr[0]++;
		else
			arr[1]++;
	}
	while (getchar() != '\n');

	printf("%d", arr[0] + arr[1] + 1);
	return 0;
}