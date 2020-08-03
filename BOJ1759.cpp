#include <iostream>
#include <set>
#include <vector>

using namespace std;

int L, C;

void rec(set<char>& s, string& str) {
	if (str.size() == L) {
		int e = 0, o = 0;

		for (char c : str) {
			if (c == 'a' || c == 'o' || c == 'e' || c == 'i' || c == 'u')
				e++;
			else
				o++;
		}
		if(e >= 1 && o >= 2)
			cout << str << '\n';
	}
	else {
		set<char>::iterator iter = s.begin();

		if (!str.empty())
			iter = s.upper_bound(str.back());

		while (iter != s.end()) {
			char c = *iter;
			str.push_back(c);

			s.erase(c);
			rec(s, str);

			str.pop_back();
			s.insert(c);
			iter = s.find(c);

			iter++;
		}
	}
}

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> L >> C;

	set<char> s;
	string str;
	for (int i = 0; i < C; i++) {
		char c;
		cin >> c;
		s.insert(c);
	}

	rec(s, str);

	return 0;
}