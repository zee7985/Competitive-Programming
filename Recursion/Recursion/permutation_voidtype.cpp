#include<bits/stdc++.h>
using namespace std;

int permutation(string ques,string ans)
{
    if(ques.length() == 0)
    {
        cout<<ans;
        return 1;
    }

    int count = 0;
    for(int i = 0 ; i < ques.length() ; i++)
    {   
        char ch = ques[i];
        string rest = ques.substr(0,i) + ques.substr(i+1);
        count += permutation(rest, ans + ch);
    }
    return count;
}
int main()
{
    int count = permutation("abc"," ");
    cout<<endl;
    cout<<"No of permutation are : "<<count;
    return 0;
}