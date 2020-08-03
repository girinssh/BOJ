#include <iostream>

using namespace std;

int main(void) {
	int e, s, m;
	int year = 1;
	cin >> e >> s >> m;

	e -= 1;
	s -= 1;
	m -= 1;

	int te, ts, tm;
	te = ts = tm = 0;

	while (te != e || ts != s || tm != m) {
		te++;
		ts++;
		tm++;
		te %= 15;
		ts %= 28;
		tm %= 19;
		year++;
	}

	cout << year;

	return 0;
}