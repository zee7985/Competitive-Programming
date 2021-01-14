#include<bits/stdc++.h>
using  namespace std;

int LIS(vector<int> &arr)
{
    vector<int> dp(arr.size(), 1);
    int max_ = 1;
    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                max_ = max(max_, dp[i]);
            }
        }
    }
    return max_;
}

int LDS(vector<int> &arr)
{
    vector<int> dp(arr.size(), 1);
    int max_ = 1;
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] > arr[j] && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                max_ = max(max_, dp[i]);
            }
        }
    }
    return max_;
}

int LBS(vector<int> &arr){

    vector<int> lis_dp(arr.size(), 1);
     for (int i = 1; i < arr.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && lis_dp[j] + 1 > lis_dp[i])
            {
                lis_dp[i] = lis_dp[j] + 1;
            }
        }
    }
    vector<int> lds_dp(arr.size(), 1);
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] > arr[j] && lds_dp[j] + 1 > lds_dp[i])
            {
                lds_dp[i] = lds_dp[j] + 1;
            }
        }
    }
    int max_ = lis_dp[0] + lds_dp[0] - 1; 
    for (int i = 1; i < arr.size(); i++) 
        if (lis_dp[i] + lds_dp[i] - 1 > max_) 
        max_= lis_dp[i] + lds_dp[i] - 1; 
    return max_; 

}

//NlogN
//https://www.youtube.com/watch?v=qW1O1a40-No
int LIS_(vector<int> &arr)
{
    vector<int> list;
    list.push_back(arr[0]);
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > list.back())            //  If curr ele is greater than last element in list,Add element to the list
        {
            list.push_back(arr[i]);
        }
        else                                // Update the list by finding just greater or equal element in list and replace by curr ele
        {
            int idx=lower_bound(list.begin(),list.end())-list.begin();
            list[idx] = arr[i];
        }
    }
   
    return len;
}

const int MAX = 100; 

int goldMine(int arr[][MAX], int m, int n){
vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i = n-1;i>=0;i--)
    {
        for(int j = m-1;j>=0;j--)
        {
            dp[i][j]=arr[i][j] + max(dp[i-1][j+1],max(dp[i][j+1],dp[i+1][j+1]));
        }
    }
    int res = dp[0][0]; 
    for (int i=1; i<m; i++) 
        res = max(res, dp[i][0]); 
    return res; 

} 



int coinChangePermu(vector<int> &coins, int tar)
{
    vector<int> dp(tar + 1, 0);
    dp[0] = 1;

    for (int t = 1; t <= tar; t++)
    {
        for (int c = 0; c < coins.size(); c++)
        {
            if (t - coins[c] >= 0)
                dp[t] += dp[t - coins[c]];
        }
    }
    return dp[tar];
}

int coinChangeCombi(vector<int> &coins, int tar)
{
    vector<int> dp(tar + 1, 0);
    dp[0] = 1;

    for (int c = 0; c < coins.size(); c++)
    {
        for (int t = 1; t <= tar; t++)
        {
            if (t - coins[c] >= 0)
                dp[t] += dp[t - coins[c]];
        }
    }
    return dp[tar];
}

int main()
{

   vector<int> arr = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    //vector<int> arr = {2,-1,4,3,5,-1,3,2};
    // cout << LIS(arr) << endl;
    cout<<LBS(arr)<<endl;
    // cout << LIS_(arr);

    //    int gold[MAX][MAX]= { {1, 3, 1, 5}, 
    //     {2, 2, 4, 1}, 
    //     {5, 0, 2, 3}, 
    //     {0, 6, 1, 2} 
    // }; 
    // int m = 4, n = 4; 
    // cout << goldMine(gold, m, n);
}
