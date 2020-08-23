//Given a stream of characters and we have to find first non repeating character each time a character is inserted to the stream.

Input  : a a b c
Output : a -1 b b

#include <bits/stdc++.h>
using namespace std;

int main() {
    int freq[26]={0};
    queue<char> q;

    char ch;
    cin>>ch;

    while(ch!='.')
    {
        freq[ch-'a']++;
        q.push(ch);

        while(!q.empty())
        {
            int idx=q.front()-'a';
            if(freq[idx]>1)
            {
                q.pop();
            }
            else
            {
                cout<<q.front()<<" ";
                break;
            }
        }
        if(q.empty())
        {
            cout<<"-1 ";
        }
        cin>>ch;
    }
    return 0;
    
}
