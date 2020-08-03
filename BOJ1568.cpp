#include <iostream>
#include <cmath>
using namespace std;

int main(void){
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int time = 0;

	int n;

	cin >> n;

	while (n > 0) {
		int temp = 0;
		int adder = 1;
		while (temp <= n) {
			temp += adder;
			time++;
			adder++;
		}
		adder -= 1;
		temp -= adder;
		time--;
		
		n -= temp;
	}

	cout << time << '\n';
	return 0;
}