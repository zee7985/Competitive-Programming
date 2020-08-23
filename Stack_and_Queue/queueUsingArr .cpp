// C++ program to implement a queue using an array 
#include <bits/stdc++.h> 
using namespace std; 

class Queue { 
	int front, rear, currentSize,maxSize; 
	int* arr; 

 public:
	Queue(int c=5) 
	{ 
		front  = 0; 
        rear=c-1;
		currentSize = 0;
        maxSize=c; 
		arr = new int[c]; 
	} 

	~Queue() { 
        delete[] arr;
    } 

    bool isFull()
    {
        return maxSize==currentSize;
    }

	void push(int data) 
	{ 
		if(!isFull())
        {
            rear=(rear+1)%maxSize;
			arr[rear] = data; 
            currentSize++;
		} 
	} 

	bool isEmpty()
    {
        return currentSize==0;
    }
	void pop() 
	{ 
		if(!isEmpty())
        {
            front=(front+1)%maxSize;  // no need to delete it will be updated by another no.
            currentSize--;
        }

	} 

	int top() 
	{ 
		return arr[front];
	} 
}; 


int main() 
{ 
	
	Queue q(4); 

	q.push(20); 
	q.push(30); 
	q.push(40); 
	q.push(50); 

	while(!q.isEmpty())
    {
        cout<<q.top()<<" ";
    }

	return 0; 
} 
