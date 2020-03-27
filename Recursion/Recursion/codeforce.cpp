#include<bits/stdc++.h>
using namespace std;

vector<string>find_path(int sr,int sc,int er, int ec,vector<vector<bool> >item , vector<vector<bool> >path , int count )
{
    if(sr == er && sc ==ec && count == 5 )
    {   
        vector<string>ans;
        ans.push_back(" ");
        return ans;
    }
    path[sr][sc] = true;
    vector<string> finalans;
    if(sr + 1 <= er && !path[sr+1][sc])
    {   
        if(item[sr+1][sc] == true)
        {
            count++;
        }
        vector<string>ans = find_path(sr+1,sc,er,ec,item,path,count);
        for(string s: ans)
        {
            finalans.push_back('U' + s);
        }
    }
    if(sc + 1 <= ec && !path[sr][sc+1])
    {   
        if(item[sr][sc+1] == true)
        {
            count++;
        }
        vector<string>ans = find_path(sr,sc+1,er,ec,item,path,count);
        for(string s: ans)
        {
            finalans.push_back('R' + s);
        }
    }
    path[sr][sc] = false;
    if(item[sr][sc] == true)
    {
        count = count - 1;
    }
    return finalans;
}

int main()
{
    int n = 5;
    vector<vector<bool> >item(n+1, vector<bool>( n+1 , false));
    item[1][3] = true;
    item[1][2] = true;
    item[3][3] = true;
    item[5][5] = true;
    item[4][3] = true;

    vector<vector<bool> >path (n+1 , vector<bool> (n+1 , false));

    vector<string>ans = find_path(0,0,5,5,item,path,0);
    for(string s : ans)
    {
        cout<<s<<" ";
    }
    return 0;
}
//RUUURRRRUU