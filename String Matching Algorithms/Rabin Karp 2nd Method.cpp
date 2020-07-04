//Rabin Karp -Second Method : Prefix Sum
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

    // Create prefix array
    int pref[n];
    for(int i=0;i<n;i++)
    {
        pref[i]=(text[i] -'a' + 1)*powr(p,i);
        pref[i]%=mod;
    }
    for(int i=1;i<n;i++)
    {
        pref[i]+=pref[i-1];
        pref[i]%=mod;
    }

    for(int i=0;i+m<=n;i++)
    {
        //subtring from s[l...r]
        //r=i+m-1 ,l=i 
        //-> hash=(pref[r] - pref[l-1])/p^l
        int new_hash=pref[i+m-1];
        if(i-1>=0) new_hash-=pref[i-1];
        new_hash+=mod;
        new_hash%=mod;

        if(new_hash == (p_hash * powr(p,i)%mod))
        {
            cout<<i<<" ";
        }
    }
    return 0;
}