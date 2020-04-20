#include<bits/stdc++.h>
using namespace std;

vector<vector<bool>> isPali(string str){
    vector<vector<bool>>isPalindrome(str.length(),vector<bool>(str.length(),false));

    for(int gap=0;gap<str.length();gap++){
        for(int i=0,j=gap;j<str.length();i++,j++){
            if(gap==0){
                isPalindrome[i][j]=true;
            }
            else if(str[i]==str[j]){
                if(gap==1){
                    isPalindrome[i][j]=true;
                }
                else if(isPalindrome[i+1][j-1]) {
                    isPalindrome[i][j]=true;
                }
            
            }
        }
    }
    return isPalindrome;
}

int longestPaliSubstr_Length(string str){
    vector<vector<int>> dp(str.length(),vector<int>(str.length(),0));
    vector<vector<bool>>isPalindrome=isPali(str);

    
    for(int gap=0;gap<str.length();gap++){
        for(int i=0,j=gap;j<str.length();i++,j++){
            if(gap==0){
                dp[i][j]=1;
            }
            else if(gap==1 && str[i]==str[j]){
                dp[i][j]=2;
            }
            else if(isPalindrome[i+1][j-1] && str[i]==str[j]) {
                dp[i][j]=dp[i+1][j-1] +2;
            }
            else{
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
            
            }
        }
        return dp[0][str.length()-1];
}

int longestPaliSubstr_count(string str){
    vector<vector<bool>>isPalindrome(str.length(),vector<bool>(str.length(),false));
    int count=0;
    for(int gap=0;gap<str.length();gap++){
        for(int i=0,j=gap;j<str.length();i++,j++){
            if(gap==0){
                isPalindrome[i][j]=true;
                count++;
            }
            else if(str[i]==str[j]){
                if(gap==1){
                    isPalindrome[i][j]=true;
                    count++;
                }
                else if(isPalindrome[i+1][j-1]) {
                    isPalindrome[i][j]=true;
                    count++;
                }
            
            }
        }
    }
    return count;
}

string longestPaliSubstr_stringPrint(string str){
    vector<vector<int>> dp(str.length(),vector<int>(str.length(),0));
    vector<vector<bool>>isPalindrome=isPali(str);
    string s="";

    
    for(int gap=0;gap<str.length();gap++){
        for(int i=0,j=gap;j<str.length();i++,j++){
            if(gap==0){
                dp[i][j]=1;
            }
            else if(gap==1 && str[i]==str[j]){
                dp[i][j]=2;
                s+=str[i];
                
            }
            else if(isPalindrome[i+1][j-1] && str[i]==str[j]) {
                dp[i][j]=dp[i+1][j-1] +2;
                s+=str[i] + str[i-1] + str[i];
            }
            else{
                dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
            
            }
        }
        return s;
}


int LongestPalindrom_Subseq_length(string str)
{
    vector<vector<int>> dp(str.length(), vector<int>(str.length(), 0));

    for (int gap = 0; gap < str.length(); gap++)
    {
        for (int i = 0, j = gap; j < str.length(); j++, i++)
        {
            if (gap == 0)
                dp[i][j] = 1;
            else if (str[i] == str[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
    }
    return dp[0][str.length() - 1];
}


int LongestPalindrom_Subseq_count(string str)
{
    vector<vector<int>> dp(str.length(), vector<int>(str.length(), 0));

    for (int gap = 0; gap < str.length(); gap++)
    {
        for (int i = 0, j = gap; j < str.length(); j++, i++)
        {
            if (gap == 0)
                dp[i][j] = 1;
            else if (str[i] == str[j])
                dp[i][j] = dp[i + 1][j] + dp[i][j-1] +1;
            else
                dp[i][j] =dp[i + 1][j] + dp[i][j-1] -dp[i+1][j-1];
        }
    }
    return dp[0][str.length() - 1];
}
int main(){


    // cout<<longestPaliSubstr_Length("babad");
   // cout<<longestPaliSubstr_count("babad");
   cout<<longestPaliSubstr_stringPrint("");

//    cout<<LongestPalindrom_Subseq_length("babcda");
   // cout<<LongestPalindrom_Subseq_count("babcda");



    
}
