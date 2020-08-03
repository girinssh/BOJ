#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main(void) {
	string n1;
	string n2;

	list<int> result;

	cin >> n1 >> n2;

	int pos = 1;
	int adder = 0;
	while(true) {
		int value = 0;

		if (pos <= n1.size()) {
			value += n1[n1.size() - pos] - '0';
		}
		if (pos <= n2.size()) {
			value += n2[n2.size() - pos] - '0';
		}
		if (pos > n1.size() && pos > n2.size())
			break;

		value += adder;
		adder = value / 10;
		value %= 10;

		result.push_front(value);
		if (pos > n1.size() && pos > n2.size())
			break;
		pos++;
	}

	if (adder != 0)
		cout << adder;

	for (int v : result)
		cout << v;
	return 0;
}