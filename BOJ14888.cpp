#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int minimum = 1e9;
int maximum = -(1e9);

void rec(vector<int>& number, vector<int> ops, vector<int> opss, int left) {
	if (left == 0) {
		int total = number[0];

		for (int i = 1; i < number.size(); i++) {
			switch (opss[i - 1]) {
			case 0:
				total += number[i];
				break;
			case 1:
				total -= number[i];
				break;
			case 2:
				total *= number[i];
				break;
			case 3:
				total /= number[i];
				break;
			}
		}
		if (total < minimum) {
			minimum = total;
		}
		if (total > maximum) {
			maximum = total;
		}
	}
	else {
		left--;
		vector<int>::iterator iter = ops.begin();

		while (iter != ops.end()) {
			int t = *iter;
			while (t == -1) {
				iter++;
				if (iter == ops.end())
					break;
				t = *iter;
			}
			if (iter == ops.end())
				break;
			opss.push_back(t);
			*iter = -1;
			rec(number, ops, opss, left);
			*iter = t;
			opss.pop_back();
			iter++;
		}
	}
}

int main(void) {
	int n;
	vector<int> number;
	vector<int> ops;
	vector<int> opss;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		number.push_back(temp);
	}

	for (int i = 0; i < 4; i++) {
		int temp;
		cin >> temp;
		for (int j = 0; j < temp; j++) {
			ops.push_back(i);
		}
	}
	rec(number, ops, opss, n - 1);

	cout << maximum << '\n' << minimum;
	return 0;
}