#include<iostream>
#include<vector>
using namespace std;

bool isvalid(int x ,int y, vector<vector<bool> >visited)
{   //int len = 5;// sizeof(visited[0])/sizeof(int);
    if( x >= 0 && y >=0 && !visited[x][y] &&  x<5 && y<5)
    {
        return true;
    }
    return false;
}


void knight_tour(int sr,int sc,int count,int boxes,vector<vector<bool> >visited, vector<vector<int> >ans)
{
    visited[sr][sc] = true;
    ans[sr][sc] = count;
    if(count == boxes )
    {   
        for(int i = 0 ; i <= 5; i ++)
        {
            for(int j = 0 ; j <= 5 ; j++)
            {
                cout<<ans[i][j]<< " ";

            }cout<<endl;
        }
    }

    int dir[8][2] = { {2,1},{2,-1},{-2,-1},{-2,1},{1,-2},{1,2},{-1,2},{-1,-2} };
    int length = 8;     //sizeof(dir[0])/sizeof(int);
    for(int d = 0 ; d < length ; d++)
    {
        int x = sr + dir[d][0];
        int y = sc + dir[d][1];
        if( isvalid(x,y,visited) )
        {
            knight_tour( x , y , count + 1 , boxes , visited , ans);
        }
    }
    visited[sr][sc] = false;
    ans[sr][sc] = 0;
}



int main()
{
vector<vector<bool>> isVisited (5,vector<bool> (5,false));
    vector<vector<int>> ans= {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}; 
    knight_tour(0,0,0,24,isVisited,ans);
    return 0;   
}