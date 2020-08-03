#include <iostream>
#include <set>
#include <algorithm>

using namespace std;



int main(void) {
	string arr[20];
	set<string> words;
	int r, c;

	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < r; i++) {
		string s;

		for (int j = 0; j < c; j++) {
			if (arr[i][j] == '#') {
				if (s.size() > 1)
					words.insert(s);
				s.clear();

			}
			else {
				s.push_back(arr[i][j]);
			}
		}
		if (s.size() > 1)
			words.insert(s);
	}
	for (int i = 0; i < c; i++) {
		string s;

		for (int j = 0; j < r; j++) {
			if (arr[j][i] == '#') {
				if (s.size() > 1)
					words.insert(s);
				s.clear();
			}
			else {
				s.push_back(arr[j][i]);
			}
		}
		if (s.size() > 1)
			words.insert(s);
	}

	cout << *words.begin();
	return 0;
}