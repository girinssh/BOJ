#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {

	int n = 0;
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;

	vector<int> NGE;
	vector<int>::iterator top;
	vector<int>::iterator iter;
	while (n--) {
		int value;
		cin >> value;

		NGE.push_back(value);
	}

	top = NGE.end();
	top--;


	return 0;
}