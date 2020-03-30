#include<bits/stdc++.h>
using namespace std;

int equiset(vector<int> arr, int vidx , int set1 , int set2 , string ans1 , string ans2)
{
    if(vidx == arr.size() - 1)
    {
        if(set1 == set2)
        {
            cout<<ans1 <<"-"<<ans2;
            cout<<endl;
            return 1;
        }
    return 0;
    }     
    
    int count = 0;
    count += equiset(arr , vidx + 1 , set1 + arr[vidx] , set2 , ans1 + to_string(arr[vidx]) , ans2);
    count += equiset(arr , vidx + 1 , set1 , set2 + arr[vidx] , ans1 , ans2 + to_string(arr[vidx]));
    count += equiset(arr, vidx + 1 , set1 , set2 , ans1 ,ans2);
    return 0;
}
int main()
{
    vector<int> arr = {10,20,30,40,50,60,70,80};

    equiset(arr , 1, 10 ,0 , "10" , " ");
    return 0;  
}