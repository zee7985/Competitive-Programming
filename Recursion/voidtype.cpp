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

//=========================================================================================
    

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


//Permutation with Repetition
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

// Combination with Repetition
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

// Combination without Repetition
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

//Permutation without Repetition
int coinPermu_02(vector<int> &arr, vector<bool> &vis, int tar, string ans)
{
    if (tar == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (tar - arr[i] >= 0 && !vis[i])
        {
            vis[i] = true;
            count += coinPermu_02(arr, vis, tar - arr[i], ans + to_string(arr[i]) + " ");
            vis[i] = false;
        }
    }
    return count;
}

//Permutation by Subsequence Method
int coinPermu_03(vector<int> &arr, int idx, int tar, string ans)
{
    if (idx == arr.size() || tar == 0)
    {
        if (tar == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    if (tar - arr[idx] >= 0)
    {
        count += coinPermu_03(arr, 0, tar - arr[idx], ans + to_string(arr[idx]) + " ");
    }
    count += coinPermu_03(arr, idx + 1, tar, ans);
    return count;
}

//Combination by Subsequence Method(repetition of coin)

int coinCombi_03(vector<int> &arr, int idx, int tar, string ans)
{
    if (idx == arr.size() || tar == 0)
    {
        if (tar == 0)
        {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }

    int count = 0;
    if (tar - arr[idx] >= 0)
    {
        count += coinCombi_03(arr, idx, tar - arr[idx], ans + to_string(arr[idx]) + " "); //for without repetition use idx+1 here
    }
    count += coinCombi_03(arr, idx + 1, tar, ans);
    return count;
}

//========================================================================================================
//NQUEEN PROBEM

// int placeNqueenCombi(int n,int vidx,int queen,string ans){

//     if(vidx==n || queen<=0){
//         if(queen==0){
//             cout<<ans<<endl;
//             return 1;
//         }
//         return 0;
//     }
//     int count=0;
//     for(int i=vidx;i<n;i++){
//         if(n-i>=queen)
//             count+=placeNqueenCombi(n,i+1,queen-1,ans+ to_string(i+1)+ "q");
//         }
    
//     return count;

// }

// int placeNqueenPermut(int n,int queen,vector<bool> visited,string ans){

//     if(queen==0){
//             cout<<ans<<endl;
//             return 1;
//         }

//     int count=0;
//     for(int i=0;i<n;i++){
//         if(!visited[i]){
//             visited[i]=true;
//             count+=placeNqueenPermut(n,queen-1,visited,ans+ to_string(i+1)+ "q");
//             visited[i]=false;
//         }
//     }
    
//     return count;

// }


int queenBoxCombi(int tnq, int tnb, int lqpsf, string ans)
{
    if (tnq == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = lqpsf; i < tnb; i++)
    {

        count += queenBoxCombi(tnq - 1, tnb, i + 1,ans + "b" + to_string(i) + "q" + to_string(tnq) + " ");
    }
    return count;
}

int queenBoxPermu(int tnq, vector<bool> tnb, string ans)
{
    if (tnq == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = 0; i < tnb.size(); i++)
    {
        if (!tnb[i])
        {
            tnb[i] = true;
            count += queenBoxPermu(tnq - 1, tnb,ans + "b" + to_string(i) + "q" + to_string(tnq) + " ");
            tnb[i] = false;
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
//NqueenPermut2D(0,0,3,3,3,visited,"");

int queen2dBoxCombi(int tnq, vector<vector<bool>> &tnb, int lqpsf, string ans)
{
    if (tnq == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = lqpsf; i < tnb.size() * tnb[0].size(); i++)
    {
        int x = i / tnb[0].size();
        int y = i % tnb[0].size();

        count += queen2dBoxCombi(tnq - 1, tnb, i + 1, ans + "(" + to_string(x) + ", " +to_string(y) + ") ");
    }
    return count;
}

int queen2DBoxPermu(int tnq, vector<vector<bool>> &tnb, string ans)
{
    if (tnq == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = 0; i < tnb.size() * tnb[0].size(); i++)
    {
        int x = i / tnb[0].size();
        int y = i % tnb[0].size();

        if (!tnb[x][y])
        {
            tnb[x][y] = true;
            count += queen2DBoxPermu(tnq - 1, tnb,ans + "(" + to_string(x) + ", " + to_string(y) + ") ");
            tnb[x][y] = false;
        }
    }
    return count;
}

//Nquuen with rules
bool isSafeToPlaceQueen(vector<vector<bool>> &boxes, int x, int y)
{
    int xdir[4] = {0, -1, -1, -1};
    int ydir[4] = {-1, -1, 0, 1};

    for (int rad = 1; rad < max(boxes.size(), boxes[0].size()); rad++)
    {
        for (int d = 0; d < 4; d++)
        {
            int r = x + rad * xdir[d];
            int c = y + rad * ydir[d];
            if (r >= 0 && c >= 0 && r < boxes.size() && c < boxes[0].size() && boxes[r][c])
                return false;
        }
    }
    
    return true;
}

int nQueenRules(int tnq, vector<vector<bool>> &boxes, int lqpsf, string ans)   //same 
{
    if (tnq == 0)
    {
        cout << ans << endl;
        return 1;
    }

    int count = 0;
    for (int i = lqpsf; i < boxes.size() * boxes[0].size(); i++)
    {
        int x = i / boxes[0].size();
        int y = i % boxes[0].size();
        if (isSafeToPlaceQueen(boxes, x, y))
        {
            boxes[x][y] = true;
            count += nQueenRules(tnq - 1, boxes, i + 1,ans + "(" + to_string(x) + ", " +to_string(y) + ") ");
            boxes[x][y] = false;
        }
    }
    return count;
}

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



//======================================
//Crossword Hackerank


vector<vector<char>> board = {
    {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
    {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
    {'+', '-', '-', '-', '-', '-', '-', '-', '+', '+'},
    {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
    {'+', '-', '+', '+', '+', '+', '+', '+', '+', '+'},
    {'+', '-', '-', '-', '-', '-', '-', '+', '+', '+'},
    {'+', '-', '+', '+', '+', '-', '+', '+', '+', '+'},
    {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
    {'+', '+', '+', '+', '+', '-', '+', '+', '+', '+'},
    {'+', '+', '+', '+', '+', '+', '+', '+', '+', '+'}};

bool canPlaceVertical(string word, int r, int c)
{
    if (r == 0 && word.length() != board.size())
    {
        if (board[r + word.length()][c] != '+')
            return false;
    }
    else if ((r + word.length()) == board.size() && word.length() != board.size())
    {
        if (board[r - 1][c] != '+')
            return false;
    }
    else
    {
        if (board[r - 1][c] != '+' || board[r + word.length()][c] != '+')
            return false;
    }

    for (int i = 0; i < word.length(); i++)
    {
        if (!(board[r + i][c] == '-' || word[i] == board[r + i][c]))
        {
            return false;
        }
    }
    return true;
}

vector<bool> placeWordVertical(string word, int r, int c)
{
    vector<bool> pos(word.length(), false);
    for (int i = 0; i < word.length(); i++)
    {
        if (board[r + i][c] == '-')
        {
            board[r + i][c] = word[i];
            pos[i] = true;
        }
    }

    return pos;
}

void unplaceWordVertical(int r, int c, vector<bool> pos)
{
    for (int i = 0; i < pos.size(); i++)
    {
        if (pos[i])
        {
            board[r + i][c] = '-';
        }
    }
}

bool canPlaceHorizontal(string word, int r, int c)
{
    if (c == 0 && word.length() != board[0].size())
    {
        if (board[r][c + word.length()] != '+')
            return false;
    }
    else if ((c + word.length()) == board[0].size() && word.length() != board[0].size())
    {
        if (board[r][c - 1] != '+')
            return false;
    }
    else
    {
        if (board[r][c - 1] != '+' || board[r][c + word.length()] != '+')
            return false;
    }

    for (int i = 0; i < word.length(); i++)
    {
        if (!(board[r][c + i] == '-' || word[i] == board[r][c + i]))
        {
            return false;
        }
    }
    return true;
}

vector<bool> placeWordHorizontal(string word, int r, int c)
{
    vector<bool> pos(word.length(), false);
    for (int i = 0; i < word.length(); i++)
    {
        if (board[r][c + i] == '-')
        {
            board[r][c + i] = word[i];
            pos[i] = true;
        }
    }

    return pos;
}

void unplaceWordHorizontal(int r, int c, vector<bool> pos)
{
    for (int i = 0; i < pos.size(); i++)
    {
        if (pos[i])
        {
            board[r][c + i] = '-';
        }
    }
}

int crossWordUtil(vector<string> &words, int idx)
{
    if (idx == words.size())
    {
        for (vector<char> ar : board)
        {
            for (char ele : ar)
            {
                cout << ele << " ";
            }
            cout << endl;
        }
        return 1;
    }

    string word = words[idx];
    int count = 0;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {

            if (canPlaceHorizontal(word, i, j))
            {
                vector<bool> pos = placeWordHorizontal(word, i, j);
                count += crossWordUtil(words, idx + 1);
                unplaceWordHorizontal(i,j,pos);
            }

            if (canPlaceVertical(word, i, j))
            {
                vector<bool> pos = placeWordVertical(word, i, j);
                count += crossWordUtil(words, idx + 1);
                unplaceWordVertical(i,j,pos);
            }
        }
    }
    return count;
}





int main(){ 

    // subseq("abc","");
    // removeHi("ihihiiiihiiihhii","");
    // removeDuplicate("aaabbbbccc","");
     //stringCompression("aaabbbbccc","",1);
    // mazePath(0,0,2,2,"");
  // cout<<boardPathDice(0,10,"");
  

//============================================
    //vector<int>arr={2,3,5,7};
    //cout<<coinChangePermute01(arr,0,10,"");
    //cout<<coinChangeCombina01(arr,0,10,"");
// cout << coinPermu_02(arr, vis, 10, "") << endl;
   // coinChangeCombina02(arr,0,10,"");
   //cout << coinPermu_03(arr, 0, 10, "") << endl;
   //cout<<coinCombi_03(arr,0,10,"");

   

   //========================

   // vector<bool> tnb(5,false);
    // cout << queenBoxCombi(4, 16, 0, "") << endl;
    // cout<<queenBoxPermu(3,tnb,"")<<endl;

    // cout<<NqueenCombi_sub(5,3,0,0,"");


    // vector<vector<bool>> boxes(7, vector<bool>(7, 0));
    // cout << nQueenRules(7, boxes, 0, "") << endl;


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

    //=============================================
    vector<string> words = {"agra", "norway", "england", "gwalior"};
    cout << crossWordUtil(words, 0) << endl;

   
   

    return 0;
}