/* you are given positions of houses and heaters on a horizontal line,
 find out minimum radius of heaters so that all houses could be covered by those heaters.
 Eg:
    Input: [1,2,3,4],[1,4]
    Output: 1
Eg: 
    [1,2,3,4,5,6,7],[3,4]
    output : 3
*/
#include<bits/stdc++.h>
using namespace std;

    int binary_search(vector<int> arr , int ele)
    {   
        int s =0 ;
        int e = arr.size() - 1;
        while(s<=e)
        {   
            int mid = (s+e)/2;
            if(ele == arr[mid])
            {
                return mid;
            }
            if(arr[mid] > ele)
            {
                e = mid -1;
            }
            if(arr[mid] < ele)
            {
                s = mid +1;
            }
        }
        return s; //if element is not found then it will return either index 0 or arr.size()
    }
    int findRadius(vector<int> houses, vector<int> heaters) {
        
        sort(houses.begin() , houses.end());
        sort(heaters.begin() , heaters.end());
        
        int radius = INT_MIN;
        for(int i = 0 ; i < houses.size() ; i++)
        {
            int pos = binary_search(heaters , houses[i]);
           // cout<<pos<<" ";   
            if(pos < 0)
            {
                pos = 0;
            }
            if(pos == 0)
                {
                    radius = max(radius , heaters[pos] - houses[i]);
                }
            else if(pos < heaters.size())
                {
                    radius = max(radius , min ( heaters[pos] - houses[i] , houses[i] - heaters[pos-1]) );
                }
            else if( pos >= heaters.size())
                {
                    radius = max(radius , houses[i] - heaters[heaters.size() -1]);
                }
            }
        return radius;
    }
int  main()
{
    vector<int>houses  = {1,2,3,4,5,6,7};
    vector<int>heaters = {3,4};

    cout<<findRadius(houses , heaters);
    //cout<<binary_search(heaters , 7);
    return 0;
    }