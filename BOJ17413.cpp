#include <iostream>

using namespace std;

void printStr(string w) {
	while (!w.empty()) {
		printf("%c", w.back());
		w.pop_back();
	}
	return;
}

int main(void) {
	string word;

	int stk = 0;
	char c;
	do {
		c = getchar();

		if (stk != 0) {
			printf("%c", c);
			if (c == '>') {
				stk--;
			}
			else if (c == '<') {
				stk++;
			}
		}
		else {
			if (c == '\n') {
				printStr(word);
				word.clear();
			}
			else if (c == '<') {
				printStr(word);
				printf("%c", c);
				word.clear();
				stk++;
			}
			else if (c == ' ') {
				printStr(word);
				printf("%c", c);
				word.clear();
			}
			else {
				word.push_back(c);
			}
		}
	} while (c != '\n');
	return 0;
}