// Shortest path in an unweighted graph
// Given an unweighted graph, a source, and a destination, we need to find the shortest path from source to destination in the graph in the most optimal way.
 
// Unweighted graph of 8 vertices 

// Input: source vertex = 0 and destination vertex is = 7.
// Output: Shortest path length is:2
//         Path is::
//         0 3 7

// Input: source vertex is = 2 and destination vertex is = 6.
// Output: Shortest path length is:5
//         Path is::
//         2 1 0 3 4 6


/*Time is O(v+E) as all nodes plus edge are traversed and space is O(v)
Use iterative approach and queue(fifo), from source node then direct neighbours then another layer
array is maintained for nodes visited so that they dont get pushed in queue again */

// Also search from shortest path from srs, in that instead of visited array we maintain a distance one

#include <bits/stdc++.h>
using namespace std;

void bfs(int src,int k,vector<vector<int>> graph)
{
    
    vector<bool> visited(k+1, false);
    vector<int> dist(k+1,INT_MAX);
    queue<int> q;
    q.push(src);
    visited[src] = true;
    dist[src]=0;

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        //cout<<cur<<" ";
        for (auto ele : graph[cur])
        {
            if (!visited[ele])
            {
                visited[ele] = true;
                dist[ele]=dist[cur]+1;
                q.push(ele);
            }
        }
    }
    for(int i=0;i<k;i++)
    {
        cout<<"Distance of "<<src<<" from "<<i<<" : "<<dist[i]<<"\n";
    }
}

int main() {
    
    int n,k; cin >>n>>k;
    vector<vector<int>> graph(k);
    for ( int i = 0; i <n; i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bfs(0,k,graph);

    // for(int i=0;i<graph.size();i++)
    //     {
    //         cout<<i<<"->";
    //         for(int j=0;j<graph[i].size();j++)
    //         {
    //             cout<<graph[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }

    return 0;
}
