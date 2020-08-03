#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n;
	int total = 0;
	vector<int> v;
	
	cin >> n;

	v.push_back(n);

	while (v.size() != n) {
		int lim = v.size();
		int pos = 0;
		for (int i = 0; i < lim; i++) {
			if (v[i] == 1)
				continue;
			if (v[i] % 2 == 0) {
				v[i] /= 2;
				v.push_back(v[i]);
				total += v[i] * v[i];
			}
			else {
				v[i] /= 2;
				v.push_back(v[i] + 1);
				total += v[i] * v.back();
			}
		}
	}
	cout << total;
	return 0;
}