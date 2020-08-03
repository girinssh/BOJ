#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main(void) {
	//set<int> s = { 1, 2, 3, 4, 5, 6, 7 };
	//set<int>::iterator iter = s.begin();
	////cout << *(s.begin()) << endl;
	////for (int i : s)
	////	cout << i << endl;
	////cout << *(s.upper_bound(4)) << endl;
	////cout << *(s.lower_bound(4)) << endl;
	//map<int, int> m = map<int, int>();
	//m.insert(pair<int, int>(1, 2));
	//multimap<int, int> mm = multimap<int, int>();
	//mm.insert(pair<int, int>(3, 3));
	//mm.insert(pair<int, int>(3, 4));
	//mm.insert(pair<int, int>(3, 6));
	//mm.insert(pair<int, int>(3, 5));
	//multimap<int, int>::iterator miter = mm.begin();
	//advance(miter, 2);
	//cout << (*miter).second << endl;

	//int m = 0;
	//set<int> s = set<int>();
	//set <int> t = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	//const set <int> c = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	//cin.tie(NULL);
	//cin.sync_with_stdio(false);
	//cin >> m;
	//while (m--) {
	//	string cmd;
	//	cin >> cmd;
	//	if (cmd == "add") {
	//		int a = 0;
	//		cin >> a;
	//		s.insert(a);
	//		t.erase(a);
	//	}
	//	else if (cmd == "remove") {
	//		int a = 0;
	//		cin >> a;
	//		s.erase(a);
	//		t.insert(a);
	//	}
	//	else if (cmd == "check") {
	//		int a = 0;
	//		cin >> a;
	//		if (s.find(a) != s.end())
	//			cout << "1\n";
	//		else
	//			cout << "0\n";
	//	}
	//	else if (cmd == "toggle") {
	//		int a = 0;
	//		cin >> a;
	//		if (s.find(a) != s.end()) {
	//			s.erase(a);
	//			t.insert(a);
	//		}
	//		else {
	//			s.insert(a);
	//			t.erase(a);
	//		}
	//	}
	//	else if (cmd == "all") {
	//		for (int i : t) {
	//			s.insert(i);
	//		}
	//			t.clear();
	//	}
	//	else if (cmd == "empty") {
	//		s.clear();
	//		t = c;
	//	}
	//}

	int n, m, k;
	map<int, int> jbnu;

	cin.sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		int key, value;
		cin >> key >> value;
		jbnu[key] = value;
	}

	for (int i = 0; i < m; i++) {
		int cmd;
		int value = NULL;
		int key;
		cin >> cmd;

		switch (cmd) {
		case 1:
			cin >> key >> value;
			jbnu[key] = value;
			break;
		case 2: {
			int d[3] = { k, k, k };
			int* v = NULL;
			int fail = 0;
			int j = 0;
			int min = k;
			int notfound = 1;
			cin >> key >> value;
			if (jbnu.find(key) != jbnu.end())
				jbnu[key] = value;
			map<int, int>::iterator iter = jbnu.lower_bound(key);
		
			if (iter->first == key) {

			}

		}
			break;
		case 3: {
			cin >> key;
			int v;
			int d[3] = { k, k, k };
			int min = k;
			int fail = 0;
			int notfound = 1;
			int j = 0;
			map<int, int>::iterator iter = jbnu.lower_bound(key);
			if(iter != jbnu.end())
				iter++;
			if (iter == jbnu.end()) {
				j = 1;
				iter--;
			}
			for (; j < 3; j++) {
				d[j] = abs(key - iter->first);
				if (min > d[j] && d[j] <= k) {
					v = iter->second;
					fail = 0;
					notfound = 0;
					min = d[j];
				}
				if (min == d[j])
					fail = 1;
				iter--;
				if (iter == jbnu.end())
					break;
			}
			if (notfound)
				cout << -1 << '\n';
			else if (fail)
				cout << "?\n";
			else
				cout << v << "\n";
		}
			  break;
		}
	}

	for (pair<int, int> i : jbnu) {
		cout << i.first << "  " << i.second << endl;
	}

	return 0;

}