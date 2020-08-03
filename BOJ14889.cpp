#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int S[20][20] = { 0 };
int minDiff = 10000000;

void rec(int num, int size, set<int> arr = set<int>() ) {
	arr.insert(num);

	if (arr.size() *2 == size) {
		int diff = 0;
		int total1 = 0 , total2 = 0;
		set<int> arr2;
		for (int i = 0; i < size; i++) {
			if (arr.find(i) == arr.end())
				arr2.insert(i);
		}
		set<int>::iterator ar11 = arr.begin(),  ar12;
		set<int>::iterator ar21 = arr2.begin(), ar22;

		while (ar11 != arr.end()) {
			ar12 = ar11;
			ar22 = ar21;
			ar12++;
			ar22++;
			while (ar12 != arr.end()) {
				total1 += S[*ar11][*ar12] + S[*ar12][*ar11];
				total2 += S[*ar21][*ar22] + S[*ar22][*ar21];
				ar12++;
				ar22++;
			}
			ar11++;
			ar21++;
		}
		diff = total1 - total2;
		diff = diff < 0 ? diff * -1 : diff;

		if (minDiff > diff) {
			minDiff = diff;
		}
	}
	else {
		for (int i = num + 1; i < size; i++) {
			rec(i, size, arr);
		}
	}
	arr.erase(num);
}

int main(void) {
	int n;
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	cin >> n;

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++)
			cin >> S[i][j];
	
	rec(0, n);

	cout << minDiff << '\n';
	return 0;
}