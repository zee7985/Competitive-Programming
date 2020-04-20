#include<bits/stdc++.h>
using namespace std;


void multiplication(vector<vector<int>> &a, vector<vector<int>> &b)
{

    int a0 = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    int a1 = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    int a2 = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    int a3 = a[1][0] * b[0][1] + a[1][1] * b[1][1];

    a[0][0] = a0;
    a[0][1] = a1;
    a[1][0] = a2;
    a[1][1] = a3;
}

void power(vector<vector<int>> &a, vector<vector<int>> &I, int pow)
{
    if (pow == 1)
        return;

    power(a, I, pow / 2);
    multiplication(a, a);

    if (pow % 2 != 0)
        multiplication(a, I);
}

int boardPath_memo(int start, int end, vector<int> &dp)
{
    if (start == end)
    {
        dp[start] = 1;
        return 1;
    }

    // if(dp[start]!=0) return dp[start];

    int count = 0;
    for (int dice = 1; dice <= 6; dice++)
    {
        if (start + dice <= end)
        {
            count += boardPath_memo(start + dice, end, dp);
        }
    }

    dp[start] = count;

    return count;
}

int mazePath(int sr, int sc, int er, int ec, vector<vector<int>> &dp)
{
    if (sr == er && sc == ec)
    {
        dp[sr][sc] = 1;
        return 1;
    }

    if (dp[sr][sc] != 0)
        return dp[sr][sc];

    if (dp.size() == dp[0].size() && dp[sc][sr] != 0)
        return dp[sc][sr];

    int count = 0;
    if (sr + 1 <= er)
    {
        count += mazePath(sr + 1, sc, er, ec, dp);
    }

    if (sc + 1 <= ec)
    {
        count += mazePath(sr, sc + 1, er, ec, dp);
    }

    if (sc + 1 <= ec && sr + 1 <= er)
    {
        count += mazePath(sr + 1, sc + 1, er, ec, dp);
    }

    dp[sr][sc] = count;
    if (dp.size() == dp[0].size())
        dp[sc][sr] = count;
    return count;
}

int mazePathDP(int sr, int sc, int er, int ec)
{

    vector<vector<int>> dp(er + 1, vector<int>(ec + 1));

    for (int sr = er; sr >= 0; sr--)
    {
        for (int sc = ec; sc >= 0; sc--)
        {

            if (sr == er && sc == ec)
            {
                dp[sr][sc] = 1;
                continue;
            }
            int count = 0;
            if (sr + 1 <= er)
                count += dp[sr + 1][sc];
            if (sc + 1 <= ec)
                count += dp[sr][sc + 1];
            if (sr + 1 <= er && sc + 1 <= ec)
                count += dp[sr + 1][sc + 1];

            dp[sr][sc] = count;
        }
    }

    return dp[0][0];
}

// int calls = 0;
int mazepath_multi(int sr,int sc,int er,int ec,vector<vector<int>>& dp){

    if(sr==er && sc==ec){
        dp[sr][sc]=1;
        return 1;
    }

    if(dp[sr][sc]!=0) return dp[sr][sc];

    int count =0;

    // calls++;
   
    for(int i=1;sc+i<=ec;i++){
        count+=mazepath_multi(sr,sc+i,er,ec,dp);
        }

    for(int i=1;sr+i<=er;i++){
       count+=mazepath_multi(sr+i,sc,er,ec,dp);
            
        }

    for(int i=1;sc+i<=ec && sr+i<=er;i++){
        count+=mazepath_multi(sr+i,sc+i,er,ec,dp);
            
    }
    dp[sr][sc]=count;

    if(dp[0].size()==dp.size()) dp[sc][sr] = count; // For Symmetry

    return dp[sr][sc];

}

int mazePathMultiDP(int sr, int sc, int er, int ec)
{

    vector<vector<int>> dp(er + 1, vector<int>(ec + 1));

    for (int sr = er; sr >= 0; sr--)
    {
        for (int sc = ec; sc >= 0; sc--)
        {

            if (sr == er && sc == ec)
            {
                dp[sr][sc] = 1;
                continue;
            }
            int count = 0;

            for (int jump = 1; sr + jump <= er; jump++)
                count += dp[sr + jump][sc];

            for (int jump = 1; sc + jump <= ec; jump++)
                count += dp[sr][sc + jump];

            for (int jump = 1; sr + jump <= er && sc + jump <= ec; jump++)
                count += dp[sr + 1][sc + 1];

            dp[sr][sc] = count;
        }
    }

    return dp[0][0];
}

int minCost(int sr,int sc,int er,int ec,vector<vector<int>> &cost,vector<vector<int>> &dp){

    if(sr==er && sc==ec){
        dp[sr][sc]=cost[sr][sc];
        return dp[sr][sc];
    }

    if(dp[sr][sc]!=-1) return dp[sr][sc];

    int a=INT_MAX;

    if(sr+1<=er){
         a=min(a,minCost(sr+1,sc,er,ec,cost,dp));
    }
    if(sc+1<=ec){
        a=min(a,minCost(sr,sc+1,er,ec,cost,dp));
    }
    if(sr+1<=er && sc+1<=ec){
        a=min(a,minCost(sr+1,sc+1,er,ec,cost,dp));
    }

    dp[sr][sc]=cost[sr][sc] +a;

    return dp[sr][sc];
}




int main(){

    // int n = 10;
    // vector<int> dp(n + 1, 0);
    // cout << boardPath_memo(0, n, dp) << endl;

    // for (int ele : dp)
    // {
    //     cout << ele << " ";
    // }

    // int n = 3;
    // int m = 3;
    // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // cout << mazePath(0, 0, n, m, dp) << endl;
    // cout << mazePathDP(0, 0, n, m) << endl;


    // int n=3;
    // int m=3;
    // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    // cout<<mazepath_multi(0,0,n-1,m-1,dp)<<endl;
    // // cout<<calls;

    // int n=3;
    // int m=3;
    // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    // vector<vector<int> > cost={{2,3,0,4},
    //                             {0,6,5,2},
    //                             {8,0,3,7},
    //                             {2,6,4,2}};

    // cout<<minCost(0,0,n,m,cost,dp)<<endl;

    
    


                                
}
 