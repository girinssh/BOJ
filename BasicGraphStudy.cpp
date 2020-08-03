#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<int>> Graph;
typedef vector<int> Node;

void AddEdge(Graph& G, int s, int d) {
	G[s].push_back(d);
}

// Depth First Search
void DFS(Graph& graph, vector<bool>& visited, int u) {
	visited[u] = true;
	cout << u << ' ';
	for (bool b : visited) {
		if (b)
			cout << 1;
		else
			cout << 0;
	}
	cout << '\n';

	for (int v : graph[u]) {
		if (!visited[v])
			DFS(graph, visited, v);
	}
}

void DFSTraversal(Graph& graph, vector<bool>& visited) {
	for (int i = 0; i < graph.size(); i++) {
		visited[i] = false;
	}
	for (int i = 0; i < graph.size(); i++) {
		if(!visited[i])
			DFS(graph, visited, i);
	}
}


// Breadth First Search
void BFS(Graph& graph, vector<bool>& visited, int u) {
	queue<int> Q;
	Q.push(u);

	while (Q.size() != 0) {
		u = Q.front();
		Q.pop();

		cout << u;
		visited[u] = true;

		for (int v : graph[u]) {
			if(!visited[v])
				Q.push(v);
		}
	}
}

void BFSTraversal(Graph& graph, vector<bool>& visited) {
	for (int i = 0; i < graph.size(); i++) {
		visited[i] = false;
	}

	for (int i = 0; i < graph.size(); i++) {
		if (!visited[i]) {
			BFS(graph, visited, i);
		}
	}
}


int main(void) {
	// directed Graph
	Graph graph;
	vector<bool> Visited;

	// Use Examples
	int size = 5;
	int arr[][2] = {
		{0, 2},
		{0, 4},
		{1, 2},
		{1, 3},
		{2, 1},
		{2, 4},
		{3, 4},
		{4, 2}
	};

	//int E, V;
	//
	//cin >> V >> E;
	//for (int i = 0; i < V; i++) {
	//	graph.push_back(Node());
	//	Visited.push_back(false);
	//}
	//for (int i = 0; i < E; i++) {
	//	int start, dest;
	//	cin >> start >> dest;
	//	AddEdge(graph, start, dest);
	//}
	//for (int i = 0; i < V; i++) {
	//	graph[i].push_back(i);
	//}

	for(int i = 0; i < size; i++){
		graph.push_back(Node());
		Visited.push_back(false);
	}
	for (int (*edge) : arr) {
		AddEdge(graph, edge[0], edge[1]);
	}
	for (int i = 0; i < size; i++) {
		graph[i].push_back(i);
	}
	
	cout << "It is DFS Traversal \n";
	DFSTraversal(graph, Visited);

	cout << "\nIt is BFS Traversal \n";
	BFSTraversal(graph, Visited);
	return 0;
}