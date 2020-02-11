#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    node *next;
    int data;

    node(int d){
        data=d;
        next=NULL;
    }
};


void insertAtHead(node *&head,int data){
    node *n=new node(data);
    n->next=head;
    head=n;
}

node *merge(node *a,node *b){
    if(a==NULL){
        return b;
    }
    else  if(b==NULL){
        return a;
    } 
    node *c;
    if(a->data < b->data){
            c=a;
            c->next=merge(a->next,b);
        }
     else{
           
        c=b;
         c->next=merge(a,b->next);
    }
    return c;
}


void printHead(node *head){
   // node *temp=head;
    while(head!=NULL){
        cout<<head->data;
        head=head->next;
    }
}


int main() {
    node* head1;
    node *head=NULL;
    node *head2=NULL;
    
    insertAtHead(head,8);
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,1);
    printHead(head);
    cout<<endl;

    insertAtHead(head2,7);
    insertAtHead(head2,6);
    insertAtHead(head2,3);
    insertAtHead(head2,2);
    printHead(head2);
    cout<<endl;

    head1=merge(head,head2);
    printHead(head1);
}
