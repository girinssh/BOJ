#include <iostream>

using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);


	int t;
	cin >> t;

	for (int Case = 1; Case <= t; Case++) {
		string s;
		string output = "";
		int cnt = 0;
		cin >> s;

		for (char c : s) {
			int val = c - '0';

			if (val > cnt) {
				for (; cnt < val; cnt++) {
					output.push_back('(');
				}
			}
			else if (val < cnt) {
				for (; val < cnt; cnt--) {
					output.push_back(')');
				}
			}
			output.push_back(c);
		}

		for (; cnt > 0; cnt--) {
			output.push_back(')');
		}
		cout << "Case #" << Case << ": " << output << '\n';
	}
	return 0;
}