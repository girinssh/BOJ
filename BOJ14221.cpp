#include <iostream>
#include <vector>
#include <queue>

#define INT_MAX 2e9

#define make_edge make_pair

using namespace std;

// { to, weight }
typedef pair<int, int> edge;

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<edge>* graph = new vector<edge>[n];

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		a -= 1;
		b -= 1;

		graph[a].push_back(make_edge(b, c));
		graph[b].push_back(make_edge(a, c));
	}
	
	int p, q;
	cin >> p >> q;

	int* houses = new int[p] {0};
	int* convens = new int[q] {0};

	for (int i = 0; i < p; i++) {
		cin >> houses[i];
		houses[i] -= 1;
	}
	for (int i = 0; i < q; i++) {
		cin >> convens[i];
		convens[i] -= 1;
	}

	int minDist = INT_MAX;
	int minIdx = 0;

	for (int index = 0; index < p; index++) {
		int h = houses[index];
		vector<int> dist(n, INT_MAX);
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> next;

		dist[h] = 0;

		next.emplace(dist[h], h);

		// dijkstra
		for (int i = 0; i < n; i++) {
			pair<int, int> pivot = next.top();
			int idx = pivot.second;
			int nowDist = dist[idx];

			next.pop();

			for(int j = 0; j < graph[idx].size(); j++){
				int to = graph[idx][j].first;
				int weight = graph[idx][j].second;

				int d= min(dist[to], dist[idx] + weight);
				if (d != dist[to]) {
					dist[to] = d;
					next.emplace(d, to);
				}
			}

		}

		for (int i = 0; i < q; i++) {
			int idx = convens[i];
			if (minDist > dist[idx] || (minDist == dist[idx] && minIdx > h)) {
				minDist = dist[idx];
				minIdx = h;
			}
		}
	}
	cout << minIdx + 1;
	return 0;
}