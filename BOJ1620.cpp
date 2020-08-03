#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	map<string, int> pm;
	vector<string> pv;

	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		pm[s] = i;
		pv.push_back(s);
	}

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;

		if (isalpha(s[0])) {
			cout << pm[s] << '\n';
		}
		else {
			cout << pv[stoi(s) - 1] << '\n';
		}
	}
	return 0;
}