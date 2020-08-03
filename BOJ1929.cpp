#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

bool isPrime[1000001];

int main(void) {
	int s, e;
	int pos = 2;
	list<int> primes;
	int total = 0;
	cin >> s >> e;
	list<int>::iterator iter;

	fill(isPrime + 2, isPrime + e+ 1, true);

	while (pos <= e) {
		int delpos = pos * 2;
		if (isPrime[pos])
			primes.push_back(pos);
		while (delpos <= e) {
			isPrime[delpos] = false;
			delpos += pos;
		}
		
		do {
			pos++;
		} while (!isPrime[pos]);
	}

	iter = lower_bound(primes.begin(), primes.end(), s);

	while (iter != primes.end()) {
		cout << *iter << '\n';
		iter++;
	}

	cout << primes.size() << '\n';

	return 0;
}