#include <bits/stdc++.h>
using namespace std;



int main() {
    int t;
    cin>>t;
    while(t--){
        string a,b,c;
        cin>>a>>b>>c;
        bool ans=true;
        for(int i=0;i< a.length();i++){
            if(a[i]==c[i] || b[i]==c[i]){
                ans=true;
            }
            else{
                ans=false;
            }
        }
        if(ans==true){
            cout<<"Yes";
        }
        else{
            cout<<"No";
        }
        cout<<endl;

    }
    return 0;
}
