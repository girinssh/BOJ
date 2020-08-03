#include <iostream>

using namespace std;

int main(void) {
	int n;
	string arr[3] = { "ABC", "BABC", "CCAABB" };
	string name[3] = { "Adrian", "Bruno", "Goran" };
	int score[3] = { 0 };
	string s;
	
	cin >> n;
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < 3; j++) {
			if (s[i] == arr[j][i % arr[j].size()]) {
				score[j] ++;
			}
		}
	}

	int max = 0;
	for (int j = 0; j < 3; j++) {
		if (score[j] > max) {
			max = score[j];
		}
	}
	cout << max << '\n';
	for (int j = 0; j < 3; j++) {
		if (score[j] == max) {
			cout << name[j] << '\n';
		}
	}
	return 0;
}