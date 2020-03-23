#include<bits/stdc++.h>
using namespace std;
bool isvalid(int solve[][9],int row,int col,int number)
{
    for(int i=0;i<9;i++)
    {
        if(solve[row][i] == number || solve[i][col] == number)
        {
            return false;
        }
    }
    int rf = (row/3)*3;
    int cf = (col/3)*3;

    for(int i=0 ; i<3 ; i++)
    {
        for(int j=0 ; j<3 ; j++)
        {
            if(solve[rf + i][cf + j] == number)
            {
                return false;
            }
        }
    }
    return true;
}
bool sudoku_solver(int solve[][9] ,int row,int col,int n)
{
    if( row == n)
    {   
        for(int i=0 ; i<9; i++)
        {
            for(int j=0 ; j<9 ; j++)
            {
                cout<<solve[i][j]<<",";
            }cout<<endl;
        }
        return true;
    }
   
    if(col == n)
    { //  cout<<"a";
        return sudoku_solver(solve,row+1,0,n);
    }
    if(solve[row][col] != 0)
    {   //cout<<"b";
        return sudoku_solver(solve,row,col+1,n);
    }
    for(int num = 1; num<=9 ; num++)
    {
        if(isvalid(solve,row,col,num)==true)
        {
            solve[row][col] = num;
            bool ans = sudoku_solver(solve,row,col+1,n);
            if(ans == true)
            {   
                return true;
            }
        }
    }
    solve[row][col] = 0;
    return false;
}
int main()
{
    int solve[][9] ={   {5,0,0,0,1,0,0,0,4},
                        {2,7,4,0,0,0,6,0,0},
                        {0,8,0,9,0,4,0,0,0},
                        {8,1,0,4,6,0,3,0,2},
                        {0,0,2,0,3,0,1,0,0},
                        {7,0,6,0,9,1,0,5,8},
                        {0,0,0,5,0,3,0,1,0},
                        {0,0,5,0,0,0,9,2,7},
                        {1,0,0,0,2,0,0,0,3} };  
   sudoku_solver(solve,0,0,9);
    
    return 0;
}