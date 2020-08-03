#include <iostream>
#include <set>

using namespace std;

void func(set<int>& s, set<int>& output) {
	if (output.size() == 6) {
		for (int val : output) {
			cout << val << ' ';
		}
		cout << '\n';
	}
	else {
		set<int>::iterator iter = s.begin();

		if (!output.empty())
			iter = s.upper_bound(*output.rbegin());

		while (iter != s.end()) {
			int val = *iter;
			s.erase(val);
			output.insert(val);

			func(s, output);

			output.erase(val);
			s.insert(val);
			iter = s.find(val);
			iter++;
		}
	}
}

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	while (true) {
		int n;
		cin >> n;

		if (n == 0)
			break;

		set<int> s, out;

		for (int i = 0; i < n; i++) {
			int val;
			cin >> val;

			s.insert(val);
		}

		func(s, out);
		cout << '\n';
	}
	return 0;
}