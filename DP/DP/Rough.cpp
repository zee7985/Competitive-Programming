#include<bits/stdc++.h>
using namespace std;


// int step(int *a,int idx,int count,int sum){

//     if(idx==4){
//         return count;
//     }

//     int s=a[0];
//     sum+=a[idx];
//     if(sum<=s){
//         return step(a,idx+1,count,sum);
//     }
//     else{
//         return step(a,idx,count+1,0);
//     }
    
// }






// int main(){

//     int t;
//     cin>>t ;

//     while(t--){
//         int arr[4];
//         for(int i=0;i<4;i++){
//             cin>>arr[i];
//         }
    
//         cout<<step(arr,1,1,0)<<endl;

//     }
// }


// int main(){
//     int a,s,b,c,d,e;

//     cin>>a;
//     cin>>s;
//     cin>>b;
//     cin>>c;
//     cin>>d;
//     cin>>e;

//     if(s=a+b+c+d+e){
//         cout<<1;
//     }
//     else{
//         cout<<-1;
//     }
// }
// #include <iostream>
// #include<vector>
// using namespace std;

// vector<string> find1(int sr,int sc,int er,int ec)
// {
//     if(sr == er && sc == ec)
//     {
//         vector<string> ans;
//         ans.push_back(" ");
//         return ans;
//     }

//     vector<string> finalans ;
//     if(sr+1 <= er)
//     {
//         vector<string>hori = find1(sr+1,sc,er,ec);
//         for(string s:hori)
//         {
//             finalans.push_back("h"+s);
//         }//return finalans;

//     }

//     if(sc+1 <= ec)
//     {
//         vector<string>vert = find1(sr,sc+1,er,ec);
//         for(string s:vert)
//         {
//             finalans.push_back("v"+s);
//         }
//         //return finalans;
//     }

//     return finalans;

// }


// int main()
// {
  

//     vector<string> ans=find1(0,0,2,2);
//     for(string i : ans){
//             cout<<i;
//         }

//     return 0;
// }

// #include <iostream>
// #include<vector>
// using namespace std;

// vector<string>find1(int sr,int sc,int er,int ec)
// {
//     if(sr == er && sc == ec)
//     {
//         vector<string>ans;
//         ans.push_back(" ");
//         return ans;
//     }

//     vector<string> finalans ;
//     if(sr+1 <= er)
//     {
//         vector<string>hori = find1(sr+1,sc,er,ec);
//         for(string s:hori)
//         {
//             finalans.push_back("h"+s);
//         }//return finalans;

//     }

//     if(sc+1 <= ec)
//     {
//         vector<string>vert = find1(sr,sc+1,er,ec);
//         for(string s:vert)
//         {
//             finalans.push_back("v"+s);
//         }
//         //return finalans;
//     }

//     return finalans;

// }


// int main()
// {

//     vector<string> ans=find1(0,0,2,2);
//     for(string i : ans){
//         cout<<i;
//     }

//     return 0;
// }

