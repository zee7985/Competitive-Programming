#include <iostream>
using namespace std;
class trie
{
    public:
    trie *nxt[26];

    trie()
    {
        for(int i=0;i<26;i++)
        {
            nxt[i]=NULL;
        }
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
    return true;
}

int main() {
    root=new trie();
    string text="abaabadbaaca";
    string pat="aaca";
    int n=text.size();
    int m=pat.size();

    //Insert all suffixes in trie
    for(int i=0;i<n;i++)
    {
        insert(text.substr(i));
    }
    
    // check if pattern is present in trie or not
    if(seach_in_trie(pat))
    {
        cout<<"Found";
    }
    else{
        cout<<"Not founded";
    }
    return 0;
}
