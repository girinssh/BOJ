#include <iostream>
#include <string>

using namespace std;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	string p1, p2;
	int n;

	cin >> p1 >> p2 >> n;

	while (n--) {
		string cmd;
		cin >> cmd;

		if (cmd == "R") {
			if (p1[1] == p2[1] && p2[0] - p1[0] == 1) {
				if (p1[0] == 'H' - 1)
					continue;
				p2[0] += 1;
			}
			
			if (p1[0] != 'H')
				p1[0] += 1;
		}
		else if (cmd == "RT") {
			if (p1[1] == p2[1] - 1 && p2[0] - p1[0] == 1) {
				if (p1[0] == 'H' - 1 || p1[1] == '7')
					continue;
				p2[0] += 1;
				p2[1] += 1;
			}

			if (p1[0] != 'H' && p1[1] != '8') {
				p1[0] += 1;
				p1[1] += 1;
			}
		}
		else if (cmd == "RB") {
			if (p1[1] == p2[1] + 1 && p2[0] - p1[0] == 1) {
				if (p1[0] == 'H' - 1 || p1[1] == '2')
					continue;
				p2[0] += 1;
				p2[1] -= 1;
			}

			if (p1[0] != 'H' && p1[1] != '1') {
				p1[0] += 1;
				p1[1] -= 1;
			}
		}
		else if (cmd == "L") {
			if (p1[1] == p2[1] && p2[0] - p1[0] == -1) {
				if (p1[0] == 'A' + 1)
					continue;
				p2[0] -= 1;
			}

			if (p1[0] != 'A')
				p1[0] -= 1;
		}
		else if (cmd == "LT") {
			if (p1[1] == p2[1] - 1 && p2[0] - p1[0] == -1) {
				if (p1[0] == 'A' + 1 || p1[1] == '7')
					continue;
				p2[0] -= 1;
				p2[1] += 1;
			}

			if (p1[0] != 'A' && p1[1] != '8') {
				p1[0] -= 1;
				p1[1] += 1;
			}
		}
		else if (cmd == "LB") {
			if (p1[1] == p2[1] + 1 && p2[0] - p1[0] == -1) {
				if (p1[0] == 'A' + 1 || p1[1] == '2')
					continue;
				p2[0] -= 1;
				p2[1] -= 1;
			}

			if (p1[0] != 'A' && p1[1] != '1') {
				p1[0] -= 1;
				p1[1] -= 1;
			}
		}
		else if (cmd == "T") {
			if (p1[1] == p2[1] - 1 && p2[0] - p1[0] == 0) {
				if (p1[1] == '8' - 1)
					continue;
				p2[1] += 1;
			}

			if (p1[1] != '8')
				p1[1] += 1;
		}
		else if (cmd == "B") {
			if (p1[1] == p2[1] + 1 && p2[0] - p1[0] == 0) {
				if (p1[1] == '1' + 1)
					continue;
				p2[1] -= 1;
			}

			if (p1[1] != '1')
				p1[1] -= 1;
		}
	}

	cout << p1 << '\n' << p2;
	return 0;
}