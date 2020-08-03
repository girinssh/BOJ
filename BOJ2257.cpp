#include <iostream>
#include <algorithm>

#define H 1
#define C 12
#define O 16

using namespace std;

int rec(string s) {
	int pos = 0;
	int start = -1;
	int end = -1;
	int mul = 1;
	int totalSize = 0;
	int deltaSize = 0;
	int stack = 0;


	while (pos < s.size()) {
		if (s[pos] == '(') {
			if(start == -1)
				start = pos + 1;
			stack++;
		}
		else if (s[pos] == ')') {
			stack--;
			if (stack == 0) {

				end = pos;
				if ('0' <= s[pos + 1] && s[pos + 1] <= '9') {
					mul = s[pos + 1] - '0';
					pos++;
				}
				else
					mul = 1;
				string temp = s.substr(start, end - start);
				//cout << temp << ' ';

				totalSize += mul * rec(temp);

				start = -1;
				end = -1;
			}
		}
		else if (isalpha(s[pos]) && start == -1) {
			totalSize += deltaSize;
			if (s[pos] == 'H')
				deltaSize = H;
			else if (s[pos] == 'C')
				deltaSize = C;
			else
				deltaSize = O;
		}
		else {
			if (start == -1) {
				totalSize += deltaSize * (s[pos] - '0');
				deltaSize = 0;
			}
		}
		pos++;
	}
	totalSize += deltaSize;

	//cout << totalSize << '\n';
	return totalSize;
}

int main(void) {
	string s;
	int size = 0;
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> s;

	size = rec(s);

	cout << size;

	return 0;
	
}