/* Program to implement a stack 
using two queue */
#include <bits/stdc++.h> 
using namespace std; 

class Stack { 
	queue<int> q1, q2; 

public: 
	void push(int x) 
	{ 
		q1.push(x); 
	} 


	void pop() 
	{ 
		if (q1.empty()) 
			return; 

		// Leave one element in q1 and 
		// push others in q2. 
		while (q1.size() != 1) { 
			q2.push(q1.front()); 
			q1.pop(); 
		} 

		// Pop the only left element 
		// from q1 
		q1.pop(); 
 

		// swap the names of two queues
        swap(q1,q2); 
	} 

	int top() 
	{ 
		if (q1.empty()) 
			return -1; 

		while (q1.size() != 1) { 
			q2.push(q1.front()); 
			q1.pop(); 
		} 


		int temp = q1.front(); 

		// to empty the auxiliary queue after 
		// last operation 
		q1.pop(); 

		// push last element to q2 
		q2.push(temp); 

		// swap the two queues names 
		swap(q1,q2);
		return temp; 
	} 

	int size() 
	{ 
		return q1.size()+q2.size(); 
	} 
}; 

int main() 
{ 
	Stack s; 
	s.push(1); 
	s.push(2); 
	s.push(3); 
	s.push(4); 

	cout << "current size: " << s.size() 
		<< endl; 
	cout << s.top() << endl; 
	s.pop(); 
	cout << s.top() << endl; 
	s.pop(); 
	cout << s.top() << endl;  
	return 0; 
} 

