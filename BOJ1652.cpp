#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main(void) {
	char arr[100][100] = { 0 };

	int n = 0;
	int garo = 0, sero = 0;
	int temp = scanf("%d", &n);
	while (getchar() != '\n');

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = getchar();
		}
		while (getchar() != '\n');
	}

	for (int i = 0; i < n; i++) {
		int g = 0; 
		int s = 0; 
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == '.') 
				g++;
			else 
				g = 0;
			if (arr[j][i] == '.')
				s++;
			else
				s = 0;

			if (g == 2) 
				garo++;
			
			if (s == 2) 
				sero++;
		}
		//printf("%d %d\n", garo, sero);
	}

	printf("%d %d", garo, sero);
	return 0;
}