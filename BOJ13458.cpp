#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int n;
	vector<int> a;
	int b, c;

	long long total = 0;

	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		a.push_back(val);
	}
	cin >> b >> c;

	for (int val : a) {
		total += 1;
		val -= b;
		if(val > 0)
			total += val / c + (val % c == 0 ? 0 : 1);
	}
	cout << total;
	return 0;
}