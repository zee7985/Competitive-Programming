#include<bits/stdc++.h>

using namespace std;


void subseq(string ques,string ans){
    if(ques.length()==0){
        cout<<ans<<" ";
        return;
    }

    char ch=ques[0];
    string rest=ques.substr(1);

    subseq(rest,ans+ch);
    subseq(rest,ans);

}

void removeHi(string ques,string ans){
    if(ques.length()==0){
        cout<<ans<<" ";
        return;
    }


    if(ques.length()>1 && ques.substr(0,2)=="hi"){
        removeHi(ques.substr(2),ans);
    }
    else{
         char ch=ques[0];
         removeHi(ques.substr(1),ans+ch);
    }

}

void removeDuplicate(string ques,string ans){
    if(ques.length()==0){
        cout<<ans<<" ";
        return;
    }

    if(ques[0]==ans[ans.length()-1]){
        removeDuplicate(ques.substr(1),ans);

    }
    else{
        removeDuplicate(ques.substr(1),ans +ques[0]);
    }
}

void stringCompression(string ques,string ans,int count){
     
    if(ques.length()==0){
        cout<<ans<<" ";
        return;
    }
    
    char ch=ques[0];
    string rest=ques.substr(1);
    if(rest.length()!=0){
        if(ch==rest[0]){
            stringCompression(rest,ans,count+1);
        }
        else{
            if(count>1){
            stringCompression(rest,ans + ch + to_string(count),1);
            }
            else{
                stringCompression(rest,ans + ch,1);
            }
        }
    }
    else{
         if(count>1){
            stringCompression(rest,ans + ch + to_string(count),1);
            }
            else{
                stringCompression(rest,ans + ch,1);
            }

    }
}
    

void mazePath(int sr,int sc,int er,int ec,string ans)
    {
        if(sr==er && sc==ec)
        {
          cout<<ans<<" ";
          return;
        }

        if(sc+1<=ec){
            mazePath(sr,sc+1,er,ec,ans+"H");

        }

        if(sr+1<=er){
            mazePath(sr+1,sc,er,ec,ans+ "V");
        }

    }

int boardPathDice(int src,int dest,string ans){
    if(src==dest){
        cout<<ans<<" ";
        return 1;
    }

    if(src>dest){
        return 0;
    }
    int count=0;

    for(int i=1;i<=6;i++){
        int j=src+i;
        count+=boardPathDice(j,dest,ans + to_string(i));
      
    }
    return count;
}
    

// int coinTargetSum(int arr[],int src,int target,string ans){
//     if(src==target){
//         cout<<ans;
//         return 1;
//     }
//     if(src>target){
//         return 0;
//     }
    
    
//     int count=0;
//     for(int i=1;i<=4;i++){
        
//         count+=coinTargetSum(arr,src +arr[i],target,ans + to_string(arr[i]));
      
//     }
//     return count;
// }

int coinChangePermute01(vector<int> arr,int vidx ,int target,string ans){
    if(target==0){
        cout<<ans<<endl;
        return 1;
    }
   
    
    
    int count=0;
    for(int ele:arr){
        if(target-ele>=0)
        {
            count+=coinChangePermute01(arr,vidx,target-ele,ans + to_string(ele) + " ");
        }
    }    
    return count;
}
    
int coinChangeCombina01(vector<int> arr,int vidx ,int target,string ans){
    if(target==0){
        cout<<ans<<endl;
        return 1;
    }
   
    
    
    int count=0;
    for(int i=vidx;i<arr.size();i++){
        if(target-arr[i]>=0)
        {
            count+=coinChangeCombina01(arr,i,target-arr[i],ans + to_string(arr[i]) + " ");
        }
    }    
    return count;
}

int coinChangeCombina02(vector<int> arr,int vidx ,int target,string ans){ 
        
    if(target==0){
        cout<<ans<<endl;
        return 1;
    }
   
    
    
    int count=0;
    for(int i=vidx;i<arr.size();i++){
        if(target-arr[i]>=0)
        {
            count+=coinChangeCombina02(arr,i+1,target-arr[i],ans + to_string(arr[i]) + " ");
        }
    }    
    return count;
}



int placeNqueenCombi(int n,int vidx,int queen,string ans){

    if(vidx==n || queen<=0){
        if(queen==0){
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count=0;
    for(int i=vidx;i<n;i++){
        if(n-i>=queen)
            count+=placeNqueenCombi(n,i+1,queen-1,ans+ to_string(i+1)+ "q");
        }
    
    return count;

}

int placeNqueenPermut(int n,int queen,vector<bool> visited,string ans){

    if(queen==0){
            cout<<ans<<endl;
            return 1;
        }

    int count=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            visited[i]=true;
            count+=placeNqueenPermut(n,queen-1,visited,ans+ to_string(i+1)+ "q");
            visited[i]=false;
        }
    }
    
    return count;

}


