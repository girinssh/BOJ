#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int n;
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;
	int size = 0;
	int i = 666;
	int value = i;
	while (size < n) {
		int div = 1;
		bool flag = false;
		for (; i / div - 666 >= 0; div *= 10) {
			if ((i / div - 666) % 1000 == 0) {
				flag = true;
				break;
			}
		}
		if (flag) {
			size++;
			value = i;
		}
		i++;
	}



	cout << value;
	return 0;
}