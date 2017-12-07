#include <iostream>
#include <climits>

using namespace std;

struct edge {
	int u;
	int v;
	int w;
};

struct graph {
	struct edge* arr;
};

int main() {
	int V, E, u, v, w;
	cin >> V;
	cin >> E;
	//cout << "V: " << V << "E: " << E << endl;
	struct graph* G = new graph;
	int cost[V];
	edge* edges = new edge[E];
	bool cycleFound = false;
	G->arr = edges;
	for (int i = 0; i < E; i++) {
		//cout << "loop: " << i << endl;
		cin >> u;
		cin >> v;
		cin >> w;
		G->arr[i].u = u;
		G->arr[i].v = v;
		G->arr[i].w = w;
	}

	for (int i = 0; i < V; i++) {
		//cout << "loop2: " << i << endl;
		if (i == 0)
			cost[i] = 0;
		else
			cost[i] = INT_MAX;
	}

	for (int i = 1; i <= V-1; i++) {
		//cout << "loop3: " << i << endl;
		for (int j = 0; j < E; j++) {
			//cout << "loop4: " << j << endl;
			if (cost[G->arr[j].u] != INT_MAX && (cost[G->arr[j].u] + G->arr[j].w < cost[G->arr[j].v])) {
				cost[G->arr[j].v] = cost[G->arr[j].u] + G->arr[j].w;
			}
		}
	}

	for (int i = 0; i < E; i++) {
		//cout << "loop5: " << i << endl;
		if (cost[G->arr[i].u] != INT_MAX && (cost[G->arr[i].u] + G->arr[i].w < cost[G->arr[i].v])) {
			cycleFound = true;
		}
	}

	if (cycleFound == true) {
		cout << "FALSE" << endl;
	}
	else if (cycleFound == false){
		cout << "TRUE" << endl;
		for (int i = 0; i < V; i++) {
			if (cost[i] == INT_MAX)
				cout << "INFINITY" << endl;
			else
				cout << cost[i] << endl;
		}
	}
}
