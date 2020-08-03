#include <iostream>
#include <list>

using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n, m;
	list<int> l1, l2;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		l1.push_back(val);
	}

	for (int i = 0; i < m; i++) {
		int val;
		cin >> val;
		l2.push_back(val);
	}

	list<int>::iterator iter1, iter2;

	iter1 = l1.begin();
	iter2 = l2.begin();

	while (iter1 != l1.end() || iter2 != l2.end()) {
		if (iter1 == l1.end()) {
			while (iter2 != l2.end()) {
				cout << *iter2 << ' ';
				iter2++;
			}
		}
		else if (iter2 == l2.end()) {
			while (iter1 != l1.end()) {
				cout << *iter1 << ' ';
				iter1++;
			}
		}
		else {
			if (*iter1 < *iter2) {
				cout << *iter1 << ' ';
				iter1++;
			}
			else {
				cout << *iter2 << ' ';
				iter2++;
			}
		}
	}
	return 0;
}