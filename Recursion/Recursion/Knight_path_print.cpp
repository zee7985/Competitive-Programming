#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dir ={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};


bool isValid(int x,int y,vector<vector<bool>> isVisited)
{   cout<<"a"<<isVisited[0].size();
    cout<<"b"<<isVisited.size();
    if(x>=0 && y >=0 && x<isVisited.size() && y<isVisited[0].size() && !isVisited[x][y])
    {
        return true;
    }
    return false;
}
bool knightPath_Fill(int sr,int sc,int count,int Boxes,vector<vector<bool>> isVisited,vector<vector<int>> ans)
{
    isVisited[sr][sc] = 1;
    ans[sr][sc] = count;

    if(count == Boxes - 1)
    {   
        for(auto arr : ans)
        {   
            for(int ele : arr) cout<<ele<<" ";
            cout<<endl; 
        }
        return true;
    }
    bool res = false;
    for(int d = 0; d < dir.size() && !res;d++)
    { 
        int x = sr + dir[d][0];
        int y = sc + dir[d][1];
        if(isValid(x,y,isVisited))
        {
            res = res || knightPath_Fill(x,y,count + 1,Boxes,isVisited,ans);
        }
    }
    isVisited[sr][sc] = 0;
    ans[sr][sc] = 0;
    
    return res;
}


int main(){
    vector<vector<bool>> isVisited (5,vector<bool> (5,false));
    vector<vector<int>> ans= {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}; 
    knightPath_Fill(0,0,1,24,isVisited,ans);
    return 0;   
}