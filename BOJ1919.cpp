#include <iostream>
#include <cmath>
using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	string a;
	string b;

	cin >> a;
	cin >> b;

	int arr[26] = {0};
	int brr[26] = {0};

	for (char c : a) {
		arr[(int)c - 'a']++;
	}
	for (char c : b) {
		brr[(int)c - 'a']++;
	}

	int total = 0;

	for (int i = 0; i < 26; i++) {
		total += abs(arr[i] - brr[i]);
	}

	cout << total << '\n';
	return 0;
}