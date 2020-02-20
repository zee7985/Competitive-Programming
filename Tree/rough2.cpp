#include <bits/stdc++.h>
using namespace std;



vector<int> cost = {100,75,50,25};


long long int prob3(vector<vector<int>> v,int k,vector<bool> &row_,vector<bool> &col_)
{
    if(k==4) return 0;

    int answer = INT_MIN;

    for(int i = 0;i<4;i++)
    {
        int answer2 = INT_MIN;
        if(!row_[i])
        
            row_[i] = true;
            for(int j = 0;j<4;j++)
            {
                int answer_3 = 0;
                if(!col_[j])
                {
                    col_[j] = true;

                    if(v[i][j])
                    {
                        answer_3 = v[i][j]*cost[k] + solve(v,k+1,row_,col_);
                    }
                    else{
                        answer_3 = -100 + solve(v,k+1,row_,col_);
                    }
                    answer2 = max(answer2,answer_3);
                    col_[j] = false;
                }
            }
            answer = max(answer,answer2);

            row_[i] = false;
        }
    }

    return answer;
}

int main() {
    int t; cin>>t;
    unordered_map<int,int>mp_;
    mp_[12] = 0;
    mp_[3] = 1;
    mp_[6] = 2;
    mp_[9] = 3;

    long long int answer = 0;
    while(t--)
    {
        int n; cin>>n;

        vector<vector<int>> v(4,vector<int>(4,0));

        while(n--)
        {
            char ch;int x;
            cin>>ch>>x;

            v[ch-'A'][mp_[x]]++;
        }

        vector<bool> row_(4,false);
        vector<bool> col_(4,false);
        long long int cur = prob3(v,0,row_,col_);
        cout<<cur<<endl;

        answer += cur;

    }

    cout<<answer;
}