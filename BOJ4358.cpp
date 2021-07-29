#include <iostream>
#include <map>

using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	map<string, int> trees;
	int total = 0;

	while (!cin.eof()) {
		char name[31];
		cin.getline(name, 31);
		
		if (cin.eof())
			break;

		trees[string(name)]++;
		total++;
	}

	map<string, int>::iterator iter = trees.begin();

	cout << fixed;
	cout.precision(4);

	while (iter != trees.end()) {
		cout << iter->first << ' ' << (double)iter->second * 100 / (double)total << '\n';
		iter++;
	}
	return 0;
}