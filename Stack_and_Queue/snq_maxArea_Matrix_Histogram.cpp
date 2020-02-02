#include<bits/stdc++.h>
using namespace std;

int largestArea(vector<int>height){
    stack<int> st;

    st.push(-1);
    int i=0;
    int maxArea=0;

    while(i< height.size()){
        while(st.top()!=-1 && height[st.top()] >= height[i]){
            int j=st.top();
            st.pop();
            int ht=height[j];
            int area=ht*(i-st.top()-1);
            maxArea=max(maxArea,area);
            }
        st.push(i);
        i++;
    }
    while(st.top()!=-1){
        int j=st.top();
        st.pop();
        int ht=height[j];
        int area=ht*(i-st.top()-1);
        maxArea=max(maxArea,area);
    }

    return maxArea;
}

int maxAreaInMatrix(vector<vector<char>> &arr) {
    if (arr.size() == 0)
        return 0;

vector<int> ar(arr[0].size());
    int max_ = 0;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            ar[j] = arr[i][j] == '0' ? 0 : ar[j] + 1;
        }
        max_ = max(max_,largestArea(ar));
    }
    return max_;
}

int main(){

    vector<vector<char>> arr{{"1","0","1","0","0"},
                            {"1","0","1","1","1"},
                            {"1","1","1","1","1"},
                            {"1","0","0","1","0"}};
    
    cout<<maxAreaInMatrix(arr)<<endl;
    return 0;
}