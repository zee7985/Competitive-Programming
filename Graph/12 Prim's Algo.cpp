//Using priority Queue


//https://www.hackerrank.com/challenges/primsmstsub/copy-from/157311155?isFullScreen=false
#include <bits/stdc++.h>
using namespace std;
int dist;


int main()
{
      int n,m;
        cin>>n>>m;

        vector<vector<pair<int,int>>> graph(n);
        for(int i = 0;i<m;i++)
        {
            int u,v,wt;
            cin>>u>>v>>wt;
            u--;v--;

            graph[u].push_back({v,wt});
            graph[v].push_back({u,wt});
        }

        int src; cin>>src;
        src--;

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;  // based on weights { weight ,node}

        vector<bool> visited(n,false);
        dist = 0;
        pq.push({0,src});
        //visited[0]=true;

        while(!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
            
            if (visited[cur.second])
                continue;
            
            dist+=cur.first;
            visited[cur.second] = true;
            
            for(auto child : graph[cur.second])
            {
                if(!visited[child.first]){
                    //visited[child.first]=true;
                    // dist+=child.second;
                    pq.push({child.second,child.first});
                }
            }
               
        }
    cout<<dist;
    return 0;
}

