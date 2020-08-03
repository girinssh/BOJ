#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int N, Q;
	vector<int> diff;

	int temp = -1;

	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N >> Q;

	for (int i = 0; i < N; i++) {
		int a = 0;
		cin >> a;
		if (temp != -1)
			diff.push_back(abs(temp - a));
		temp = a;
	
	}

	for (int i = 0; i < Q; i++) {
		int s, e;
		cin >> s >> e;

		if (s >= e)
			cout << 0 << '\n';
		else {
			int total = 0;
			for (int j = s; j < e; j++) {
				total += diff[j-1];
			}
			cout << total << '\n';
		}
	}
	return 0;
}