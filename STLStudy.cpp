#include <iostream>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main(void) {
	set<string> s;

	s.insert("ÇÏ");
	s.insert("°¡");
	
	for (string a : s) {
		cout << a << ' ';
	}

	map<char, int> m;

	m['a'] = 1;
	m['b'] = 5;
	m['c']++;

	return 0;
}