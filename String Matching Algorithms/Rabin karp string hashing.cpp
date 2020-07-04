#include <bits/stdc++.h>
#define int long long int 
using namespace std;

const int mod=1000000007;
const int p=31;  //prime no.

//return (a^b)%mod
int powr(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b & 1ll)
        {
            res*=a;
            res%=mod;
        }
        b/=2;
        a*=a;
        a%=mod;
    }
    return res;
}
//Left shift string (a/p)%mod = a*(p^-1)  and p^-1=p^(mod-2)%mod -fermat little theorem
int inv(int a)
{
    return powr(a,mod-2);
}

int poly_hash_string(string s)
{
    int  p_power=1;
    int hash=0;
    for(int i=0;i<s.size();i++)
    {
        hash+=(p_power*(s[i]- 'a' + 1));
        p_power*=p;
        p_power%=mod;
        hash%=mod;
    }
    return hash;
}

int32_t main() {
    
    string text="abaacadsfreaaca";
    string pat="aaca";
    int n=text.size();
    int m=pat.size();
    

    int p_hash=poly_hash_string(pat);
       
    int text_hash=poly_hash_string(text.substr(0,m));
    

    if(text_hash==p_hash)
    {
        cout<<0<<" ";
    }

    for(int i=m;i<n;i++)
    {
        int new_hash=text_hash;
        
        //1.step -remove Ist character from window
        new_hash=(new_hash - (text[i-m] -'a' + 1) + mod)% mod; //if we substract something from mod value then we need to add mod

        //Step 2
        new_hash *=inv(p);  //   a/p=a*p^-1  
        new_hash%=mod;

        //Step 3
        new_hash=new_hash + (text[i] - 'a' + 1)*powr(p,m-1);
        new_hash%=mod;

        
        if(new_hash==p_hash)
        {
            cout<<i - m + 1<<" ";
        }

        text_hash=new_hash;
        
    }
    return 0;
}