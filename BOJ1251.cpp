#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	string str;
	string min;

	cin >> str;


	for (int p1 = 0; p1 < str.size() - 2; p1++) {
		for (int p2 = p1 + 1; p2 < str.size() - 1; p2++) {
			string temp1 = str.substr(0, p1 + 1);
			string temp2 = str.substr(p1+1, p2-p1);
			string temp3 = str.substr(p2+1, str.size() - p2);
			
			//cout << temp1 << ' ';
			//cout << temp2 << ' ';
			//cout << temp3 << '\n';

			reverse(temp1.begin(), temp1.end());
			reverse(temp2.begin(), temp2.end());
			reverse(temp3.begin(), temp3.end());

			temp1 += temp2 + temp3;
			
			if (temp1 < min || min.empty()) {
				min = temp1;
			}
		}
	}

	cout << min;
	return 0;
}