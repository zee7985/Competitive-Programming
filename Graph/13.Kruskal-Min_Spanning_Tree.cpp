#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Graph {
    // Number of vertices and edges
    int V, E;
    
    vector<Edge> edges;
    
    Graph(int v, int e) {
        V = v;
        E = e;
    }
};

// Data structure to represent a disjoint set
struct DisjointSet {
    int *parent, *rank;
    int n;

    DisjointSet(int n) {
        this->n = n;
        parent = new int[n+1];
        rank = new int[n+1];

        // Initially, all vertices are in different sets and have rank 0
        for (int i = 0; i <= n; i++) {
            rank[i] = 0;
            parent[i] = i;
        }
    }

    // Find the set of a vertex
    int find(int u) {
        // Path compression
        if (u != parent[u])   
            parent[u] = find(parent[u]);
        return parent[u];
    }

    // Union by rank
    void merge(int x, int y) {
        x = find(x);
        y = find(y);

        // Attach smaller rank tree under root of high rank tree
        if (rank[x] > rank[y])
            parent[y] = x;
        else
            parent[x] = y;

        if (rank[x] == rank[y])
            rank[y]++;
    }
};

bool compareEdges(Edge a, Edge b) {
    return a.weight < b.weight;
}

void KruskalMST(Graph &graph) {
    int V = graph.V;
    vector<Edge> result(V - 1);  // MST will have V-1 edges

    // Sort all edges in increasing order of their weight
    sort(graph.edges.begin(), graph.edges.end(), compareEdges);

    // Create disjoint sets for each vertex
    DisjointSet ds(V);

    // Index variable, used for result[]
    int e = 0;

    for (int i = 0; i < graph.E; i++) {
        // Take the smallest edge and check if it forms a cycle
        int u = graph.edges[i].src;
        int v = graph.edges[i].dest;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        // If including this edge does not cause cycle, include it in result
        if (set_u != set_v) {
            result[e++] = graph.edges[i];
            ds.merge(set_u, set_v);
        }
    }

    // Print the MST
    cout << "Edges of MST:" << endl;
    for (int i = 0; i < V - 1; i++) {
        cout << result[i].src << " -- " << result[i].dest << " == " << result[i].weight << endl;
    }
}

int main() {
    int V = 4; 
    int E = 5;  
    Graph graph(V, E);

    graph.edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    KruskalMST(graph);

    return 0;
}
