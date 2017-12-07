#include <iostream>
#include <climits>

using namespace std;

struct edge
{
	int v1;
	int v2;
	int wgt;
};

struct graph
{
	struct edge* edges;
};


void print(int cost[], bool cycle, int numverts)
{
	if (cycle == true)
	{
		cout << "FALSE" << endl;
	}
	else if (cycle == false)
	{
		cout << "TRUE" << endl;
		for (int i = 0; i < numverts; i++)
		{
			if (cost[i] == INT_MAX)
			{
				cout << "INFINITY" << endl;
			}
			else
			{
				cout << cost[i] << endl;
			}
		}
	}
}

bool BellmanFord(graph* G, int numverts, int numedges, int cost[])
{
	bool cycle = false;

	for (int i = 0; i < numverts; i++)
	{
		if (i == 0)
		{
			cost[i] = 0;
		}
		else
		{
			cost[i] = INT_MAX;
		}
	}

	for (int i = 1; i <= numverts-1; i++)
	{
		for (int j = 0; j < numedges; j++)
		{
			if (cost[G->edges[j].v1] != INT_MAX && (cost[G->edges[j].v1] + G->edges[j].wgt < cost[G->edges[j].v2]))
			{
				cost[G->edges[j].v2] = cost[G->edges[j].v1] + G->edges[j].wgt;
			}
		}
	}

	for (int i = 0; i < numedges; i++)
	{
		if (cost[G->edges[i].v1] != INT_MAX && (cost[G->edges[i].v1] + G->edges[i].wgt < cost[G->edges[i].v2]))
		{
			cycle = true;
		}
	}

	print(cost,cycle,numverts);

}

int main()
{
	int numverts;
	int numedges;

	cin >> numverts;
	cin >> numedges;

	int v1;
	int v2;
	int wgt;
	int cost[numverts];

	struct graph* G = new graph;
	edge* edges = new edge[numedges];
	G->edges = edges;

	for (int i = 0; i < numedges; i++)
	{
		cin >> v1;
		cin >> v2;
		cin >> wgt;
		G->edges[i].v1 = v1;
		G->edges[i].v2 = v2;
		G->edges[i].wgt = wgt;
	}

	BellmanFord(G, numverts, numedges, cost);

	return 0;
}
