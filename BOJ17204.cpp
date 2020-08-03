#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main(void) {
	vector<int> pointer;
	int N, K;
	bool isFailed = true;
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int a = 0;
		cin >> a;
		pointer.push_back(a);
		if (a == K)
			isFailed = false;
	}

	if (isFailed) {
		cout << -1;
	}
	else {
		int cnt = 0;
		int pos = 0;
		set<int> s;
		while (true) {
			cnt++;
			pos = pointer[pos];
			if (s.find(pos) != s.end()) {
				cout << -1;
				break;
			}
			else if (pos == K) {
				cout << cnt;
				break;
			}
			s.insert(pos);
		}
	}
	return 0;
}