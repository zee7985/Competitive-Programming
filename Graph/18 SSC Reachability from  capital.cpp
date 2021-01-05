//https://codeforces.com/contest/999/problem/E
E. Reachability from the Capital

There are n cities and m roads in Berland. Each road connects a pair of cities. The roads in Berland are one-way.

What is the minimum number of new roads that need to be built to make all the cities reachable from the capital?

New roads will also be one-way.

Input
The first line of input consists of three integers n, m and s (1≤n≤5000,0≤m≤5000,1≤s≤n) — the number of cities, the number of roads and the index of the capital. Cities are indexed from 1 to n.
The following m lines contain roads: road i is given as a pair of cities ui, vi (1≤ui,vi≤n, ui≠vi). For each pair of cities (u,v), there can be at most one road from u to v. Roads in opposite directions between a pair of cities are allowed (i.e. from u to v and from v to u).

Output
Print one integer — the minimum number of extra roads needed to make all the cities reachable from city s. If all the cities are already reachable from s, print 0.

Examples
input
9 9 1
1 2
1 3
2 3
1 5
5 6
6 1
1 8
9 8
7 1
output
3
input
5 4 5
1 2
2 3
3 4
4 1
output
1

#include<bits/stdc++.h>
using namespace std;

// unordered_map<int,vector<int>> graph,rev;
vector<int> graph[5001];
vector<bool>visited(5001,false);

void DFS2(int i)
{
    if(!visited[i])
    {
	    visited[i] = true;
	    for(int j: graph[i])
			DFS2(j);
    }
}


void DFS1(int i,stack<int>& mystack)
{
    if(!visited[i])
    {
        mystack.push(i);
	    visited[i]=true;
	    for(int j: graph[i])
			DFS2(j);
    }
}



void findSCCs(int s,int V)
{
	stack<int> mystack;
	
	DFS2(s);

	// reverse(V);

    for(int i=0;i<V;i++)
    {
        if(!visited[i])
            DFS1(i,mystack);
    }


	for(int i=0;i<V;++i)
		visited[i] = false;

    int count=0;
	while(!mystack.empty())
	{
		int curr = mystack.top();
		mystack.pop();
		if(visited[curr]==false)
		{
			DFS2(curr);
            count++;
		}
	}
    
    cout<<count;

}

int main()
{
	int n, m,s;
    cin >> n >> m>>s;
    s--;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--; y--;
        graph[x].push_back(y);

    }

	findSCCs(s,n);
	return 0;
}

//https://www.youtube.com/watch?v=d595jx6qNLU
