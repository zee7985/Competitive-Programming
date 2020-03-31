#include<bits/stdc++.h>
using namespace std;

int find_unique(vector<int>&arr , int k)
{
    vector<int>bits(32,0);

    for( int ele : arr)
    {
        for(int i=0 ; i<32; i++)
        {   int mask =0;
            mask = (1<<i);
            
            if( (ele & mask) != 0)
            {
                bits[i]++;
            }
        }
    }
    int ans = 0;
    for(int i = 0 ; i < 32 ;i++)
    {
        if( (bits[i] % k) != 0)
        {
            ans |= (1<<i);
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {2,3,2,3,4};
    int k = 2;

    cout<<find_unique(arr,k);
    return 0;
}