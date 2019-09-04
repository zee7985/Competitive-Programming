#include<iostream>
#include<cmath>

using namespace std;
bool canplace(int arr[][9],int i,int j,int n,int number)
{  //row n column check
    for(int x=0;x<n;x++)
    {
     if(arr[x][j]==number || arr[i][x]==number)
      {
        return false;
      }
    }
int rx=sqrt(n);
int sx=(i/rx)*rx;
int sy=(j/rx)*rx;

for(int q=sx;q<sx+rx;q++)
    {
        for(int w=sy;w<sy+rx;w++)
        {
            if(arr[q][w]==number)
            {
                return false;
            }
        }
    }
return true;
}
bool sudoku(int arr[][9],int i,int j,int n)
{
    //print
if(i==n)
 {
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            {
                cout<<arr[i][j]<<" ";
            }   cout<<endl;
        }return true;
    }
    if(j==n)
    {
       return sudoku(arr,i+1,0,n);
    }
  if(arr[i][j]!=0)
    {
      return sudoku(arr,i,j+1,n);
    }
    for(int number=1;number<=n;number++)
    {
        if(canplace(arr,i,j,n,number)==true)
        {
            arr[i][j]=number;

            bool couldwesolve=sudoku(arr,i,j+1,n);
            if(couldwesolve==true)
            {cout<<arr[i][j];
                return true;

            }
         }
    }
    arr[i][j]=0;  //Backtracking
    return false;
}

int main() {
int arr[][9]={{5,0,0,0,1,0,0,0,4},
                {2,7,4,0,0,0,6,0,0},
                {0,8,0,9,0,4,0,0,0},
                {8,1,0,4,6,0,3,0,2},
                {0,0,2,0,3,0,1,0,0},
                {7,0,6,0,9,1,0,5,8},
                {0,0,0,5,0,3,0,1,0},
                {0,0,5,0,0,0,9,2,7},
                {1,0,0,0,2,0,0,0,3}
                };
sudoku(arr,0,0,9);
return 0;
}
