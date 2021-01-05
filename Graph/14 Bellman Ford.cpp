//  Bellman ford algorithm which is also a single source shortest path algorithm just like dijkstra algorithm
//   but the only difference is that, bellman ford algorithm can detect negative edge cycles which dijkstra cannot.
//   The time complexity of bellman ford is higher than dijkstra and so bellman ford should only be used if we have 
//   chances of getting a negative edge weight cycle.

// If the graph contain negative edge weight cycle,then it is not possible to find shortest path with any of the algorithm

#include<bits/stdc++.h>
using namespace std;

struct edge{
	int src,dst,wt;
};
int V,E;

void bellmanFord(vector<edge>& Edges)
{
    // parent to used to create the mst
	int parent[V];		//Stores Shortest Path Structure
	vector<int> dist(V,INT_MAX);	//Keeps shortest path values to each vertex from source
	

	parent[0] = -1;	//Start node has no parent
	dist[0] = 0;	//start node has value=0 to get picked 1st

	//Include (V-1) edges to cover all V-vertices
	bool updated;
	for(int i=0;i<V-1;++i)
	{
		updated = false;
		for(int j=0;j<E;++j)
		{
			int U = Edges[j].src;
			int V = Edges[j].dst;
			int wt = Edges[j].wt;
			if(dist[U]!=INT_MAX and dist[U]+wt<dist[V])
			{
				dist[V] = dist[U]+wt;
				parent[V] = U;
				updated = true;
			}
		}
		if(updated==false)
			break;
	}
	//Now check by relaxing once more if we have a negative edge cycle
	for(int j=0;j<E and updated==true;++j)
		{
			int U = Edges[j].src;
			int V = Edges[j].dst;
			int wt = Edges[j].wt;
			if(dist[U]!=INT_MAX and dist[U]+wt<dist[V])
			{
				cout<<"Graph has -VE edge cycle\n";
				return;
			}
		}
    int minCostPath=0;
	//Print Shortest Path Graph
	for(int i=1;i<V;++i)
    {
        minCostPath+=dist[i];
		cout<<"U->V: "<<parent[i]<<"->"<<i<<"  Cost to reach "<<parent[i]<<" from source 0 = "<<dist[i]<<"\n";
    }

     cout<<"MST with cost is "<<minCostPath;

}

int main()
{
	cin>>V>>E;	//Enter no of Vertices and Edges
	vector<edge> Edges(E);

	for(int i=0;i<E;++i)
	{
		cin>>Edges[i].src>>Edges[i].dst>>Edges[i].wt;
	}

	bellmanFord(Edges);	
	return 0;
}

//TIME COMPLEXITY: O(V.E)