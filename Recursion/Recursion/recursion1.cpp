#include <iostream>
#include<vector>
using namespace std;

vector<string>find1(int sr,int sc,int er,int ec)
{
    if(sr == er && sc == ec)
    {
        vector<string>ans;
        ans.push_back(" ");
        return ans;
    }

    vector<string> finalans ;
    if(sr+1 <= er)
    {
        vector<string>hori = find1(sr+1,sc,er,ec);
        for(string s:hori)
        {
            finalans.push_back("h"+s);
        }

    }

    if(sc+1 <= ec)
    {
        vector<string>vert = find1(sr,sc+1,er,ec);
        for(string s:vert)
        {
            finalans.push_back("v"+s);
        }
    
    }        
    if(sr+1 <= er && sc+1 <= ec)
    {
        vector<string>diag  = find1(sr+1,sc+1,er,ec);
        for(string s: diag)
        {
            finalans.push_back("d"+s);
        }
    }
    return finalans;
}
vector<string>multimoves(int sr,int sc,int er,int ec)
{
    if(sr == er && sc == ec)
    {
        vector<string>ans;
        ans.push_back(" ");
        return ans;
    }

    vector<string> finalans ;

    for (int i=1;sc+i<=ec;i++)
    {
        vector<string>hori = multimoves(sr,sc+i,er,ec);
        for(string s:hori)
        {
            finalans.push_back("h"+to_string(i)+s);
        }
    }

    for (int i=1;sr+i<=er;i++) 
    {
        vector<string>vert =multimoves(sr+i,sc,er,ec);
        for(string s:vert)
        {
            finalans.push_back("v"+to_string(i)+s);
        }
    }

    return finalans;

}

int main()
{

    //vector<string> ans=find1(0,0,2,2);
    vector<string> ans=multimoves(0,0,2,2);
    for(string i : ans){
        cout<<i;
    }

    return 0;
}
