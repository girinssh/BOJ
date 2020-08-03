#include <iostream>

#define pow(x) ((x)*(x))

using namespace std;

int main(void) {
	int n;
	cin >> n;

	int minCnt = 4;
	int val = 0;
	for (int i = 0; i <= 100; i++) {
		val = pow(i);
		if (val > n)
			break;
		for (int j = i; j <= 200; j++) {
			int vj = pow(j);
			val += vj;
			if (val > n) {
				val -= vj;
				break;
			}
			for (int k = j; k <= 500; k++) {
				int vk = pow(k);
				val += vk;
				if (val > n) {
					val -= vk;
					break;
				}
				for (int l = k; l <= 500; l++) {
					if (val + pow(l) == n) {
						int cnt = 4;
						if (i == 0)
							cnt--;
						if (j == 0)
							cnt--;
						if (k == 0)
							cnt--;
						if (l == 0)
							cnt--;
						if (cnt < minCnt)
							minCnt = cnt;
					}
					else if (val + pow(l) > n)
						break;
				}
				val -= vk;
			}
			val -= vj;
		}
	}

	cout << minCnt;

	return 0;
}