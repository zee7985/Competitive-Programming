#include<bits/stdc++.h>
using namespace std;

bool isOperator(char ch){
    if(ch=='+' || ch=='-'  || ch=='*' || ch=='/' || ch=='^' ){
        return true;
    }
    return false;
}

int priority(char ch){
    if(ch== '+' || ch== '-'){
        return 0;
    }
    else if(ch== '*' || ch== '/'){
        return 1;
    }
    else if(ch== '^'){
        return 2;
    }
    return -1;

}

int performOperation(int val1,int val2,char ch){
    if(ch=='+') {
        return val1+val2;
    }
    else if(ch=='-') {
        return val2-val1;
    }
    else if(ch=='*') {
        return val1*val2;
    }
    else if(ch=='/') {
        return val2/val1;
    }
    else{
        return (int)pow(val2,val1);
    }

}

int infix(string str){

    stack <int> numberSt;
    stack<char> operatorSt;

    for(int i=0;i<str.length();i++){
        char ch=str[i];
        if(ch>='0' && ch<='9'){
            numberSt.push(ch-'0');
        }
        else if(ch=='('){
            operatorSt.push(ch);
        }
        else if(isOperator(ch)){
           //priority greater so resolve
            while(operatorSt.size()!=0 && operatorSt.top() !='(' && priority(operatorSt.top())>priority(ch)){
            int val1=numberSt.top();
            numberSt.pop();
            int val2=numberSt.top();
            numberSt.pop();
            char c=operatorSt.top();
            operatorSt.pop();
                       
            int ans=performOperation(val1,val2,c);
            numberSt.push(ans);
            }
            operatorSt.push(ch);
        }
        else{
            while(operatorSt.top() !='('){
                int val1=numberSt.top();
                numberSt.pop();
                int val2=numberSt.top();
                numberSt.pop();
                char c=operatorSt.top();
                operatorSt.pop();
                       
                int ans=performOperation(val1,val2,c);
                numberSt.push(ans);
            }
            operatorSt.top();
            operatorSt.pop();
        }
    }
    while(operatorSt.size()!=0){       //important -it can  happen that all the operator are nor resolved completely,so resolving
        int val1=numberSt.top();
        numberSt.pop();
        int val2=numberSt.top();
        numberSt.pop();
        char c=operatorSt.top();
        operatorSt.pop();
                       
        int ans=performOperation(val1,val2,c);
        numberSt.push(ans);
    }
    return numberSt.top();
    
}
int main(){
    
    cout<<infix("8+4*3-9/3^(2-1)")<<endl;
}

