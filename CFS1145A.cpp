#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

int main(void) {
	list<list<int>> v;
	int n;
	bool isFailed = true;

	cin >> n;
	{
		list<int> l;

		for (int i = 0; i < n; i++) {
			int val;
			cin >> val;
			l.push_back(val);

		}
		v.push_back(l);
	}

	while (isFailed) {
		bool isClear = true;
		list<int> l = v.front();
		list<int>::iterator iter = l.begin();
		v.pop_front();

		int past = 0;
		for (int curr : l) {
			if (curr < past) {
				isClear = false;
				advance(iter, l.size() / 2);
				v.push_back(list<int>(l.begin(), iter));
				v.push_back(list<int>(iter, l.end()));
				break;
			}
			past = curr;
		}
		if (isClear) {
			cout << l.size();
			isFailed = false;
		}
	}
	return 0;
}