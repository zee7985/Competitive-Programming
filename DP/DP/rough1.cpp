#include <bits/stdc++.h>
using namespace std;

void deadline(long long int n,long long int d){
    if(d<=n){
        cout<<"YES";
        return;
    }

    else{
        for(long long int x=1;x<d-1;x++){
            if(x + ceil(d/(x+1))<=n){
                cout<<"YES";
                break;
            }
            else{
                cout<<"NO";
                break;
            }
        }
    }
}

int main() {
    int t;
    cin>>t;
    while(t--){
        long long int n,d;
        cin>>n>>d;
        deadline(n,d);
        cout<<endl;

    }
   return 0;
   
}
