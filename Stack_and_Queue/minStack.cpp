//Design a stack that supports getMin() in O(1) time and O(1) extra space

#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    stack<int> st;
    int MinSf = 0;

    void push(int val)
    {
        if (st.size() == 0)
        {
            st.push(val);
            MinSf = val;
            return;
        }

        if (MinSf < val)
            st.push(val);
        else
        {
            st.push(2 * val - MinSf);
            MinSf = val;
        }
    }

    int pop()
    {

        if (st.size() == 0)
            return -1;

        if (st.top() < MinSf)
        {
            int j = st.top();
            st.pop();
            int actualValue = MinSf;

            int recoveredMinSf = 2 * MinSf - j;

            MinSf = recoveredMinSf;
            return actualValue;
        }
        else
        {
            int j = st.top();
            st.pop();
            return j;
        }
    }

    int top()
    {
        if (st.size() == 0)
            return -1;

        if (st.top() < MinSf)
            return MinSf;
        else
            return st.top();
    }

    int getMin()
    {
        if (st.size() == 0)
            return -1;
        return MinSf;
    }
};

int main()
{
    // MinStack s;
    // s.push(3);
    // s.push(5);
    // cout<<s.getMin();
    // s.push(2);
    // s.push(1);
    // // s.getMin();
    // // s.pop();
    // // s.getMin();
    // // s.pop();
    // // s.top();

    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.top() << endl;
    cout << minStack.getMin();

    return 0;
}