int NqueenCombi_sub(int n,int queen,int qloc,int qpsf,string ans){

    if(qpsf==queen || qloc>=n){
        if(qpsf==queen){
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count=0;
    count+=NqueenCombi_sub(n,queen,qloc+1,qpsf+1,ans + "b"+ to_string(qloc+1) + "q"+ to_string(qpsf)+" ");
    count+=NqueenCombi_sub(n,queen,qloc+1,qpsf,ans);
    return count;

}


// int NqueenPermut2D(int sr,int sc,int er,int ec,int queen,vector<bool> visited,string ans)
// {
//         if(sr==er && sc==ec  || queen==0)
//         {
//             cout<<ans;
//             return 1;
//         }

//         int count=0;
//         visited[sr][sc]=true;
//         if(queen!=0){
//         if(sr-1>=0 && !visited[sr-1][sc]){
//             NqueenPermut2D(sr-1,sc,er,ec,queen-1,visited,ans +to_string(sr-1)+ " "+to_string(sc)+ "q");
//             }
        
//         if(sc+1<=ec && !visited[sr][sc+1]){
//             NqueenPermut2D(sr-1,sc,er,ec,queen-1,visited,ans +"R"+ "q");
//            }
        

//         if(sr+1<=er  && !visited[sr+1][sc]){
//             NqueenPermut2D(sr-1,sc,er,ec,queen-1,visited,ans +"D"+ "q");
    
//         }

//         if(sc-1>=0 && !visited[sr][sc-1]){
//            NqueenPermut2D(sr-1,sc,er,ec,queen-1,visited,ans +"L"+ "q");
//         }
//     }   

//         visited[sr][sc]=false;

       
//     return ans;

// }

// int placeNqueenPermut2D(int sr,int sc,int er,int sc,int n,int vidx,int queen,vector<bool> visited,string ans){

//     if(queen==0){
//             cout<<ans<<endl;
//             return 1;
//         }

//     int count=0;
//     for(int i=sr;i<er;i++){
//         for(int j=sc;i<ec;j++)
//         if(!visited[i][j]){
//             visited[i][j]=true;
//             count+=placeNqueenPermut(i,j,sr,sc,i+1,queen-1,visited,ans+ to_string(i+1)+"-" +to_string(j+1)+ "q");
//             visited[i][j]=false;
//         }
//     }
    
//     return count;

// }
//==================================================================//

string a="send";                            //Global
string b="more";
string c="money";
vector<int> maping(26,-1);
vector<bool> numUsed(10,false);


int strToNum(string str){
    int res=0;
    for(int i=0;i<str.length();i++){
        int num=maping[str[i]-'a'];
        res=res*10+num;
    }
    return res;

}


int crypto(string str,int idx)
{
    if(idx==str.length()){
        int strNum1=strToNum(a);
        int strNum2=strToNum(b);
        int strNum3=strToNum(c);
        if(strNum1 + strNum2==strNum3){
            cout<<strNum1<<"+"<<strNum2<<"="<<strNum3<<endl;
            return 1;

        }
        return 0;
    }
    char ch=str[idx];
    int count=0;
    for(int i=0;i<10;i++){
        if(!numUsed[i]){
            numUsed[i]=true;
            maping[ch-'a']=i;

            count+=crypto(str,idx+1);

            numUsed[i]=false;
            maping[ch-'a']=-1;
            
        }

    }
    return count;
}


// ===========================================================================


string dict[]={"i","like","man","go","mango","and","sam","samsung"};
bool checkIsWordPresent(string word){
    for(string s:dict){
        if(s.compare(word)==0){
            return true;
        }
            
    }return false;
}


int wordBreak(string word,int vidx,string ans){
    if(word.length()==vidx){
         cout<<ans<<endl;
         return 1;
    }


    string temp="";
    int count=0;
    for(int i =vidx;i<word.length();i++){
        temp+=word[i];
        if(checkIsWordPresent(temp)){
            count+=wordBreak(word,i+1,ans+temp+" ");
        }
    }
    return count;

}


// void sudokuBitwise(vector<vector<int>> board,int i,int j,int num){

// }








int main(){ 

    // subseq("abc","");
    // removeHi("ihihiiiihiiihhii","");
    // removeDuplicate("aaabbbbccc","");
     //stringCompression("aaabbbbccc","",1);
    // mazePath(0,0,2,2,"");
  // cout<<boardPathDice(0,10,"");
  //vector<int>arr={2,3,5,7};
  //cout<<coinChangePermute(arr,0,10,"");
//   coinChangeCombina01(arr,0,10,"");
   // coinChangeCombina02(arr,0,10,"");
//    cout<<placeNqueenCombi(5,0,3,"");
//     vector<bool> visited(6,false);
// cout<<placeNqueenPermut(5,3,visited,"");
// cout<<NqueenCombi_sub(5,3,0,0,"");
//NqueenPermut2D(0,0,3,3,3,visited,"");


   //===================
    // vector<int> freq (26,0);
    // string str=a+b+c;
    //  for(int i=0;i<str.length();i++){
    //     freq[str[i]-'a']++;
    //  }
    //  string ans="";
    //  for(int i=0;i<26;i++){
    //      if(freq[i]!=0){
    //          ans+=(char)(i + 'a');
    //      }
    // }

    //  //cout<<ans;

    //  crypto(ans,0);

     //==============================

    // cout<<wordBreak("ilikemangoandsamsung",0,"");

   
   

    return 0;
}