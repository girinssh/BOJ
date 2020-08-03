#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	char dir[] = { 'E', 'W', 'S', 'N' };
	int direction[][2] = {
		{1, 0},
		{-1, 0},
		{0, -1},
		{0, 1}
	};

	int units[32] = { 0 };


	for (int i = 0; i < 32; i++) {
		if (i == 0)
			units[i] = 1;
		else
			units[i] = units[i-1] * 2;
	}

	int t;
	cin >> t;

	for (int cnt = 1; cnt <= t; cnt++) {
		int x, y;
		bool isClear = true;
		string output = "";
		cin >> x >> y;
		cout << "Case #" << cnt << ": ";
		
		if (abs(x + y) % 2 == 0)
			isClear = false;

		else {

		}

		if (isClear)
			cout << output << '\n';
		else
			cout << "IMPOSSIBLE\n";
	}
	return 0;
}

// (0, 0) to (x, y)
// as few jump as possible
// exactly on the goal point
// i-th jump must move 2^(i-1) unit only one direction 
