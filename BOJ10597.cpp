#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

using namespace std;

bool isComplete = false;

string str;
set<int> s;
vector<int> v;
int nlen = 0;

void func(int start) {
	static int count = 0;

	if (!isComplete) {
		if (s.size() != nlen) {
			for (int i = 0; i < 2; i++) {
				int val = stoi(str.substr(start, 1 + i));
				if (val == 0 || val > nlen)
					return;
				s.insert(val);
				v.push_back(val);
				count++;

				if (s.size() != count) {
					v.pop_back();
					count--;
					continue;
				}

				func(start + 1 + i);
				s.erase(val);
				v.pop_back();
				count--;
			}
		}
		else {
			int exVal = -1;
			bool isFailed = false;
			for (int val : s) {
				if (exVal == -1)
					exVal = val;
				else {
					if (exVal + 1 != val) {
						isFailed = true;
						break;
					}
					exVal = val;
				}
			}
			if (!isFailed) {
				for (int val : v) {
					cout << val << ' ';
				}
				isComplete = true;
			}
		}
	}
}

int main(void) {

	int i = 1;
	cin >> str;

	if (str.length() > 9)
		nlen = (str.length() - 9) / 2 + 9;
	else
		nlen = str.size();
	func(0);
	return 0;
}