//The time complexity remains O(ELogV)) as there will be at most O(E) vertices in priority queue and O(Log E) is same as O(Log V)
#include <bits/stdc++.h>
using namespace std;


class Graph {
public:
    vector<vector<pair<int, int>>> g;
    int n;

    Graph(int size)
    {
        n = size;
        g.resize(size);
    }

    void addEdge(int u, int v, int wt)
    {
        g[u].push_back({v, wt});
    }

    void dijkstra(int src,vector<int> &dist)
    {
        
        vector<bool> visited(n, false);


        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  //weightsofar
        pq.push({0, src});

        while (!pq.empty())
        {
            auto cur = pq.top();
            int node = pq.top().second;
            pq.pop();

            // Instead of visited we can also use
            // if(dist[node.second] < cur.first) // means it has been relaxes earlier
            if (visited[node]) continue;

            visited[node] = true;

            for (auto v : g[node])
            {
                if (v.second + dist[node] < dist[v.first])
                {
                    dist[v.first] = v.second + dist[node];
                    pq.push({dist[v.first], v.first});
                }
            }
        }
    }


};

int main() {

    int m,n;
    cin >> m>>n;
    Graph g(n);

    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;

        g.addEdge(u, v, wt);
    }

    vector<int> dist(n, INT_MAX);
    g.dijkstra(0,dist);
    for(int i=0;i<n;i++)
    {
        cout<<"Distance from 0 to "<<i<<" is : "<<dist[i]<<"\n";
    }
    return 0;
}




// 8 7 
// 0 1 10
// 0 3 10
// 1 2 10
// 2 3 40
// 3 4 2
// 4 5 2
// 5 6 3
// 6 4 8