#include<bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[],int n) 
{  
    
    int Dp[n+1][W+1]; 
  
   for (int i = 0; i <= n; i++) 
   { 
       for (int w = 0; w <= W; w++) 
       { 
           if (i==0 || w==0) 
               Dp[i][w] = 0; 
           else if (wt[i-1] <= w) 
                Dp[i][w] = max(val[i-1] + Dp[i-1][w-wt[i-1]],  Dp[i-1][w]); 
           else
                 Dp[i][w] = Dp[i-1][w]; 
       } 
   } 
  
   return Dp[n][W]; 
} 
  
int main() 
{ 
    int val[] = {60, 100, 120}; 
    int wt[] = {10, 20, 30}; 
    int  W = 50; 
    int n = sizeof(val)/sizeof(val[0]);
    cout<<knapSack(W, wt, val,n)<<endl; 
    return 0; 
} 