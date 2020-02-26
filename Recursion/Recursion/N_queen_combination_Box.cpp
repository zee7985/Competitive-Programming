#include<bits/stdc++.h>
using namespace std;

int n_queen_box_combination(int queen , int boxes_size , int lqpsf , string ans) //boxes_size = 4
{
    if(queen == 0)
    {
        cout<<ans;
        cout<<endl;
        return 1;
    }
    int count = 0;
    for(int i = lqpsf ; i < boxes_size*boxes_size ; i++)
    {   
        int x = i / boxes_size;
        int y = i % boxes_size;

        count += n_queen_box_combination(queen - 1 , boxes_size , i + 1 , ans + "(" + to_string(x) + "," + to_string(y) + ")" +"Q" +to_string(queen) );
    }
    return count;
}
int n_queen_box_permutation(vector<vector<bool> >isvisit ,int queens ,string ans)
{
    if( queens == 0 )
    {
        cout<<ans;
        cout<<endl;
        return 1;
    }
    int count = 0; 
    for(int i = 0 ; i < isvisit.size()*isvisit[1].size() ; i++)
    {
        int x = i / isvisit.size() ;
        int y = i % isvisit[1].size() ;
         
        if (isvisit[x][y] == false)
        {   
            isvisit[x][y] = true;
            count += n_queen_box_permutation(isvisit , queens - 1 , ans + "(" + to_string(x) + "," + to_string(y) +")" +"Q" + to_string(queens) );
        }
        isvisit[x][y] = false;
    }
    return count;
}
int main()
{
    //int a = n_queen_box_combination(3 , 4 , 0 , " ");

    vector<vector< bool > >isvisit (4,vector<bool>(4,false) );
    int a = n_queen_box_permutation(isvisit , 3 , " ");
    cout<<"aaaa"<<a;
    return 0;
}