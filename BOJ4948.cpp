#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 123456

bool isPrime[2*MAX+2] = { false, false };

int main(void) {
	vector<int> primes;
	fill(isPrime + 2, isPrime + 2*MAX+2, true);
	
	for (int i = 2; i <= 2*MAX+1; i++) {
		if (isPrime[i]) {
			primes.push_back(i);
			for (int j = i * 2; j <= 2*MAX+1; j += i) {
				isPrime[j] = false;
			}
		}
	}
	
	int n = 0;
	do {
		cin >> n;

		if (n != 0) {
			int s = n + 1; 
			int e = 2 * n;
			int count = 0;
			vector<int>::iterator start = lower_bound(primes.begin(), primes.end(), s), end = lower_bound(primes.begin(), primes.end(), e);

			if (*end != e)
				end--;
			while (*start <= *end) {
				start++;
				count++;
			}
			cout << count << '\n';
		}
	} while (n != 0);

	return 0;
}