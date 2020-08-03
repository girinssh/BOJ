#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int retMax(int a, int b) {
	return a > b ? a : b;
}
int retMin(int a, int b) {
	return a < b ? a : b;
}
void func(vector<map<int, set<int>>>& ladder, int xpos, int ypos) {
	int x = xpos;
	int y = ypos;

	bool isClear = false;

	//cout << "------------start" << ' ' << xpos << "------------\n";

	while (!isClear) {
		map<int, set<int>>::iterator iter1, iter2;

		if (x == 0) {
			iter1 = iter2 = ladder[x].upper_bound(y);
			if (iter1 == ladder[x].end()) {
				isClear = true;
			}
		}
		else if (x == ladder.size()) {
			iter1 = iter2 = ladder[x - 1].upper_bound(y);
			if (iter1 == ladder[x - 1].end()) {
				isClear = true;
			}
		}
		else {
			iter1 = ladder[x - 1].upper_bound(y);
			iter2 = ladder[x].upper_bound(y);

			if (iter1 == ladder[x - 1].end() && iter2 == ladder[x].end()) {
				isClear = true;
			}
		}

		if (!isClear) {
			//cout << "before" << x << ' ' << y << '\n';
			if (x == 0) {
				iter1->second.insert(xpos);
				x += 1;
				y = iter1->first;
			}
			else if (x == ladder.size()) {
				iter1->second.insert(xpos);
				x += -1;
				y = iter1->first;
			}
			else {
				if (iter1 == ladder[x - 1].end()) {
					iter2->second.insert(xpos);
					x += 1;
					y = iter2->first;
				}
				else if (iter2 == ladder[x].end()) {
					iter1->second.insert(xpos);
					x += -1;
					y = iter1->first;
				}
				else {
					if (iter1->first > iter2->first) {
						iter2->second.insert(xpos);
						x += 1;
						y = iter2->first;
					}
					else {
						iter1->second.insert(xpos);
						x += -1;
						y = iter1->first;
					}
				}
			}
			//cout << "after" << x << ' ' << y << "\n\n";

		}
	}
}

int main(void) {
	int n;
	int cnt = 0;

	int maxLadder = 0;

	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> n;

	vector<map<int, set<int>>> ladder(n-1);
	vector<vector<int>> ladders(n-1);

	for (int i = 0; i < n - 1; i++) {
		int val;
		do {
			cin >> val;
			if (val != 0) {
				cnt++;
				ladder[i][val];
				ladders[i].push_back(val);
				if (maxLadder < val)
					maxLadder = val;
			}
		} while (val != 0);
	}

	// main Algorithm
	bool isClear = true;

	map<set<int>, set<pair<int, int>>> checkMap;

	do {
		isClear = true;

		for (int x = 0; x < n; x++) {
			func(ladder, x, 0);
		}

		for (int i = 0; i < ladder.size(); i++) {
			for (pair<int, set<int>> p : ladder[i]) {
				checkMap[p.second].insert(make_pair(i, p.first));
				ladder[i][p.first].clear();
			}
		}

		for (auto check : checkMap) {
			//for (int v : check.first) {
			//	cout << v << ' ';
			//}
			//cout << ": " << check.second.size() << '\n';

			if (check.second.size() % 2 == 0) {
				isClear = false;
				for (pair<int, int> p : check.second) {
					//cout << p.first << ' ' << p.second << '\n';
					*find(ladders[p.first].begin(), ladders[p.first].end(), p.second) = 0;
					ladder[p.first].erase(p.second);
					cnt--;
				}
			}
			else if (check.second.size() > 2) {
				pair<int, int> b = { 0, 0 };
				for (pair<int, int> p : check.second) {
					if (b.first == p.first) {
						int MIN = b.second;
						int MAX = p.second;

						bool del = false;

						if (p.first == 0) {
							map<int, set<int>>::iterator iter = ladder[1].begin();

							while (iter->first < MIN) {
								iter++;
								if (iter == ladder[1].end())
									break;
							}

							if (iter == ladder[1].end()) {
								del = true;
							}
							else if(MAX < iter->first)
								del = true;

						}
						else if (p.first == ladder.size() - 1) {
							map<int, set<int>>::iterator iter = ladder[p.first -1].begin();

							while (iter->first < MIN) {
								iter++;
								if (iter == ladder[p.first - 1].end())
									break;
							}

							if (iter == ladder[p.first - 1].end()) {
								del = true;
							}
							else if (MAX < iter->first) {
								del = true;
							}
						}
						else {
							map<int, set<int>>::iterator iter1 = ladder[p.first - 1].begin();
							map<int, set<int>>::iterator iter2 = ladder[p.first + 1].begin();

							while (iter1->first < MIN) {
								iter1++;
								if (iter1 == ladder[p.first - 1].end())
									break;
							}							
							while (iter2->first < MIN) {
								iter2++;
								if (iter2 == ladder[p.first + 1].end())
									break;
							}

							if (iter1 == ladder[p.first - 1].end() && iter2 == ladder[p.first + 1].end())
								del = true;
							else if (MAX < iter1->first && MAX < iter2->first) {
								del = true;
							}
						}

						if (del) {
							*find(ladders[p.first].begin(), ladders[p.first].end(), p.second) = 0;
							*find(ladders[b.first].begin(), ladders[b.first].end(), b.second) = 0;
							ladder[p.first].erase(p.second);
							ladder[p.first].erase(b.second);
							cnt -= 2;
						}
					}
					b = p;
				}
			}
		}

		checkMap.clear();

	} while (!isClear);

	cout << cnt << '\n';
	for (int i = 0; i < ladders.size(); i++) {
		for (int j = 0; j < ladders[i].size(); j++) {
			if(ladders[i][j] != 0)
				cout << i + 1 << ' ' << j + 1 << '\n';
		}
	}
	return 0;
}