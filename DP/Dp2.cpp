#include<bits/stdc++.h>
using namespace std;


int minStepTopDown(int src,int des,vector<int> arr){
    vector<int> dp(des+1,-1);
    if(src==des){
        dp[des]=0;
        return 0;
    }

    if(dp[src]!=-1) return dp[src];

    int curEle=arr[src];

    if(curEle==0){
        dp[src]=INT_MAX/2;
    }
    
    int ans=INT_MAX/2;
    for(int i=1;i<=curEle;i++){
        ans=min(ans,minStepTopDown(src+i,des,arr));
        dp[i]=ans;
    }
    return ans+1;
}


int minStepDp(int src,vector<int> &arr,vector<int> &dp){
    dp[arr.size()+1]={0};


    for(int i=arr.size()-2;i>=0;i--){
        int minAns=INT_MAX/2;
        for(int j=i+1;j<arr.size() && j <=i + arr[i];j++){
            minAns=min(minAns,dp[j]);
        }
        dp[i]=minAns+1;
    }
    return dp[src];

}


int singlePairWays(int n){
    vector<int> dp(n+1,0);
    dp[n+1]={0};
    dp[0]=1;
    dp[1]=1;

    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1] + dp[i-2]*(i-1);
    }

    return dp[n];
}

int divideN_ksets(int n,int k){
    vector<vector<int>> dp(n+1,vector<int>(k+1,0));

    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++){
             if(i<j || j==0){
                dp[i][j]=0;
                continue;
            }
            if(j==i || j==1){
                dp[i][j]=1;
                continue;
            }

            dp[i][j]=(dp[i-1][j])*j+ dp[i-1][j-1];
           

        }
    }
    return dp[n][k];

}

int main(){

    // vector<int> arr={1,3,0,4,0,0,2,1,1,0};
    // // vector<int> dp(arr.size()+1,0);
    // cout<<minStepTopDown(0,arr.size(),arr)<<endl;
    // cout<<minStepDp(0,arr,dp)<<endl;

   
     //cout<<singlePairWays(5);

     //         cout<<divideN_ksets(5,2)<<endl;
}