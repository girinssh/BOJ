#include <iostream>
#include <map>

using namespace std;

int main(void) {
	int n, m;
	int cnt = 0;
	map<string, int> mem;

	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		mem[s]++;
	}
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		mem[s]--;
		if (mem[s] == 0) {
			cnt++;
		}
	}
	cout << cnt << '\n';
	for (pair<string, int> s : mem) {
		if(s.second == 0)
			cout << s.first << '\n';
	}
	return 0;
}