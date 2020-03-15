#include<bits/stdc++.h>
using namespace std;
vector<string>encoding(string ques)
{   
    if(ques.size() == 0)
    {
        vector<string>base ;
        base.push_back(" ");
        return base;
    }
    char ch = ques[0];    //'1'
    vector<string>finalans;
    if(ch == '0')
    {
       return encoding(ques.substr(1));
    }
    else
    {
        vector<string>ans = encoding(ques.substr(1));
        for(string s: ans)
        {
            char ch1 = char('a' + ch - '1');// To convert integer of type char to character like a,b,c
            finalans.push_back(ch1 +s);
        }
    }
    if(ques.size() > 1)
    {
        char ch2 = ques[1];
        //char final_ch = char( ('a' + ch - '1')*10  + ('a' + ch - '1'));
        int num = (ch - '0')*10 + (ch2 - '0');  //  '1' - '0'
        vector<string> ans  = encoding(ques.substr(2));
        for(string s:ans)
        {   
            char ch3=(char)('a' + num -1);
            finalans.push_back(ch3 + s);
        }
    }
    return finalans;
}

int main()
{
    string ques = "11023";
    vector<string> ans = encoding(ques);
    for(string s: ans)
    {
        cout<<s<<" ";
    }
}