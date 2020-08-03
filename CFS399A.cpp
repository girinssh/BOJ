#include <iostream>
#include <list>

using namespace std;

int main(void) {
	int n, p, k;
	bool printing = true;
	list<int> l;

	cin >> n >> p >> k;

	l.push_back(p);

	for (int i = p - 1; i >= p - k; i--) {
		if (i < 1) {
			continue;
		}
		else if (i == 1) {
			l.push_front(i);
		}
		else {
			l.push_front(i);
		}
	}
	for (int i = p + 1; i <= p + k; i++) {
		if (i > n) {
			break;
		}
		else if (i == n) {
			printing = false;
			l.push_back(i);
		}
		else
			l.push_back(i);
	}

	if(l.front() != 1)
		cout << "<< ";

	for (int i : l) {
		if (i != p)
			cout << i << ' ';
		else
			cout << '(' << i << ") ";
	}

	if (p == n)
		printing = false;

	if (printing)
		cout << ">>";
	return 0;

}