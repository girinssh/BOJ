#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(void) {
	set<int> triangleNum;
	int t;
	{
		int i = 1;
		int num = 0;
		do {
			triangleNum.insert(num + i);
			num += i;
			i++;
		} while (num < 1000);
	}
	cin >> t;

	while (t--) {
		int k;
		bool flag = false;
		cin >> k;

		set<int>::iterator iter1 = triangleNum.begin(), iter2;
		
		while (iter1 != triangleNum.end() && !flag) {
			iter2 = iter1;
			while (iter2 != triangleNum.end() && !flag) {
				if (triangleNum.find(k - *iter1 - *iter2) != triangleNum.end()) {
					cout << 1 << '\n';
					flag = true;
				}
				iter2++;
			}
			iter1++;
		}
		if (!flag)
			cout << 0 << '\n';
	}
	return 0;
}