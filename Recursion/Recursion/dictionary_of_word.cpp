#include<bits/stdc++.h>
using namespace std;

string dict[] = {"i", "like","ilike" ,"man" , "go" , "mango", "and" , "sam" , "sung" , "samsung"};
string word = "ilikemangoandsamsung";

bool iswordpresent(string word)
{
    for(string s : dict)
    {
        if(s.compare(word)==0 )
        {
            return true;
        }
    }
    return false;
} 
int wordbreak(string word , int idx , string ans)
{
    //base case
    if(idx == word.length())
    {
        cout<<ans;
        cout<<endl; 
        return 1;
    }
    int count = 0;
    string temp = "";
    for(int i=idx ; i< word.length() ; i++)
    {
        temp += word[i];
        if(iswordpresent(temp))
        {
            count += wordbreak(word , i+1 , ans + temp +" ");
        }
    }
    return count;
}
int main()
{
    int count = wordbreak(word , 0 , "");
    cout<<count;
    return 0;
}