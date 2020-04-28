//Ques 3.Even Tree -Hackerrank

#include <bits/stdc++.h>
using namespace std;



vector<vector<int>> graph;
int ans;
vector<bool> visited(101);

void addedge(int u, int v)

{

    if (u < 0 || v < 0 || u > graph.size() || v > graph.size())
        return;

    graph[u].push_back(v);
    graph[v].push_back(u);
}

int dfs(int u){

    visited[u]=true;
    int node=0;

    for(auto i : graph[u]){

        if(!visited[i]){
            int no_of_node=dfs(i);     //Go thriugh u's non visited neighbour and find no of node under them
        

        if(no_of_node % 2==0){    // If a node gets in return an even number of vertices from one of it child then remove edge
	ans++;
        }
        else{
            node+=no_of_node;     //else if its odd ,increase no of node of u by next_node( if the number is odd add it to the number of vertices)
        }
        
    }
    }
    return vtx+1;     //if adjacent node has been processed then  return no of node under u+1  

}
     

int main() {
   int n,p;
   cin>>n>>p;
    for(int i = 0;i<n;i++) 
    {
        vector<int> v;
        graph.push_back(v);
    }

    for(int i=0;i<p;i++){
        int u,v;
        cin>>u>>v;
        addedge(u,v);
    }
    dfs(1);
    cout<<ans<<endl;
 
    return 0;
}
