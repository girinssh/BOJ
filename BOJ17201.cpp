#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int n = 0;
	bool isChained = true;
	
	vector<int> mag;
	
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;

	int b = 0;
	cin >> b;

	for (int i = 0; i < n * 2; i++) {
		int a = b % 10;
		mag.push_back(a);
		b /= 10;
	}

	for (int i = 0; i < n - 1; i++) {
		if (mag[1 + i * 2] == mag[2 + i * 2]) {
			isChained = false;
			break;
		}
	}
	if (isChained)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}