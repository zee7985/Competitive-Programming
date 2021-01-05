#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n; cin >> n;
    // vector<vector<int>> graph(n);
    unordered_map<int,set<int>> graph;      // for duplicate input for eg- 0 1 ,0 1   two times as input
    for ( int i = 0; i <n; i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a].insert(b);
        graph[b].insert(a);
    }

   for(auto i : graph)
	{
		cout<<i.first<<"->";
		for(int  neigh: i.second) cout<<neigh<<" ";


    //         cout<<i<<"->";
    //         for(int j=0;j<graph[i].size();j++)
    //         {
    //             cout<<graph[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }

        vector<bool> visited(n, false);
         queue<int> q;
         q.push(0);
         visited[0] = true;

        while (!q.empty())
        {
            auto cur = q.front();
            q.pop();
            cout<<cur<<" ";
            for (auto ele : graph[cur])
            {
                if (!visited[ele])
                {
                    visited[ele] = true;
                    q.push(ele);
                   
                }
            }

        }
    return 0;
}
