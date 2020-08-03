#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

bool comp(pair<int, string> t1, pair<int, string> t2) {
	if (t1.first < t2.first)
		return true;
	else
		return false;
}

int main(void) {
	//string s = "hello\0 world";
	//pair<int, int> point(0, 0);
	//point = make_pair(1, 1);
	//cout << s << endl;
	//cout << s.back() << endl;
	//int t = 0;
	//int arr[1000];
	//cin >> t;
	//
	//for (int i = 0; i < t; i++)
	//	cin >> arr[i];
	//sort(arr, arr + t);
	//for (int i = 0; i < t; i++)
	//	cout << arr[i] << endl;

	//int t = 0;
	//list<pair<int, string>> xy;
	//cin >> t;
	//for (int i = 0; i < t; i++) {
	//	pair<int, string> temp(1, "0");
	//	cin >> temp.first >> temp.second;
	//	xy.push_back(temp);
	//}
	//xy.sort(comp);
	//for (int i = 0; i < t; i++) {
	//	cout << xy.front().first << " " << xy.front().second << "\n";
	//	xy.pop_front();
	//}
	
	list<string> noSee;
	list<string> noHear;

	int s, h;

	cin >> h >> s;

	for (int i = 0; i < h; i++) {
		string n;
		cin >> n;
		noHear.push_back(n);
	}
	for (int i = 0; i < s; i++) {
		string n;
		cin >> n;
		noSee.push_back(n);
	}

	


	return 0;
}


// 1. container
// 2. iterator
// 3. algorithm
// 4. functor