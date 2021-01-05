
#include <bits/stdc++.h>
using namespace std;


 vector<vector<int>> graph(60);
// If no cycle in a undirected graph then it can also be called as tree



// Check if we are visiting a u more than once
// NOTE- we have to make a check that if the u is parent of cur_u through which we reach here then we have to ignore that one
bool bfs_cycle(int u,int n,vector<bool> &visited)
{
	
	vector<int> parent(n , -1);	
	queue<int> q;
	q.push(u);
	visited[u] = true;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (auto v : graph[cur])
		{
			if (visited[v] && v != parent[cur])
			{
                return true;
			}
			else if (!visited[v])
			{
				visited[v] = true;
				parent[v] = cur;
				q.push(v);
            }
		}
	}
    return false;
}

bool isCyclicBFS( int n) 
{ 
    vector<bool> visited(n , false); 
  
    for (int i = 0; i < n; i++) 
        if (!visited[i] && bfs_cycle(i,n, visited)) 
            return true; 
    return false; 
}

bool dfs_cycle(int u, vector<bool>&visited, int parent)
{
	visited[u] = true;

	for (int v : graph[u])
		{
            if (!visited[v])
            {
                if(dfs_cycle(v, visited, u)) return true;
            } 
			else if ( v != parent) 
            {
                return true;
            }

		}

	return false;
}

bool cyclicDFS(int n)
{
	vector<bool> visited(n, false);

	// For all components in graph
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			if (dfs_cycle(i, visited, -1))
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
        graph[b].push_back(a);
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

	// both will give opposite ans as if it is tree then no cycle and if their is any cycle othen no tree
	cout << isCyclicBFS(n)<< endl;
	cout << cyclicDFS(n) << endl;


	return 0;
}