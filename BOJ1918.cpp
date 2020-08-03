#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main(void) {
	stack<char> operators;
	string midform, preform;

	cin >> midform;

	for (char c : midform) {
		if (isalpha(c)) {
			preform.push_back(c);
		}
		else {
			if (c == '(') {
				operators.push(c);
			}
			else if (c == ')') {
				while (operators.top() != '(') {
					preform.push_back(operators.top());
					operators.pop();
				}
				operators.pop();
			}
			else {
				if (c == '+' || c == '-') {
					if (!operators.empty()) {
						char ops = operators.top();
						while (ops == '*' || ops == '/' || ops == '-' || ops == '+') {
							preform.push_back(ops);
							operators.pop();
							if (operators.empty())
								break;
							ops = operators.top();
						}
					}
					operators.push(c);
				}
				else {
					if (!operators.empty()) {
						char ops = operators.top();
						while (ops == '*' || ops == '/') {
							preform.push_back(ops);
							operators.pop();
							if (operators.empty())
								break;
							ops = operators.top();
						}
					}
					operators.push(c);
				}
			}
		}
	}
	while (operators.size() > 0) {
		preform.push_back(operators.top());
		operators.pop();
	}
	cout << preform;

	return 0;
}