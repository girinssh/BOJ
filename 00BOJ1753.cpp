#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <map>

#define INF 1000000

using namespace std;

typedef vector<list<pair<int, int>>> Graph;
typedef pair<int, int> Node;

/*

Graph(u, v, w) => u to v with weight w

*/

void bfs(int start, Graph& g, vector<int>& result) {
	vector<bool> check(g.size());

	stack<Node> stk;

	check[start] = true;

	int pos = start;

	do {
		list<Node>::iterator iter = g[pos].begin();

		while (iter != g[pos].end()) {
			if (!check[iter->first]) {
				check[iter->first] = true;
				stk.push(*iter);
			}
		}

		if (stk.size() == 0)
			break;

		pos = stk.top().first;
		stk.pop();
	} while (stk.size() >= 0);

	for (int i = 0; i < check.size(); i++) {
		if (check[i])
			result[i] = INF;
	}
}

void dji(int start, Graph& g, vector<int>& result) {
	map<int, int> minHeap; // <Weight, Vertex>



}

int main(void) {
	cin.tie(NULL);
	cin.sync_with_stdio(false);

	int V, E;
	cin >> V >> E;

	V -= 1;

	int from;
	cin >> from;

	Graph g(V);

	vector<int> result(E);

	for (int i = 0; i < E; i++) {
		int u, v, w;

		cin >> u >> v >> w;
		u -= 1;
		v -= 1;
		g[u].push_back(make_pair(v, w));
	}

	// 못 가는 곳 거르기
	bfs(V, g, result);

	result[V] = 0;

	// 다익

}