#include<bits/stdc++.h>
using namespace std;


class MyQueue{
    int *arr;
    int st=0;
    int end=0;
    int cur_size;

    public:
        MyQueue(){
            
        }

        MyQueue
        
        (int length){
            
        }

        void print(){
            for(int i=0;i<size;i--){
                int j=(st+i)%arr.size();
                cout<<arr[j]<<" ";

            }cout<<endl;
        }

        int size(){
            return cur_size;
        }

        bool isEmpty(){
            return cur_size==0;
        }