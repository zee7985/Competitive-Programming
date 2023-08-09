class Solution {
    public int longestValidParentheses(String s) {
        Stack<Integer> st=new Stack<>();
        st.push(-1);
        int max=0;
        for(int i=0;i<s.length();i++){
            
            char c = s.charAt(i);
            
            if(c='('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.isEmpty()){
                    st.push(i);
                }
                else{
                    int len = i - st.peek();
                    max = Math.max(max,len);
                }
            }
        }
        
        return max;
    }
}

class Solution {
    public int longestValidParentheses(String s) {
        int open = 0 , close = 0;
        int max = 0;
        
        // 0 -- n
        for(int i=0;i<s.length();i++){
            char c = s.charAt(i);
            if(c == '('){
                open++;
            }
            else{
                close++;
            }
            
            if(open == close){
                int len = open + close;
                max = Math.max(max,len);
            }
            else if(close > open ){
                open = close = 0;
            }
        }
        
        open = close = 0;
        // n -- 0
        for(int i= s.length()-1; i>=0 ;i--){
            char c = s.charAt(i);
            if(c == '('){
                open++;
            }
            else{
                close++;
            }
            
            if(open == close){
                int len = open + close;
                max = Math.max(max,len);
            }
            else if(open > close ){
                open = close = 0;
            }
        }
        
        return max;
    }
}


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
