#include <iostream>
#include <set>

using namespace std;

int main(void) {
	int n;
	set<int> s;
	cin >> n;

	int a, b;

	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		s.insert(v);
	}

	cout << *s.begin() * *s.rbegin();
	return 0;
}