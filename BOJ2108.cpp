#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>

using namespace std;

int main(void) {
	int total = 0;
	set<int> maxCountedNum;
	int maxCount = 0;
	map<int, int> m;

	int t = 0;
	int size = 0;
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> t;
	size = t;

	while (t--) {
		int n = 0;
		cin >> n;
		m[n]++;
		total += n;
		if (m[n] > maxCount) {
			maxCountedNum.clear();
			maxCount = m[n];
			maxCountedNum.insert(n);
		}
		else if (m[n] == maxCount) {
			maxCountedNum.insert(n);
		}
	}

	cout << (int)round((double)total/size)<< '\n';

	int temp = 0;
	for (pair<int, int> p : m) {
		temp += p.second;
		if (temp > size / 2) {
			cout << p.first << '\n';
			break;
		}
	}
	if ((maxCountedNum.size() > 1)) {
		set<int>::iterator iter = maxCountedNum.begin();
		iter++;
		cout << *iter << '\n';
	}
	else {
		cout << *(maxCountedNum.begin()) << '\n';
	}
	cout << m.rbegin()->first - m.begin()->first << '\n';

	return 0;
}