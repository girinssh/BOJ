#include <iostream>
#include <map>
#include <set>

using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		map<string, int> closet;
		int n;

		cin >> n;

		while (n--) {
			string name, kind;

			cin >> name >> kind;

			closet[kind]+=1;
		}

		int cnt = 0;

		for (map<string, int>::iterator iter = closet.begin(); iter != closet.end(); iter++) {
			if (cnt == 0) {
				cnt += iter->second+1;
			}
			else {
				cnt *= iter->second+1;
			}
		}
		if(cnt != 0)
			cnt--;

		cout << cnt << '\n';
	}
	return 0;
}