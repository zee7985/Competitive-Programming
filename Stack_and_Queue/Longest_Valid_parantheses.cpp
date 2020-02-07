#include<bits/stdc++.h>
using namespace std;

int longestValidParentheses(string str){
    stack<int> st;

    st.push(-1);
    int max_=0;

    for(int i=0;i<str.length();i++){

        if(str[st.top()]=='(' && str[i]==')' && st.top()!=-1){
            st.top();
            st.pop();
            max_=max(i-st.top(),max_);
        }
        else{
            st.push(i);
        }
    }
    return max_;


}

int main(){
    string str=")(((((()())()()))()(()))(";
    cout<<longestValidParentheses(str)<<endl;
}