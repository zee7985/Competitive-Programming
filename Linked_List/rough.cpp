#include<iostream> 
using namespace std; 

int main() 
{ 

    int t;
    cin>>t;
    while(t--)
    {
	    string str1 ; 
	    string str2;
        string str3;
        cin>>str1>>str2>>str3;

	    bool ans = true;
        for(int i =0;i<str1.length();i++)
        {
            if( str1[i]==str3[i] || str2[i]==str3[i])
            continue;
        
        ans= false;
        }

        if(ans==true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
	return 0; 
} 
