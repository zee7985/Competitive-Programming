
#include<bits/stdc++.h>

using namespace std;

vector<string >maze_path_8(int sr,int sc,int er,int ec,bool visited[4][4])
{
    if(sr == er && sc == ec)
    {
        vector<string>finalans;        
        finalans.push_back(" ");
        return finalans;
    }

    visited[sr][sc] = true;
    vector<string>finalans;
    
    if(sr-1>=0 && !visited[sr-1][sc])
    {
        vector<string>up = maze_path_8(sr-1,sc,er,ec,visited);
        for(auto s: up)
        {   
            finalans.push_back("U" + s);
        }
    }
    if(sc+1<=ec && !visited[sr][sc+1])
    {
        vector<string>right = maze_path_8(sr,sc+1,er,ec,visited);
        for(auto s: right)
        {   
            finalans.push_back("R" + s);
            //count += s.second;
        }
    }
    if(sr+1 <= er && !visited[sr+1][sc])
    {
        vector<string>down = maze_path_8(sr+1,sc,er,ec,visited);
        for(auto s: down)
        {
            finalans.push_back("D" + s);
           // count += s.second;
        }
    }
    if(sc-1>=0 && !visited[sr][sc-1])
    {
        vector<string>left = maze_path_8(sr,sc-1,er,ec,visited);
        for(auto s: left)
        {
            finalans.push_back("L" + s);
            //count += s.second;
        }
    }
    
visited[sr][sc] = false;
   // cout<<count<<" ";
    return finalans;
}

int main()
{
   /* bool obstacle[4][4]= {false};
    obstacle[1][2] = true;
    obstacle[2][2] = true;
    obstacle[3][2] = true;
    obstacle[4][3] = true;*/


    bool obstacle[4][4]={{false,false,false,false},
                          {false,false,true,false},
                          {false,false,false,false},
                         {false,false,true,false} };
    vector<string>ans = maze_path_8(0,0,3,3,obstacle);
    for(auto s: ans)
    {
        cout<<s<<" ";
    }
    cout<<ans.size();
return 0;
}

//DDRRDR, DDRRRD, DDRLLRRDDD, DDRLLRRDDUDR, DRDRDR, DRDRRD, DRLRRDDD, DRLRRDDUDR, RDDRDR, RDDRRD, RDUDRRDR, RDUDRRRD, RRRDDD, RRRDDUDR