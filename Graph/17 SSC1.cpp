//https://www.spoj.com/problems/WEBISL/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> v;      // store the element of particular ssc together   
vector<int> components;     // contains the particular element exists in which strongly connected component

unordered_map<int,vector<int>> graph,rev;

void DFS1(int i,vector<bool>& visited,stack<int>& mystack)
{
	visited[i]=true;
	for(int j: graph[i])
		if(visited[j]==false)
			DFS1(j,visited,mystack);

	mystack.push(i);
}

void reverse(int V)
{
	for(int i=0;i<V;++i)
	{
		for(int j: graph[i])
			rev[j].push_back(i);
	}
}

void DFS2(int i,vector<bool>& visited,int count)
{
	// cout<<i<<" ";
    components[i]=count;
    v[count].push_back(i);
	visited[i] = true;
	for(int j: rev[i])
		if(!visited[j])
			DFS2(j,visited,count);
}

void findSCCs(int V)
{
	stack<int> mystack;

	vector<bool> visited(V,false);
	for(int i=0;i<V;++i)
		if(!visited[i])
			DFS1(i,visited,mystack);

	reverse(V);

	for(int i=0;i<V;++i)
		visited[i] = false;

    int count=0;
	while(!mystack.empty())
	{
		int curr = mystack.top();
		mystack.pop();
		if(visited[curr]==false)
		{
			DFS2(curr,visited,count);
            count++;
		}
	}
    
    for(int i=0;i<V;i++)
    {
        int ans=INT_MAX;
        int idx=components[i];
        for (auto ele : v[idx])
        {
            ans=min(ans,ele);
        }
        cout<<ans<<"\n";
    }

}

int main()
{
	int n, m;
    cin >> n >> m;

    v.resize(n+1);
    components.resize(n);


    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;

        graph[x].push_back(y);

    }

	findSCCs(n);
	return 0;
}


