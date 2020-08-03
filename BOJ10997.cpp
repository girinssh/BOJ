#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char data[399][397];

void star(int x, int y, int n);

int main(void) {
	int number;

	scanf("%d", &number);

	if (number == 1) {
		putchar('*');
		return 0;
	}

	star(4 * (number - 1), 0, number);

	for (int i = 0; i < 7 + 4 * (number - 2); i++) {
		for (int j = 0; j < 1 + 4 * (number - 1); j++) {
			if (data[i][j]) putchar('*');
			else putchar(' ');
		}
		putchar('\n');
	}

	return 0;
}

void star(int x, int y, int n) {
	if (n == 1) {
		for (int i = 0; i < 3; i++) {
			data[y + i][x] = '*';
		}
	}
	else {
		for (int i = 0; i < 1 + 4 * (n - 1); i++) { // 위랑 아래 부분
			data[y][x - i] = '*';
			data[y + 6 + 4 * (n - 2)][x - i] = '*';
		}
		for (int i = 1; i <= 5 + 4 * (n - 2); i++) { // 왼쪽 부분
			data[y + i][x - 4 * (n - 1)] = '*';
		}
		for (int i = 0; i < 4 * (n - 1); i++) { // 오른쪽 부분
			data[y + 2 + i][x] = '*';
		}
		data[y + 2][x - 1] = '*'; // 왼쪽으로 툭 튀어나온 점 부분

		star(x - 2, y + 2, n - 1);
	}
}
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main(void) {
//	int n;
//	cin >> n;
//
//	int col = 1 + 4 * (n - 1);
//	int row = 1 + 4 * (n - 1) + (n != 1 ? 2 : 0);
//
//	vector<vector<int>> v;
//
//	for (int r = 0; r < row; r++) {
//		v.push_back(vector<int>(col));
//	}
//	int px = col - 1;
//	int py = 0;
//	int dx = -1;
//	int dy = 1;
//
//	int lowLimX = -2;
//	int lowLimY = 0;
//	int highLimX = col + 1;
//	int highLimY = row + 1;
//
//	int centrex = 2*(n - 1);
//	int centrey = 2 * n;
//
//	if (n == 1)
//		centrey = 0;
//
//	do {
//		if (dx == -1)
//			lowLimX += 2;
//		else
//			highLimX -= 2;
//		while (px >= lowLimX && px <= highLimX) {
//			v[py][px] = 1;
//			px += dx;
//		}
//		dx *= -1;
//		px += dx;
//
//		if (dy == -1)
//			lowLimY += 2;
//		else
//			highLimY -= 2;
//		while (py >= lowLimY && py <= highLimY) {
//			v[py][px] = 1;
//			py += dy;
//		}
//		dy *= -1;
//		py += dy;
//	} while (px != centrex || py != centrey);
//
//	for (int r = 0; r < row; r++) {
//		for (int c = 0; c < col; c++) {
//			if (v[r][c] == 1) {
//				cout << '*';
//				if (r == 1)
//					break;
//			}
//			else
//				cout << ' ';
//		}
//		if(r != row -1)
//			cout << '\n';
//	}
//	return 0;
//}