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

	int n, m;
	cin >> n >> m;

	vector<edge> *v = new vector<edge>[n];

	vector<int> dist(n, 1000000000), path(n, -1);

	priority_queue<edge, vector<edge>, greater<edge>> q;

	map<edge, int> mm;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a -= 1;
		b -= 1;
		
		edge ee = mkedge(a, b);
		auto iter = mm.find(ee);
		if (iter == mm.end()) {
			mm.insert(make_pair(ee, c));
		}
		else {
			if (iter->second > c) {
				iter->second = c;
			}
		}
	}

	for (pair<edge, int> e : mm) {
		int c = e.second;
		v[e.first.first].emplace_back(c, e.first.second);
	}

	int start, end;
	cin >> start >> end;

	start -= 1;
	end -= 1;

	q.emplace(0, start);

	while (!q.empty()) {
		edge t = q.top();
		int nowD = t.first;
		int nowN = t.second;
		q.pop();

		for (edge e : v[nowN]) {
			int newD = nowD + e.first;
			if (dist[e.second] > newD) {
				dist[e.second] = newD;
				path[e.second] = nowN;
				q.emplace(newD, e.second);
			}
		}
	}

	cout << dist[end];
	return 0;
}