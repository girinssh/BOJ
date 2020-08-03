#include <deque>
#include <iostream>

using namespace std;

int main(void) {

	deque<int> dq;
	int t;
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> t;

	while (t--) {
		string cmd;
		cin >> cmd;

		if (cmd == "push_front") {
			int v;
			cin >> v;
			dq.push_front(v);
		}
		else if (cmd == "push_back") {
			int v;
			cin >> v;
			dq.push_back(v);
		}
		else if (cmd == "front") {
			if (dq.empty())
				cout << "-1\n";
			else
				cout << dq.front() << '\n';
		}
		else if (cmd == "back") {
			if (dq.empty())
				cout << "-1\n";
			else
				cout << dq.back() << '\n';
		}
		else if (cmd == "size") {
			cout << dq.size() << '\n';
		}
		else if (cmd == "empty") {
			cout << (dq.empty() ? 1 : 0) << '\n';
		}
		else if (cmd == "pop_back") {
			if (dq.empty())
				cout << "-1\n";
			else {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (cmd == "pop_front") {
			if (dq.empty())
				cout << "-1\n";
			else {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
	}

	return 0;
}