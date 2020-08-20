#include <bits/stdc++.h>
using namespace std;


//0(n^3)
 int dp[1501][1501];
 int dp1[1501][1501];
 
//  bool isPalindrome(string s, int i, int j){
//     if(i>=j) return true;
//         while(i<j){
//             if(s[i]!=s[j]) return false;
//             i++;
//             j--;
//         }
//         return true;
// }

 bool isPalindrome(string s, int i, int j){
    if(i>=j) return dp1[i][j]=1;
    
    if(s[i]==s[j]) return dp1[i][j]=isPalindrome(s,i+1,j-1);
    return dp1[i][j]=0;
}
    
 int solve(string s, int i, int j){
        if(i>=j )
            return 0;
       
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(isPalindrome(s, i, j)){
            dp[i][j] = 0;
            return 0;
        }
        int min = INT_MAX, left, right;
		// loop through all the possible k(position )
        for(int k=i; k<=j-1; k++){
            
            if(dp[i][k]!=-1) left = dp[i][k];
            else {
                dp[i][k] = solve(s, i, k);
                left = dp[i][k];
            }
            
            if(dp[k+1][j]!=-1) right = dp[k+1][j];
            else {
                dp[k+1][j] = solve(s, k+1, j);
                right = dp[k+1][j];   
            }
            
            
            if(min>1+left+right)
                min = 1+left+right;
        }
        
        dp[i][j] = min;
        return min;
        
    }
    


int minCut(string A) {
    int n =A.length();
    memset(dp,-1,sizeof(dp));
    memset(dp1,0,sizeof(dp));
    return solve(A, 0, n-1);
}

int main() {
    string s;
    cin>>s;
    cout<<minCut(s);
}
