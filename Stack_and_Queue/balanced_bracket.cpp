#include <bits/stdc++.h>
using namespace std;

bool balancedBracket(string str)
{
    stack<char> st;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str.at(i);
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (st.size() == 0)
                return false;

            if (ch == ')' && st.top() == '(')
            {
                st.top();
                st.pop();
            }
            else if (ch == ']' && st.top() == '[')
            {
                st.top();
                st.pop();
            }
            else if (ch == '}' && st.top() == '{')
            {
                st.top();
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }

    return st.size() == 0;
}

int main()
{   if(!balancedBracket("[{(a+b)) + (c+d)}]")){
    cout <<"Yes";
    }
    else{
        cout<<"No";
    }
}