#include <iostream>
using namespace std;
class trie
{
    public:
    trie *nxt[26];
    bool ended;

    trie()
    {
        for(int i=0;i<26;i++)
        {
            nxt[i]=NULL;
        }
        ended=false;
    }
};

trie *root;

void insert(string s)
{
    trie *curr=root;
    for(int i=0;i<s.size();i++)
    {
        if(curr->nxt[s[i]-'a']== NULL)
        {
            curr->nxt[s[i]-'a']=new trie();
        }
        curr=curr->nxt[s[i]-'a'];
    }
    //curr pointer will be on last
    curr->ended=true;
}

bool seach_in_trie(string s)
{
    trie *curr=root;
    for(int i=0;i<s.size();i++)
    {
        if(curr->nxt[s[i]-'a']== NULL)
        {
            return false;
        }
        curr=curr->nxt[s[i]-'a'];
    }
    return curr->ended;
}

int main() {
    root=new trie();
    insert("zeeshan");
    insert("apple");

    if(seach_in_trie("apple"))
    {
        cout<<"Found";
    }
    else{
        cout<<"Not founded";
    }
    return 0;
}
