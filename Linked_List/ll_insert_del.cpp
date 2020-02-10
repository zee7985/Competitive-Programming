#include <iostream>
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

void insertAtTail(node *&head,int data){
    if(head==NULL){
        head=new node(data);
    }
    else{
        node *tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        tail->next=new node(data);
    }
}

int length(node *head){
    int len=0;
    while(head!=NULL){
        head=head->next;
        len++;
    }
    return len;
}

void insertAtMiddle(node *&head,int data,int p){
    if(head==NULL || p==0){
        insertAtHead(head,data);
    }
    else if(p>length(head)){
        insertAtTail(head,data);
    }
    else{
        node *temp=head;
        int jump=1;
        while(jump<=p-1){
            temp=temp->next;
            jump++;
            }
            node *n=new node(data);
            n->next=temp->next;
            temp->next=n;
    }
}


void deleteAtHead(node *&head){
    if(head==NULL){
        return;

    }
    node *temp=head;
    head=head->next;
    delete temp;
}

void deleteAtTail(node *&head){
    node*prev=NULL;
    node *temp=head;

    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
        
    }
    delete temp;
    prev->next=NULL;
    return;
}

void deleteAtMiddle(node *&head,int p){
    if(head==NULL){
        return;
    }
    else if(p==1){
        deleteAtHead(head);

    }
    else if(p>=length(head)){
        deleteAtTail(head);

    }
    else{
        node *temp=head;
        for(int i=1;i<p-1;i++){
            temp=temp->next;
        }
        node *temp1=temp->next;
        temp->next=temp1->next;
        delete temp1;
    }

}

void printHead(node *head){
   // node *temp=head;
    while(head!=NULL){
        cout<<head->data;
        head=head->next;
    }
}

int main() {
    node *head=NULL;
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    //printHead(head);
    insertAtTail(head,6);
    insertAtTail(head,7);
    insertAtTail(head,8);
    //insertAtTail(head,2);
    //insertAtTail(head,1);
    insertAtMiddle(head,9,4);
    insertAtMiddle(head,0,7);
    deleteAtHead(head);
    deleteAtTail(head);
   deleteAtMiddle(head,8);
    printHead(head);


}
