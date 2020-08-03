#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	char arr[] = { 'U', 'C', 'P', 'C' };
	int index = 0;

	string v;

	while (!cin.eof()) {
		string s;
		cin >> s;
		v += s;
	}

	for (char c : v) {
		while (c == arr[index]) {
			index++;
			if (index == 4)
				break;
		}
		if (index == 4)
			break;
	}

	if (index == 4) {
		printf("I love UCPC");
	}
	else
		printf("I hate UCPC");

	return 0;
}