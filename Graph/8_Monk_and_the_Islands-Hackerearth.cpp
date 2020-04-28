//Ques.8 Monk and the Islands-Hackerearth(Simple Bfs)

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> graph[n + 1];

        // vector<vector<Edge *>> graph(n,vector<Edge*> );

        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> vis(n + 1, false);
        vector<int> ans(n + 1, 0);
        queue<int> que;

        que.push(1);
        vis[1] = true;

        ans[1] = 0;

        while (!que.empty())
        {
            int rpair = que.front();
            que.pop();

            for (int e : graph[rpair])
            {
                if (!vis[e])
                {

                    ans[e] = ans[rpair] + 1;
                    vis[e] = true;
                    que.push(e);
                }
            }
        }
        cout << ans[n];
        cout << endl;
    }
    return 0; // Writing output to STDOUT
}
