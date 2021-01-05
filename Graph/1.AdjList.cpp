#include <bits/stdc++.h>
using namespace std;

// Using hashmap implementation in bfs.cpp

class Graph
{
	unordered_map<string, list<pair<string, int>>> g;

public:

	void addEdge(string u, string v, bool BiDir, int wt)
	{
		g[u].push_back({v, wt});

		if (BiDir) g[v].push_back({u, wt});
	}

	void printAdjList()
	{
		for (auto node : g)
		{
			cout << node.first << "->";
			for (auto nbr : node.second)
			{
				cout << nbr.first << " " << nbr.second << ", ";
			}
			cout << endl;
		}
	}
};

int main()
{
	Graph g;
	g.addEdge("A", "B", true, 20);
	g.addEdge("B", "D", true, 40);
	g.addEdge("A", "C", true, 10);
	g.addEdge("C", "D", true, 40);
	g.addEdge("A", "D", false, 50);


	g.printAdjList();


	return 0;
}