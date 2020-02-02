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

int main(){

    vector<int> arr{6,2,5,4,5,1,6};
    cout<<largestArea(arr)<<endl;
}