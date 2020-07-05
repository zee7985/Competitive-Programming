#include <bits/stdc++.h>
using namespace std;

//O(n^3) -Finding longest prefix suffix for KMP 
vector<int> compute_lps_bruteforce(string s)
{
    int n=s.size();
    vector<int> lps(n,0);
    for(int i=0;i<n;i++)
    {
        for(int length=0;length<i;length++)
        {
            if(s.substr(0,length)== s.substr(i-length+1,length))
            {
                lps[i]=length;
            }
        }
    }
    return lps;
}

int main() {
    string s;
    cin>>s;

    vector<int> lps=compute_lps_bruteforce(s);
     for(auto x : s)
    {
        cout<<x<<" ";
    }
    cout<<"\n";
    for(auto x : lps)
    {
        cout<<x<<" ";
    }
}
