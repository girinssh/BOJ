#include <iostream>

using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	char arr[50][50] = { 0 };
	int a, b;
	int n = 0, m = 0;
	cin >> a >> b;

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			if (arr[i][j] == 'X') {
				n++;
				break;
			}
		}
	}
	for (int i = 0; i < b; i++) {
		for (int j = 0; j < a; j++) {
			if (arr[j][i] == 'X') {
				m++;
				break;
			}
		}
	}

	cout << (a - n > b - m ? a - n : b - m);
	return 0;
}

/*
XXXXXXXXXXXXXXXXXXXX
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
....................
*/