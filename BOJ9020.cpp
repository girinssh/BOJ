#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


bool isPrime[10001] = { false, false };

int main(void) {
	set<int> primes;
	fill(isPrime + 2, isPrime + 10001, true);

	for (int i = 2; i <= 10000; i++) {
		if (isPrime[i]) {
			primes.insert(i);
			for (int j = i * 2; j <= 10000; j += i) {
				isPrime[j] = false;
			}
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int target;
		cin >> target;

		set<int>::iterator posValue = primes.lower_bound(target / 2);

		if (*posValue != target / 2)
			posValue--;

		while (1) {
			if (primes.find(target - *posValue) != primes.end()) {
				cout << *posValue << ' ' << target - *posValue << '\n';
				break;
			}
			posValue--;
		}
	}

	return 0;
}