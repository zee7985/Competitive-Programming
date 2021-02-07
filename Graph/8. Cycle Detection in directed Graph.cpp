
//Cycle Detection in directed Graph
//  Depth First Traversal can be used to detect a cycle in a Graph. DFS for a connected graph produces a tree.
//   There is a cycle in a graph only if there is a back edge present in the graph. A back edge is an edge that is 
//   from a node to itself (self-loop) or one of its ancestors in the tree produced by DFS. In the following graph,
//    there are 3 back edges, marked with a cross sign. We can observe that these 3 back edges indicate 3 cycles present in the graph.

// For a disconnected graph, Get the DFS forest as output. To detect cycle, check for a cycle in individual trees by checking back edges.

// To detect a back edge, keep track of vertices currently in the recursion stack of function for DFS traversal.
//  If a vertex is reached that is already in the recursion stack, then there is a cycle in the tree. The edge that connects the current 
//  vertex to the vertex in the recursion stack is a back edge. Use recStack[] array to keep track of vertices in the recursion stack.
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph(60);


bool dfs_cycle(int u, vector<bool>&visited, vector<bool> recStack)
{
	visited[u] = true;
    recStack[u]=true;

	for (int v : graph[u])
		{
            //Two cases
            if (!visited[v])
            {
                if(dfs_cycle(v, visited, recStack)) return true;  // detected in next path
            } 
			if (recStack[v])               // i.e present in cur path so a back edge
            {
                return true;
            }

		}
    // Exit from stack path but will remain visited
    recStack[u]=false;
	return false;
}

bool cyclicDFS(int n)
{
	vector<bool> visited(n, false);
    vector<bool>recStack(n,false);

	// For all components in graph
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			if (dfs_cycle(i, visited,recStack))
				return true;
		}
	}
    return false;
}


int main()
{
	 int k,n; 
     cin>>k>> n;
    
    //unordered_map<int,set<int>> graph;      // for duplicate input for eg- 0 1 ,0 1   two times as input
    for ( int i = 0; i <k; i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }


    //  for(int i=0;i<graph.size();i++)
	// {
    //         cout<<i<<"->";
    //         for(int j=0;j<graph[i].size();j++)
    //         {
    //             cout<<graph[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }

	cout << cyclicDFS(n) << endl;


	return 0;
}
