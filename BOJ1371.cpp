#include <iostream>

using namespace std;

int main(void) {
	int arr[26] = { 0 };
	int max = 0;
	int index = 0;

	cin.tie(NULL);
	cin.sync_with_stdio(false);

	while (!cin.eof()) {
		string l;
		cin >> l;

		for (char c : l) {
			if (isalpha(c) != 0) {
				arr[c - 'a']++;
				if (arr[c - 'a'] > max) {
					max = arr[c - 'a'];
				}
			}
		}
	}

	for (int i = 0; i < 26; i++) {
		if (arr[i] == max) {
			cout << char(i + 'a');
		}
	}
	return 0;
}