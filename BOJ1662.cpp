#include <iostream>
#include <algorithm>

using namespace std;

string total = "";

int Recursion(string s) {
	int len = 0;
	int pos = 0;
	int start = -1, end = s.size()-1;
	int mul = 1;

	int stack = 0;
	for (; pos < s.size(); pos++) {
		if (s[pos] == '(') {
			if (stack == 0 && start == -1) {
				len--;
				mul = s[pos - 1] - '0';
				start = pos+1;
			}
			stack++;
		}
		else if (s[pos] == ')') {
			stack--;
			if (stack == 0) {
				end = pos;
				string temp = s.substr(start, end - start);
				cout << temp << '\n';

				start = -1;
				len += mul * Recursion(temp);
			}
				
		}
		else {
			if (start == -1)
				len++;
		}
	}


	return len;

}

int main(void) {
	string s;

	cin >> s;

	cout << Recursion(s);

	return 0;
}

//  33(562(71(9)))  =>  33(562(79)) => 33(567979) => 3567979567979567979