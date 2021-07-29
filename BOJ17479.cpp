#include <iostream>
#include <map>
#include <set>

using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	map<string, long long> normal, special;
	set<string> service;

	int a, b, c;
	cin >> a >> b >> c;

	for (int i = 0; i < a; i++) {
		string name;
		long long cost;
		cin >> name >> cost;
		normal[name] = cost;
	}
	for (int i = 0; i < b; i++) {
		string name;
		long long cost;
		cin >> name >> cost;
		special[name] = cost;
	}
	for (int i = 0; i < c; i++) {
		string name;
		cin >> name;
		service.insert(name);
	}

	long long nCost = 0;
	long long tCost = 0;
	int serCnt = 0;

	int orderCnt = 0;
	cin >> orderCnt;

	for (int i = 0; i < orderCnt; i++) {
		string menu;
		cin >> menu;

		if (normal[menu] != 0) {
			long long c = normal[menu];
			nCost += c;
			tCost += c;
		}
		else if (special[menu] != 0) {
			long long c = special[menu];
			tCost += c;
		}
		else if(service.find(menu) != service.end()){
			serCnt++;
		}
	}

	bool isCorrect = true;
	if (nCost != tCost) {
		if (nCost < 20000)
			isCorrect = false;
	}
	if (serCnt > 0) {
		if (tCost < 50000)
			isCorrect = false;
		if (serCnt > 1)
			isCorrect = false;
	}

	cout << (isCorrect ? "Okay" : "No");
	return 0;
}