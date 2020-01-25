#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dir ={{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
bool isValid(int x,int y,vector<vector<bool>> isVisited)
{
    if(x>=0 && y >=0 && x<isVisited.size() && y<isVisited[0].size() && !isVisited[x][y])
    {
        return true;
    }
    return false;
}
int knightPath(int sr,int sc,int er,int ec,string ans,vector<vector<bool>> isVisited)
{
    if(sr==er && sc==ec)
    {
        cout<<ans<<endl;
        return 1;
    }
    int count = 0;
    isVisited[sr][sc] = 1;
    for(int d = 0; d < dir.size();d++)
    {
        int x = sr + dir[d][0];
        int y = sc + dir[d][1];
        if(isValid(x,y,isVisited))
        {
            count+=knightPath(x,y,er,ec,ans + to_string(x) +"-"+ to_string(y)+" ",isVisited);
        }
    }
    isVisited[sr][sc] = 0;
    return count;
}
int main()
{
    vector<vector<bool>> isVisited = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    cout<<knightPath(0,0,3,3," ",isVisited);
    return 0;

}