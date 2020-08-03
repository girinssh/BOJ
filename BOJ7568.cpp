#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int size;
	vector<pair<pair<int, int>, int>> data;

	cin.tie(NULL);
	cin.sync_with_stdio(false);

	cin >> size;
	data = vector<pair<pair<int, int>, int>>();

	for (int i = 0; i < size; i++) {
		int weight, height;

		cin >> weight >> height;
		data.push_back(make_pair(make_pair(weight, height), 1));
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (data[i].first.first < data[j].first.first && data[i].first.second < data[j].first.second) {
				data[i].second++;
			}
		}
		cout << data[i].second << " ";
	}
	return 0;
}