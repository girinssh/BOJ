#include <iostream>
#include <list>

using namespace std;

long long nation[1000][2] = { 0 };

int main(void) {
	int n, k;
	list<pair<long long, int>> l;

	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int arr[4];
		pair<long long, int> p;
		for (int j = 0; j < 4; j++) {
			cin >> arr[j];
		}
		
		p.first = arr[1] * 1000000000001 + (long long)arr[2] * 1000001 + arr[3];
		p.second = arr[0];

	//	cout << p.first << '\n';
		l.push_back(p);
	}
	l.sort(greater<pair<long long, int>>());

	int rank = 0;
	long long befScore = 0;
	int total = 0;
	for (pair<long long, int> p : l) {
		if (p.first != befScore) {
			rank += total + 1;
			total = 0;
		}
		else {
			total++;
		}
		if (p.second == k) {
			cout << rank;
			break;
		}
		befScore = p.first;
	}
	return 0;
}