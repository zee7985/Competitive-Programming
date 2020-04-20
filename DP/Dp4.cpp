#include<bits/stdc++.h>
using namespace std;

string ans=" ";
// For maxLength just make curAns,global ans -  of type int with init 0 

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

int longCommSubstr_DP(string s1,string s2)
{
    int max_ans = 0;
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int i = 0;i<=n;i++)
    {
        for(int j = 0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j] = 0;
                continue;
            }
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
                max_ans = max(max_ans,dp[i][j]);
            }
            else dp[i][j] = 0;
        }
    }
    // Getting the string
    string Long_Substr = "";    
    vector<vector<string>> dp2(n+1,vector<string>(m+1,""));
    for(int i = 0;i<=n;i++)
    {
        for(int j = 0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                continue;
            }
            if(s1[i-1]==s2[j-1])
            {
                dp2[i][j] = dp2[i-1][j-1] + s1[i-1];
                if(dp2[i][j].length() > Long_Substr.length())
                {
                    Long_Substr = dp2[i][j];
                }
                
            }
        }
    }
    cout<<Long_Substr<<" ";
    return max_ans;
}
// ========================================================================================================
// for MaxLen base case return 0 , if (same) return 1 + (i+1,j+1) else return max((i+1,j),(i,j+1))
string longCommSubseq(string s1,string s2,int i,int j)
{
    if(i==s1.length() || j==s2.length())
    {
        return "";
    }
    if(s1[i]==s2[j])
    {
        return s1[i] + longCommSubseq(s1,s2,i+1,j+1);
    }
    string ans1 = longCommSubseq(s1,s2,i+1,j);
    string ans2 = longCommSubseq(s1,s2,i,j + 1);
    if(ans2.length() > ans1.length()) ans1 = ans2;
    return ans1;
    
}
int longCommSubseq_DP(string s1,string s2)
{
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int i = 0;i<=n;i++)
    {
        for(int j = 0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j] = 0;
                continue;
            }
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int i = m, j = n; 
    string lcs = "";
    while (i > 0 && j > 0) 
   { 
      // If current character in X[] and Y are same, then 
      // current character is part of LCS 
      if (s1[i-1] == s2[j-1]) 
      { 
            lcs = s1[i-1] + lcs; // Put current character in result 
            i--; j--;      // reduce values of i, j and index 
      } 
  
      // If not same, then find the larger of two and 
      // go in the direction of larger value 
      else if (dp[i-1][j] > dp[i][j-1]) 
            i--; 
      else
            j--; 
   } 
    cout<<lcs<<" ";
    return dp[n][m];
}
// ===================================================================================================
int Ways(string s,string t,int i,int j)
{
    if(j==t.length()) return 1;
    if(i==s.length()) return 0;
    int count = 0;
    if(s[i] == t[j])
    {
        count += Ways(s,t,i+1,j+1); // Might be one of the occurance
        count += Ways(s,t,i+1,j); // Might be another occurance in rem string
    }
    else count = Ways(s,t,i+1,j); // Look for other occurances
    return count;
}
int Ways_DP(string s,string t)
{
    int n = s.length();
    int m = t.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i = n;i>=0;i--)
    {
        for(int j = m;j>=0;j--)
        {
            if(i==n){
                dp[i][j] = 0; // No string can be suseq of empty string s
                if(j==m) dp[i][j] = 1;
                continue;
            }
            
            if(j==m){
                dp[i][j] = 1; //Empty string t is subseq 
                continue;
            }
            if(s[i] == t[j])
            {
                dp[i][j] += dp[i+1][j+1] + dp[i+1][j];
            }
            else dp[i][j] = dp[i+1][j];
        }
    }
    for(auto v : dp){
        for(int ele : v) cout << ele<<" ";
        cout<<endl;
    }
    return dp[0][0];
}


//=======================================================================
/* Ques.4 --> min Cost to make two strings same using operations - delete,update,insert */

//Recursive  
int minCostInDeRecu(string str1, string str2, int i, int j) 
{ 
    // If first string is empty
    // insert all characters of second string into first 
    if (i==str1.length()) 
        return str2.length()-j; 
  
    // If second string is empty
    // remove all characters of first string 
    if (j==str2.length()) 
        return str1.length()-i; 
  
    //  strings are same    
    if (str1[i] == str2[j]) 
        return minCostInDeRecu(str1, str2, i+1, j+1); 
 
    return 1 + min(minCostInDeRecu(str1, str2,i+1,j), 
                  min(minCostInDeRecu(str1, str2,i,j+1), 
                   minCostInDeRecu(str1, str2,i+1,j+1)  
                   )); 
} 

//DP

  
// ============================================================================================
int main(){
    /* Ques.1 --> Longest Common Substring */
    //longestCommonSubstr("abcdgh","acdghr",0,0,"");
    //cout<<ans;
    // cout<<longCommSubstr_DP("abcded","abcged");
    /* Ques.2 --> Longest Common Subsequence */
    // cout<<longCommSubseq("abccd","abd",0,0); // Using Recursion
    // cout<<longCommSubseq_DP("abcded","abcged");
    /* Ques.3 --> no of ways of occurances of string t in string s */
    // cout<<Ways("geeksforgeeks","gks",0,0);
    // cout<<Ways_DP("geeksforgeeksgk","gks"); 
    /* Ques.4 --> min Cost to make two strings same using operations - delete,update,insert */
    cout <<minCostInDeRecu("hor","ro",0,0);
    
}