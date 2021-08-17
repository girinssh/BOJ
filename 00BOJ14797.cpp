#include <iostream>
#include <vector>
#include <set>

using namespace std;

void func(vector<string>& v, set<char>& s, int r, int c) {
	set<char>::iterator iter = s.begin();

	while (iter != s.end()) {

	}
}

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);


	int t;
	cin >> t;

	for(int test = 1; test<= t; test++) {
		cout << "Case #" << test << "\n";
		int r, c;

		cin >> r >> c;

		vector<string> v;
		set<char> s;

		for (int i = 0; i < r; i++) {
			string str;
			cin >> str;

			v.emplace_back(str);
			s.insert(str.begin(), str.end());
		}

		
	}

	
}