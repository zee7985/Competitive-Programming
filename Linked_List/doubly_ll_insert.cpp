#include <iostream>
using namespace std;

class node{
    public:
    node *next;
    node*prev;
    int data;

    node(int d){
        data=d;
        next=NULL;
        prev=NULL;
    }
};

void insertAtHead(node *&head,int data)
{
    node *n=new node(data);
    n->next=head;
    if(head !=  NULL)
    {
        head->prev=n;
    }
     n->prev=NULL;
    head=n;
}

void insertAtTail(node *&head,int data)
{
    node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    node *n =new node(data);
    temp->next=n;
    n->prev=temp;
    n->next=NULL;
}

void insertAtMiddle(node *&head,int data,int p)
{
    node *temp=head;
    int jump=1;
    while(jump<=p-1){
        temp=temp->next;
        jump++;
     }
    node *n =new node(data);
    node *store;
    store=temp->next;
    temp->next=n;
    n->prev=temp;
    n->next=store;
    store->prev=n;
}

void printHead(node *head){
   // node *temp=head;
    while(head!=NULL){
        cout<<head->data;
        head=head->next;
    }
}


int main() {
    node*head=NULL;
    insertAtHead(head,8);
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,1);
    insertAtTail(head,6);
    insertAtMiddle(head,9,3);
    printHead(head);
    cout<<endl;
}
