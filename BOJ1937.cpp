#include <iostream>
#include <algorithm>
#include <stack>

#define UP y+1
#define DOWN y-1
#define RIGHT x+1
#define LEFT x-1

using namespace std;

int arr[500][500] = { 0 };
int dp[500][500] = { 0 };
int n;
int maximum = 0;

void DFS(int i, int j) {

	int x = j;
	int y = i;
	int pass = 4;

	if (UP < n) {
		if (arr[UP][x] > arr[i][j]) {
			pass--;
			if (dp[UP][x] != 0) {
				
			}
			else {
				DFS(UP, x);
			}
			dp[i][j] = dp[UP][x] + 1 > dp[i][j] ? dp[UP][x] + 1 : dp[i][j];
		}
	}
	if (RIGHT < n) {
		if (arr[y][RIGHT] > arr[i][j]) {
			pass--;

			if (dp[y][RIGHT] != 0) {
			}
			else {
				DFS(y, RIGHT);
			}
			dp[i][j] = dp[y][RIGHT] + 1 > dp[i][j] ? dp[y][RIGHT] + 1 : dp[i][j];

		}
	}
	if (DOWN >= 0) {
		if (arr[DOWN][x] > arr[i][j]) {
			pass--;

			if (dp[DOWN][x] != 0) {
			}
			else {
				DFS(DOWN, x);
			}
			dp[i][j] = dp[DOWN][x] + 1 > dp[i][j] ? dp[DOWN][x] + 1 : dp[i][j];
		}
	}
	if (LEFT >= 0) {
		if (arr[y][LEFT] > arr[i][j]) {
			pass--;

			if (dp[y][LEFT] != 0) {
			}
			else {
				DFS(y, LEFT);
			}
			dp[i][j] = dp[y][LEFT] + 1 > dp[i][j] ? dp[y][LEFT] + 1 : dp[i][j];
		}
	}
	if (pass == 4) {
		dp[i][j] = 1;
	}
	if (maximum < dp[i][j]) {
		maximum = dp[i][j];
	}
}

int main(void) {
	
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(dp[i][j] == 0)
				DFS(i, j);
		}
	}

	cout << maximum;
	return 0;
}