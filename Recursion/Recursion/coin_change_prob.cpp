#include<bits/stdc++.h>
using namespace std;

int coin_change_permutation(vector<int> arr , int target , string ans)
{   //base case
    if ( target == 0)
    {
        cout<<ans;
        return 1;
    }

    int count = 0 ;
    for(int ele : arr)
    { 
        if(target - ele >= 0)
        {
        count += coin_change_permutation(arr , target - ele , ans + to_string(ele));
        }
    }
    return count ; 
} 
int coin_change_combination(vector<int> arr , int vidx , int target , string ans)
{
    //base
    if(target == 0)
    {
        cout<<ans;
        return 1;
    }
    int count = 0 ;
        for(int i = vidx ; i < arr.size() ; i++)
        {
            if (target - arr[i] >= 0)
            {
                count += coin_change_combination(arr , i , target - arr[i] , ans + to_string(arr[i]));
            }
        }
    return count;
}
int coin_change_combination_one_coin_use(vector<int> arr , int vidx , int target , string ans)
{
    //base
    if(target == 0)
    {
        cout<<ans;
        return 1;
    }
    int count = 0 ;
        for(int i = vidx ; i < arr.size() ; i++)
        {
            if (target - arr[i] >= 0)
            {
                count += coin_change_combination(arr , i + 1 , target - arr[i] , ans + to_string(arr[i]));
            }
        }
    return count;
}
int coin_change_permutation_one_coin_use(vector<int> arr , vector<bool>isdone, int vidx , int target , string ans)
{
    //base
    if(target == 0)
    {
        cout<<ans;
        return 1;
    }
    int count = 0 ;
        for(int i = 0 ; i < arr.size() ; i++)
        {
            if (target - arr[i] >= 0  && !isdone[i])
            {
                isdone[i] = true;
                count += coin_change_permutation_one_coin_use(arr , isdone , i + 1 , target - arr[i] , ans + to_string(arr[i]) );
                isdone[i] = false;
            }
        }
    return count; 
}

 int main()
 {
    vector<int> arr = {2,3,5,7};
    int target = 10;
    coin_change_permutation(arr,target," ");
    cout<<endl;
    coin_change_combination(arr , 0 ,10 , " ");
    cout<<endl;
    coin_change_combination_one_coin_use(arr , 0 , target , " ");
    cout<<endl;
    vector<bool>isdone(4,false);
    coin_change_permutation_one_coin_use(arr,isdone,0,10, " ");
    return 0; 
 }