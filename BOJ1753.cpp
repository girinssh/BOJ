#include <iostream>
#include <vector>
#include <queue>
#include <map>
#define mkedge make_pair

using namespace std;

typedef pair<int, int> edge; // <distance, node>

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int vertices, edges;
	cin >> vertices >> edges;
	
	int start;
	cin >> start;

	start -= 1;

	vector<edge>* graph = new vector<edge>[vertices];
	vector<int> distance(vertices, 1000000000);
	map<edge, int> mm;

	for (int i = 0; i < edges; i ++ ) {
		int a, b, c;

		cin >> a >> b >> c;

		a -= 1;
		b -= 1;

		edge ee = mkedge(a, b);
		auto iter = mm.find(ee);
		if (iter == mm.end()) {
			mm.emplace(ee, c);
		}
		else {
			iter->second = min(iter->second, c);
		}
	}

	for (pair<edge, int> ee : mm) {
		graph[ee.first.first].emplace_back(ee.second, ee.first.second);
	}
	
	priority_queue<edge, vector<edge>, greater<edge>> q;

	q.emplace(0, start);
	distance[start] = 0;

	while (!q.empty()) {
		edge ee = q.top();
		q.pop();

		int nowD = ee.first;
		int nowN = ee.second;

		int l = graph[nowN].size();

		for (int i = 0; i < l; i++) {
			edge nowE = graph[nowN][i];
			if (distance[nowE.second] > nowD + nowE.first) {
				distance[nowE.second] = nowD + nowE.first;
				q.emplace(distance[nowE.second], nowE.second);
			}
		}
	}

	for (int d : distance) {
		if (d == 1000000000)
			cout << "INF" << "\n";
		else
			cout << d << "\n";
	}
	return 0;
}