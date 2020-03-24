/*Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Note:
The solution set must not contain duplicate triplets.
Example:
Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> nums) {
        if(nums.size() < 3)
        {
            return vector<vector<int> >{};            
        }
        sort(nums.begin() , nums.end());
        
        vector<vector<int> > ans ;
        for(int i = 0; i < nums.size() - 2 ; i++ )
        {
           if ( i>0 && nums[i] == nums[i-1]) continue;
            
            int l = i + 1;
            int r = nums.size() - 1;
           
            while(l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum > 0) r--;
                else if(sum < 0) l++;
                else //sum == 0
                {
                    ans.push_back(vector<int>{nums[i] , nums[l] , nums[r]});
                   // if(nums[l] == nums[l+1]) l++;
                   // if(nums[r] == nums[r--]) r--;
                    l++;
                    r--;
                }
             }
         }
        ans.erase(std::unique(ans.begin(), ans.end()), ans.end()); //remove unique set in ans
        return ans;
    }
int main()
{
    vector<int> ques = {-1,0,1,2,-1,-4};
    vector<vector<int> > ans = threeSum(ques);

    for(auto s : ans)
    {
        for(auto ele : s)
        {
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0 ;
}