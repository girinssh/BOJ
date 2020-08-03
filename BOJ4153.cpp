#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main(void) {

	while(1) {
		set<int> s;
		set<int>::iterator iter;
		int total = 0;

		for (int i = 0; i < 3; i++) {
			int t = 0;
			cin >> t;
			s.insert(t);
		}
		if (s.size() == 1 && *s.begin() == 0)
			break;
		
		iter = s.begin();
		total += (*iter) * (*iter);
		iter++;
		total += (*iter) * (*iter);
		iter++;

		if (total == (*iter) * (*iter))
			cout << "right" << '\n';
		else
			cout << "wrong" << '\n';
	}
	return 0;
}