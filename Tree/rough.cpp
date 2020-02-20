#include <bits/stdc++.h>
using namespace std;

void prob4(long long int n,long long int p)
{
    

    vector<long long int> vect(n);

    for(int i = 0;i<n;i++){
        cin>>vect[i];
    }

    vector<int> find;

    for(int i = 0;i<n;i++)
    {
        if(vect[i]==1 || vect[i]==p) continue;

        if(vect[i] > p)
        {
            cout<<"YES ";
            for(int j = 0;j<n;j++)
            {
                if(j==i) cout<<"1"<<" ";
                else cout<<"0"<<" ";
            }
            return;
        }

        if(p%vect[i] !=0)
        {
            long long int z = p/vect[i];

            cout<<"YES ";
            for(int j = 0;j<n;j++)
            {
                if(j==i) cout<<z+1<<" ";
                else cout<<"0"<<" ";
            }
            return;

        }
            if(find.size())
            {
                for(int k = 0;k<find.size();k++)
                {
                    int rem = p-vect[i];
                    
                    if(rem%vect[find[k]]!=0)
                    {
                        cout<<"YES ";
                        for(int j = 0;j<n;j++)
                        {
                            if(j==find[k])
                                cout<<rem/vect[find[k]]+1<<" ";
                            else if(i==j) cout<<1<<" ";
                            else cout<<"0 ";
                        }
                        return ;
                    }
                }
                find.push_back(i);

            }

           if(find.size()==0){
                find.push_back(i);
            }
    }

    cout<<"NO";
}

int main() {
    int t; cin>>t;

    while(t--)
    {
        long long int n,p; 
        cin>>n>>p;
        prob4(n,p);
        cout<<endl;
    }


}