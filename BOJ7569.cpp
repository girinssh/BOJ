#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int arr[100][100][100] = { 0 };
int cnt = 0;
int m, n, h;
queue<int> mq, nq, hq;

int bfs() {
	int maxDay = 0;

	while (!mq.empty()) {
		int mm = mq.front();
		int nn = nq.front();
		int hh = hq.front();
		int day = arr[hh][nn][mm];
		mq.pop();
		nq.pop();
		hq.pop();

		for (int d = -1; d <= 1; d += 2) {
			int dh = hh + d;
			int dn = nn + d;
			int dm = mm + d;
			
			if (dh > -1 && dh < h && arr[dh][nn][mm] == 0) {
				arr[dh][nn][mm] = day + 1;
				mq.push(mm);
				nq.push(nn);
				hq.push(dh);
			}
			if (dn > -1 && dn < n && arr[hh][dn][mm] == 0) {
				arr[hh][dn][mm] = day + 1;
				mq.push(mm);
				nq.push(dn);
				hq.push(hh);
			}
			if (dm > -1 && dm < m && arr[hh][nn][dm] == 0) {
				arr[hh][nn][dm] = day + 1;
				mq.push(dm);
				nq.push(nn);
				hq.push(hh);
			}
		}
		if (day > maxDay)
			maxDay = day;
	}
	return maxDay - 1;
}

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> m >> n >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 0)
					cnt++;
				else if (arr[i][j][k] == 1) {
					mq.push(k);
					nq.push(j);
					hq.push(i);
				}
			}
		}
	}

	int day = bfs();
	bool isFailed = false;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (arr[i][j][k] == 0) {
					day = -1;
					isFailed = true;
					break;
				}
			}
			if (isFailed)
				break;
		}
		if (isFailed)
			break;
	}
	cout << day;
	return 0;
}