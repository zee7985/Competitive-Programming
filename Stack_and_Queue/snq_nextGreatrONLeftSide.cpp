#include<bits/stdc++.h>
using namespace std;

void nextGreterOnLeftSide(vector<int> arr) {

    stack<int> st;
    for (int i = 0; i < arr.size(); i++) {

        while (st.size() != 0 && st.top() <= arr[i]) {
            st.pop();
        }

        if (st.size() == 0)
               cout<<arr[i] <<" -> " <<-1<<" "<<"\n";
            else
                cout<<arr[i] <<" -> " <<st.top()<<" "<<"\n";

            st.push(arr[i]);
    }
}

int main(){
    vector<int> arr = { 6, 2, 5, 4, 5, 1, 6 };
    nextGreterOnLeftSide(arr);

}