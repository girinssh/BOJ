#include <iostream>

using namespace std;

int main(void) {
	string a, b;

	cin >> a >> b;

	if (a.size() < b.size()) {
		int n = b.size() - a.size() + 1;
		int minDiff = 50;
		for (int i = 0; i < n; i++) {
			int diff = 0;
			for(int j = 0; j < a.size(); j++){
				if (a[j] != b[i + j]) {
					diff++;
				}
			}
			if (minDiff > diff) {
				minDiff = diff;
			}
		}
		cout << minDiff;
	}

	else if (a.size() > b.size()) {
		a.swap(b);
		int n = b.size() - a.size() + 1;
		int minDiff = 50;
		for (int i = 0; i < n; i++) {
			int diff = 0;
			for (int j = 0; j < a.size(); j++) {
				if (a[j] != b[i + j]) {
					diff++;
				}
			}
			if (minDiff > diff) {
				minDiff = diff;
			}
		}
		cout << minDiff;
	}
	else {
		int diff = 0;
		for (int j = 0; j < a.size(); j++) {
			if (a[j] != b[j]) {
				diff++;
			}
		}
		cout << diff;
	}
	return 0;
}