#include <bits/stdc++.h>
using namespace std;

class Graph
{
	unordered_map <int, list<int>> adjList;

public:

	void addEdge(int u, int v, bool BiDir = true)
	{
		adjList[u].push_back(v);

		if (BiDir) adjList[v].push_back(u);
	}

	void printAdjList()
	{
		//Iterate over the map
		for (auto i : adjList)
		{
			cout << i.first << "->";

			for (auto entry : i.second) cout << entry << ", ";
			cout << endl;
		}
	}

	void dfs(int vertex, vector<bool> &visited) {
		visited[vertex] = true;

		for (int child : adjList[vertex]) {
			if (!visited[child])
				dfs(child, visited);
		}
	}

	int n_connected_components_dfs(int n)
	{
		vector<bool> visited(n + 1, false); // Can be map also
		int count = 0;

		for (int i = 0; i <= n; i++)
		{
			if (!visited[i])
			{
				dfs(i, visited);
				count++;
			}
		}

		return count;
	}

	void bfs(int vertex, vector<bool>&visited) {
		queue<int> q;
		q.push(vertex);
		visited[vertex] = true;

		while (!q.empty())
		{
			auto cur = q.front();
			q.pop();

			for (auto child : adjList[cur])
			{
				if (!visited[child])
				{
					visited[child] = true;
					q.push(child);
				}
			}
		}
	}

	int n_connected_components_bfs(int n)
	{
		vector<bool> visited(n + 1, false); // Can be map also
		int count = 0;

		for (int i = 0; i <= n; i++)
		{
			if (!visited[i])
			{
				bfs(i, visited);
				count++;
			}
		}

		return count;
	}


};

int main()
{
	Graph g;

	g.addEdge(0, 1);
	g.addEdge(0, 3);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(6, 7);


	g.printAdjList();
	cout << endl;

	cout << g.n_connected_components_dfs(7) << endl;
	cout << g.n_connected_components_bfs(7) << endl;

	return 0;
}