#include<bits/stdc++.h>
using namespace std;


class Mystack{
    int *st;
    int idx=-1;
    int length;

    public:
        Mystack(){
            st=new int[20];
            length=20;
        }

        Mystack(int length){
            st=new int[length];
        }

        void print(){

            for(int i=idx;i>=0;i--){
                cout<<st[i]<<" ";

            }cout<<endl;
        }

        int size(){
            return idx+1;
        }

        bool isEmpty(){
            return idx==-1;
        }

        int top(){
            if(isEmpty()){
                cout<<"Stack is Empty";
                return -1;
            }
            return st[idx];
        }

        void push(int data){
            if(idx>=length-1){
                cout<<"Stack Full";
                return;
            }
            idx++;
            st[idx]=data;
        }

        void pop(){
            if(isEmpty()){
                cout<<"stack is Empty ";
                return;
            }
            st[idx]=0;
            idx--;

        }

};

int main(){
    Mystack s=Mystack();
    s.push(10);
    s.print();
}
