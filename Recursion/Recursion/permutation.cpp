#include<bits/stdc++.h>
using namespace std;

vector<string>permutation(string ques)
{
    if(ques.size() == 1)
    {
        vector<string> base;
        base.push_back(ques);
        return base;
    }

    char ch = ques[0];
    string rest = ques.substr(1);

    vector<string> finalans;
    vector<string> ans = permutation(rest);

    for(string s:ans)
    {
        for(int i=0; i <= s.size() ; i++)
        {   
            string a = s.substr(0,i) + ch + s.substr(i);
            finalans.push_back(a);
        }
    }
    return finalans;
}

int main()
{
 vector<string> ans = permutation("abc");
 for(string s: ans)
 {
     cout<<s<<" ";
 }

}