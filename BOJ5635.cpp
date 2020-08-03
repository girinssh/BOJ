#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(void) {
	int t = 0;
	map <pair<int, pair<int, int>>, string> brth;

	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> t;

	while (t--) {
		string name;
		int year, month, day;
		cin >> name >> day >> month >> year;

		brth[make_pair(year, make_pair(month, day))] = name;
	}

	map <pair<int, pair<int, int>>, string>::iterator iter = brth.end();
	iter--;

	cout << iter->second << '\n';
	iter = brth.begin();
	cout << iter->second;
	return 0;
}