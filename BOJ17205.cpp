#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

unsigned long long cnt = 0;
long long arr[11] = { 1, 26 };
int len = 0;

void func(string password, int pos, int left) {

	char chr = 'a';
	long long total = 0;
	
	for (int i = 0; i < len - pos; i++) {
		total += arr[i];
	}

	while (chr != password[pos]) {
		cnt += total;
		chr++;
	}

	if (pos + 1 == password.size()) {
		cnt++;
		return;
	}

	else{
		cnt++;
		func(password, pos + 1, left - 1);
	}

}

int main(void) {
	string s;

	cin >> len;
	cin >> s;

	for (int i = 2; i < 11; i++) {
		arr[i] = arr[i-1] * 26;
		//cout << arr[i] << ' ';
	}

	//cout << '\n';
	func(s, 0, len);

	cout << cnt;
	return 0;
}