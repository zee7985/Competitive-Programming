//Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u v, 
//vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG.
//There can be more than one topological sorting for a graph
#include<bits/stdc++.h>
using namespace std;

class Graph {

	unordered_map<string, list<string> > adjList;

public:
	Graph() {

	}
	void addEdge(string u, string v, bool bidir = true) {

		adjList[u].push_back(v);

		// Directional in this case
		if (bidir) {
			adjList[v].push_back(u);
		}
	}

	void dfs(string node, unordered_map<string, bool> &visited, stack<string> &ordering)
	{
		visited[node] = true;

		for (auto nbr : adjList[node])
		{
			if (!visited[nbr])
			{
				dfs(nbr, visited, ordering);
			}
		}

		// while returning or coming back, add it
		ordering.push(node);
	}

	void topologicalSort_dfs()
	{
		unordered_map<string, bool> visited;
		stack <string> s;

		for (auto node : adjList)
		{
			if (!visited[node.first])
			{
				dfs(node.first, visited, s);
			}
		}

		while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
		cout << endl;
	}

	void topologicalSort_bfs() {
		queue<string> q;
		unordered_map<string, int> indegree;

		//Init the indegrees of all nodes
		for (auto i : adjList) {
			for (auto v : adjList[i.first]) {
				indegree[v]++;
			}
		}

		//Find out all the nodes with 0 indegree
		for (auto i : adjList) {
			auto node = i.first;
			if (indegree[node] == 0) {
				q.push(node);
			}
		}

		//Start with algorithm

		while (!q.empty()) {
			auto node = q.front();
			q.pop();
			cout << node << "-->";

			for (auto neighbour : adjList[node]) {
				indegree[neighbour]--;

				if (indegree[neighbour] == 0) {
					q.push(neighbour);
				}
			}
		}
		cout << endl;
	}
};

int main() {

	Graph g;
	g.addEdge("English", "Programming Logic", false);
	g.addEdge("Maths", "Programming Logic", false);
	g.addEdge("Programming Logic", "HTML", false);
	g.addEdge("Programming Logic", "Python", false);
	g.addEdge("Programming Logic", "Java", false);
	g.addEdge("Programming Logic", "JS", false);
	g.addEdge("Python", "Web Dev", false);
	g.addEdge("HTML", "CSS", false);
	g.addEdge("CSS", "JS", false);
	g.addEdge("JS", "Web Dev", false);
	g.addEdge("Java", "Web Dev", false);
	g.addEdge("Python", "Web Dev", false);

	g.topologicalSort_dfs();
	g.topologicalSort_bfs();


	return 0;
} 
