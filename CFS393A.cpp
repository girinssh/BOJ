#include <iostream>

using namespace std;

int main(void) {
	int arr[26] = { 0 };
	char cs[] = { 'n', 'i', 'e', 't' };
	int cnt = 100;
	string s;
	cin >> s;

	for (char c : s) {
		arr[c - 'a']++;
	}
	for (char c : cs) {
		int div = 1;
		//cout << arr[c - 'a'] << ' ';
		if (c == 'n') {
			div = 2;
			arr[c - 'a']--;
		}
		if(c == 'e'){
			div = 3;
		}
		cnt = (arr[c - 'a'] / div < cnt ? (arr[c - 'a'] / div) : cnt);
	}
	cout << cnt;
	return 0;
}