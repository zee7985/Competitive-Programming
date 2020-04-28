//Ques 5.Mancunian And Liverbird Go Bar Hopping-Hackerearth

//Hint-As only two direction possible-So we precompute answer for both the        //    directions .
//    find maximum reachable nodes from each node from both side(left and right)
//    -Ans will be right_1 + left_0 + 1(For initial direction)
//                right_0 + left_1 + 1(For opposite direction)

#include<bits/stdc++.h>
using namespace std;
long long int a[1000005];
int right_1[1000005],right_0[1000005];
int left_0[1000005], left_1[1000005];
int n;

void solve()
{
    int x = 0;
    right_1[n-1] = 0;
    
    for( int i = n-2; i >= 0; i-- )
    {
        if( a[i] == 1 )x++;
        else x = 0;
        right_1[i] = x;
    }
    
    x = 0;
    left_0[0] = 0;
    
    for( int i = 1 ; i < n; i++ )
    {
        if( a[i-1] == 0 )x++;
        else x = 0;
        left_0[i] = x;
    }
    
    x= 0;
    right_0[n-1] = 0;
    for( int i = n-2; i >= 0; i-- )
    {
        if( a[i] == 0 )x++;
        else x = 0;
    right_0[i] = x;
    }
    
    x = 0;
    left_1[0] = 0;
    for( int i = 1 ; i < n; i++ )
    {
        if(a[i-1]==1)x++;
        else x = 0;
        left_1[i] = x;
    }
}
int main() 
{
   
	cin>>n;
    
    for( int i = 0; i < n-1; i++ )
	{
        cin>>a[i];
	}
    
    solve();
    int q;
    cin>>q;
    int x = 0;
    
    int cntOfUpdate = 0;
    while(q--)
    {
        char c;
        cin>>c;
        if(c=='Q')
        {
            cin>>x;
            
            if( cntOfUpdate%2==1 )
                cout<<right_0[x-1]+left_1[x-1]+1<<endl; //+1 for current element
            else
                cout<<right_1[x-1]+left_0[x-1]+1<<endl;
        }
        else
            cntOfUpdate++;
    }
    
    return 0;
}