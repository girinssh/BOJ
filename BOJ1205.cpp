#include <iostream>
#include <map>
using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n, s, p;
	map<int, int> m;

	cin >> n >> s >> p;

	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;

		m[val]++;
	}
	
	int rank = 1;
	//int cnt = 0;
	for (auto value = m.rbegin(); value != m.rend(); value++) {
		//cnt++;
		if (value->first < s || (value->first == s && rank + value->second <= p)) {
			break;
		}
		else {
			rank += value->second;
		}
		if (rank > p) {
			rank = -1;
			break;
		}
	}
	
	cout << rank;

	return 0;
}