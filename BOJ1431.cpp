#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(string &a, string &b) {
	int total[2] = { 0 };
	string parseS[2] = { "", "" };
	string originalS[2] = { a, b };

	//cout << a << ' ' << b << ' ';

	if (a.size() > b.size()) {
		//cout << "TRUE" << '\n';
		return false;
	}
	else if (a.size() < b.size()) {
		//cout << "FALSE" << '\n';
		return true;
	}
	else {
		for (int i = 0; i < (int)(a.size()); i++) {
			for (int j = 0; j < 2; j++) {
				if (isalpha(originalS[j][i])) {
					parseS[j] += originalS[j][i];
				}
				else {
					total[j] += originalS[j][i] - '0';
				}
			}
		}
		if (total[0] > total[1]) {
			//cout << "TRUE" << '\n';
			return false;
		}
		else if(total[0] < total[1]){
			//cout << "FALSE" << '\n';
			return true;
		}
		else {
			if (originalS[0] > originalS[1]) {
				//cout << "TRUE" << '\n';
				return false;
			}
			else {
				//cout << "FALSE" << '\n';
				return true;
			}
		}
	}
	
}

int main(void) {
	int n;
	vector<string> serials;

	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		serials.push_back(s);
	}

	sort(serials.begin(), serials.end(), compare);

	vector<string>::iterator iter = serials.begin();

	while(iter != serials.end()){
		cout << *iter << '\n';
		iter++;
	}
	return 0;
}