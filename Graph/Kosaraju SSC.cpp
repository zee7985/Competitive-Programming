//  Kosaraju algorithm is used to find all the strongly connected components in a graph.
//  We can even use this algorithm to find if the given graph is strongly connected or not.
// .This is a 3 step process.
//     -The first step is to traverse the graph using DFS and then push the nodes in stack.
//     - The second step is  to find transpose of the graph, that is, reverse all the edges in the graph.
//     -The third step is to pop nodes one by one from stack and make DFS calls to find the nodes in a strongly connected component.

#include<bits/stdc++.h>
using namespace std;
#define V 8

unordered_map<int,vector<int>> adj,rev;

void DFS1(int i,vector<bool>& visited,stack<int>& mystack)
{
	visited[i]=true;
	for(int j: adj[i])
		if(visited[j]==false)
			DFS1(j,visited,mystack);

	mystack.push(i);
}

void reverse()
{
	for(int i=0;i<V;++i)
	{
		for(int j: adj[i])
			rev[j].push_back(i);
	}
}

void DFS2(int i,vector<bool>& visited)
{
	cout<<i<<" ";
	visited[i] = true;
	for(int j: rev[i])
		if(!visited[j])
			DFS2(j,visited);
}

void findSCCs()
{
	stack<int> mystack;

	vector<bool> visited(V,false);
	for(int i=0;i<V;++i)
		if(!visited[i])
			DFS1(i,visited,mystack);

	reverse();

	for(int i=0;i<V;++i)
		visited[i] = false;

	cout<<"Strongly Connected Components are:\n";
    int count=0;
	while(!mystack.empty())
	{
		int curr = mystack.top();
		mystack.pop();
		if(visited[curr]==false)
		{
			DFS2(curr,visited);
            count++;
			cout<<"\n";
		}
	}
    cout<<"Total No. of SSC : "<<count;
}

int main()
{
	adj[0].push_back(1);
	adj[1].push_back(2);
	adj[2].push_back(0);
	adj[2].push_back(3);
	adj[3].push_back(4);
	adj[4].push_back(5);
	adj[4].push_back(7);
	adj[5].push_back(6);
	adj[6].push_back(4);
	adj[6].push_back(7);

	findSCCs();
	return 0;
}

//TIME COMPLEXITY: O(V+E)