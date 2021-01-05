// Travelling Salesman Problem (TSP): Given a set of cities and distance between every pair of cities,
//  the problem is to find the shortest possible route that visits every city exactly once and returns to the starting point.
// Note the difference between Hamiltonian Cycle and TSP. The Hamiltoninan cycle problem is to find if
//  there exist a tour that visits every city exactly once. Here we know that Hamiltonian Tour exists 
//  (because the graph is complete) and in fact many such tours exist, the problem is to find a minimum weight Hamiltonian Cycle.
#include <iostream>
using namespace std;

#define INT_MAX 999999

int n=4;
int dp[16][4];  // dp[2^n][n]     mask value =2^n(0000 to 1111)  and pos will take n value denoting n cities

//Complexity  -DP - O(2^n.n)
//             recursion O(n-1!)

// Adj Matrix which defines the graph
int dist[10][10] = {
        {0,20,42,25},
        {20,0,30,34},
        {42,30,0,10},
        {25,34,10,0}
};

//If all cities have been visited
int VISITED_ALL = (1<<n) - 1;

int tsp(int mask,int pos){
    
    if(mask==VISITED_ALL){
        return dist[pos][0];
    }
    //Lookup 
    if(dp[mask][pos]!=-1){
        return dp[mask][pos];
    }
    
    int ans = INT_MAX;
    //Try to goto an unvisited city
    for(int city=0;city<n;city++){
        
        if((mask&(1<<city))==0){
            
            int newAns = dist[pos][city] + tsp( mask|(1<<city),city);
            ans = min(ans,newAns);
            
        }
        
        
    }
    
    return dp[mask][pos] = ans;
    
}

int main() {
    
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            dp[i][j] = -1;
        }
    }
    
    cout<<"Min weight hamiltonian path costs "<<tsp(1,0)<<endl;
    return 0;
}
