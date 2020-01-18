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

int LIS_(vector<int> &arr)
{
    vector<int> list;
    list.push_back(arr[0]);
    int len = 1;
    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > list[len - 1])
        {
            list.push_back(arr[i]);
            len++;
        }
        else
        {
            int li = 0;
            int ri = len - 1;
            while (li < ri)
            {
                int mid = (li + ri) / 2;
                if (list[mid] < arr[i])
                    li = mid + 1;
                else
                    ri = mid;
            }
            list[ri] = arr[i];
        }
    }
    return len;
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

int main(){
{

    vector<int> arr = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    cout << LIS(arr) << endl;
    cout << LIS_(arr);
}