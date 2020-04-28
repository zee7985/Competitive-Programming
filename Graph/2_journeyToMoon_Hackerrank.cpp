//Ques 2.Journey to the moon-Hackerrank

#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int v = 0;
   // int w = 0;

    Edge(int val)
    {
        this->v = val;
       // this->w = wt;
    }

    Edge()
    {
    }
};

vector<vector<Edge *>> graph;

void addedge(int u, int v)

{

    if (u < 0 || v < 0 || u > graph.size() || v >= graph.size())
        return;

    graph[u].push_back(new Edge(v));
    graph[v].push_back(new Edge(u));
}


vector<int> Connected()
{
    int cntConnected = 0;
    vector<bool> isVisited(graph.size(), false);
    vector<int> v;
    for (int i = 0; i < graph.size(); i++)
    {
        
        queue<int> q;
        if (isVisited[i])
            continue;

        cntConnected++;
       // cout << "Connected Component " << cntConnected << "  :  ";

        q.push(i);
        int count=0;
        while (!q.empty())
        {   
            int cur = q.front();
            q.pop();
            if (!isVisited[cur])
                count++;
            isVisited[cur] = true;
            for (Edge *c : graph[cur])
            {
                if (!isVisited[c->v])
                {
                    q.push(c->v);
                }
            }
            
        }
        //cout << endl;
        v.push_back(count);
    }

    return v;
}

int main() {
   int n,p;
   cin>>n>>p;
    for(int i = 0;i<n;i++) 
    {
        vector<Edge*> v;
        graph.push_back(v);
    }

    for(int i=0;i<p;i++){
        int u,v;
        cin>>u>>v;
        addedge(u,v);
    }

    vector<int>v=Connected();
    int sum=0;
    long long int result=0;
    for(int i=0;i<v.size();i++){
        result+=sum*v[i];           //A*B + A*C + A*D + B*C + B*D + C*D = A*B + (A+B)*C + (A+B+C)*D
        sum+=v[i];
    }
    cout<<result;
    return 0;
}
