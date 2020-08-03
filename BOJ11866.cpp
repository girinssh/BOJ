#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main(void) {
	int n, k;
	int pos = 0;
	list<int> l;
	list<int>::iterator iter;

	cin >> n >> k;
	cout << '<';
	for (int i = 1; i <= n; i++) {
		pos++;
		if (pos % k == 0) {
			if (i != k)
				cout << ", ";
			cout << i;
			pos = 0;
			continue;
		}
		l.push_back(i);
	}
	iter = l.begin();

	while (!l.empty()) {
		pos++;
		if (pos % k == 0) {
			cout << ", ";
			cout << *iter;
			pos = 0;
			
			list<int>::iterator del = iter;
			iter++;
			l.erase(del);
		}
		else {
			iter++;
		}
		if (iter == l.end()) {
			iter = l.begin();
		}
	}
	cout << '>';
	return 0;
}