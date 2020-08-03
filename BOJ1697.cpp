#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int arr[100001] = { 0 };

int main(void) {
	int n = 0; 
	int k = 0;
	int time = 0;
	queue<int> pos;
	int pass = 1;
	int nextPass = 0;

	cin >> n >> k;

	arr[k] = 1;
	arr[n] = 2;

	if (n != k) {
		pos.push(n);

		while (!pos.empty()) {
			int npos = pos.front();
			pos.pop();
			pass--;
			int p[] = { npos - 1, npos + 1, npos * 2 };

			for (int i = 0; i < 3; i++) {
				if (p[i] > 100000 || p[i] < 0 || arr[p[i]] == 2)
					continue;
				arr[p[i]] = 2;
				pos.push(p[i]);
				nextPass++;
			}
			if (pass == 0) {
				pass = nextPass;
				nextPass = 0;
				time++;
			}
			if (arr[k] != 1)
				break;
		}
		if (nextPass != 0)
			time++;
	}
	cout << time;
	return 0;
}

