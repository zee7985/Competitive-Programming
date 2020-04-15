/*Given two arrays, write a function to compute their intersection.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]

Note:
Each element in the result must be unique.
The result can be in any order.*/

#include<bits/stdc++.h>
using namespace std;

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // insertion & finding takes O(1)
        unordered_set<int> s;
        
        for( auto no : nums1)
        {
            s.insert(no);
        }
        
        vector<int> ans;
        for(auto no : nums2)
        {
            if(s.find(no) != s.end()) //number found
            {
                ans.push_back(no);
                s.erase(no);
            }
        }
        return ans;        
    }

int main()
{
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};

    vector<int> ans = intersection(nums1 , nums2);
    for( auto s : ans)
    {
        cout<<s;
    }
}