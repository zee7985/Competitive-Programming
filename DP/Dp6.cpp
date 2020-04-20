#include<bits/stdc++.h>
using namespace std;

class envePair{
    public:
    int first,second;
};

bool compare(envePair e1,envePair e2) {
    
        return (e1.second < e2.second);
}


int maxEnvelopes(vector<envePair>& en) {
    if (en.size() == 0) return 0;
    sort(en.begin(), en.end(), compare);

     vector<int> dp(en.size(), 1);
    int max_ = 1;
    for (int i = 1; i < en.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (en[i].first > en[j].first && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                max_ = max(max_, dp[i]);
            }
        }
    }
    return max_;
}

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
    //Ques1->Russian Doll Problem Leetcode
    // int n;
    // cin>>n;
    // vector<envePair> en(n);
    // for(int i=0;i<n;i++){
    //     cin>>en[i].first>>en[i].second;
    // }
    // cout<<endl;
    // cout<<maxEnvelopes(en)<<endl;

    //ques2. Knapsack
    // int val[] = {60, 100, 120}; 
    // int wt[] = {10, 20, 30}; 
    // int  W = 50; 
    // int n = sizeof(val)/sizeof(val[0]);
    // cout<<knapSack(W, wt, val,n)<<endl; 
    return 0; 
} 