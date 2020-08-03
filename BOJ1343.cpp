#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	vector<int> v;
	string s;
	cin >> s;

	int cnt = 0;
	int cntDot = 0;
	for (char c : s) {
		if (c == 'X') {
			if(cntDot != 0)
				v.push_back(2 * cntDot + 1);
			cntDot = 0;
			cnt++;
		}
		else {
			cntDot++;
			if (cnt % 2 == 1) {
				cout << -1;
				return 0;
			}
			else if(cnt != 0){
				v.push_back(cnt);
				cnt = 0;
			}
		}
	}
	if (cnt != 0) {
		if(cnt % 2 == 0)	
			v.push_back(cnt);
		else {
			cout << -1;
			return 0;
		}
	}
	if(cntDot != 0)
		v.push_back(2*cntDot+1);

	s.clear();

	for (int len : v) {
		if (len % 2 == 1) {
			len = (len - 1) / 2;
			while (len--) {
				s += ".";
			}
		}
		else {
			while (len > 0) {
				if (len >= 4) {
					s += "AAAA";
					len -= 4;
				}
				else {
					s += "BB";
					len -= 2;
				}
			}
		}
	}
	cout << s;
	return 0;
}