#include<bits/stdc++.h>
using namespace std;

void maze_path(int sr,int sc,int er,int ec,string ans)
{
    if(sr==er && sc==ec)
    {
        cout<<ans;
        return;
    }
    if(sr+1 <= er)
    {
        maze_path(sr+1,sc,er,ec,ans+'V');
    }
    if(sc+1 <= ec)
    {
        maze_path(sr,sc+1,er,ec,ans+'H');
    }
}
int maze_path_n_no_of_path(int sr,int sc,int er,int ec,string ans)
{
    if(sr==er && sc==ec)
    {
        cout<<ans;
        return 1;
    }
    int count = 0;
    if(sr+1 <= er)
    {
        count += maze_path_n_no_of_path(sr+1,sc,er,ec,ans+'V');
    }
    if(sc+1 <= ec)
    {
        count += maze_path_n_no_of_path(sr,sc+1,er,ec,ans+'H');
    }
    return count;
}

int main()
{
    //maze_path(0,0,2,2," ");
    int ans = maze_path_n_no_of_path(0,0,2,2," ");
    cout<<endl;
    cout<<"No of paths:"<<ans;
    return 0;
}