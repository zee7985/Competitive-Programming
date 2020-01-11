#include<bits/stdc++.h>
using namespace std;

string ans=" ";

void longestCommonSubstr(string str1,string str2,int i,int j,string curAns){
    if(curAns.length()>ans.length()){
        ans=curAns;
    }
    
    
    if(i==str1.length() || j==str2.length()){
        return ;
    }

    if(str1[i]==str2[j]){
        longestCommonSubstr(str1,str2,i+1,j+1,curAns + str1[i]);
    }
    else{
        longestCommonSubstr(str1,str2,i+1,j,"");
        longestCommonSubstr(str1,str2,i,j+1,"");
    }

}


int main(){

    longestCommonSubstr("abcdgh","acdghr",0,0,"");
    cout<<ans;
}