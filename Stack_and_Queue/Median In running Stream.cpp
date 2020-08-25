// median in  stream of running integers 
#include<bits/stdc++.h> 
using namespace std; 

int main() 
{ 
	priority_queue<int> maxHeap; 
	priority_queue<int,vector<int>,greater<int> > minHeap; 

    int d;
	cin>>d;
    float med=d;
    cout<<med<<"\n";
	maxHeap.push(d); 
    cin>>d;

	while(d!=-1)
	{ 
		//case 1
		if (maxHeap.size() > minHeap.size()) 
		{ 
			if (d < med) 
			{ 
				minHeap.push(maxHeap.top()); 
				maxHeap.pop(); 
				maxHeap.push(d); 
			} 
			else
				minHeap.push(d); 

			med = (maxHeap.top() + minHeap.top())/2.0; 
		} 

		// case2(both heaps are balanced) 
		else if (maxHeap.size()==minHeap.size()) 
		{ 
			if (d < med) 
			{ 
				maxHeap.push(d); 
				med = (int)maxHeap.top(); 
			} 
			else
			{ 
				minHeap.push(d); 
				med = (int)minHeap.top(); 
			} 
		} 

		// case3(right side heap has more elements) 
		else
		{ 
			if (d > med) 
			{ 
				maxHeap.push(minHeap.top()); 
				minHeap.pop(); 
				minHeap.push(d); 
			} 
			else
				maxHeap.push(d); 

			med = (maxHeap.top() + minHeap.top())/2.0; 
		} 

		cout << med << endl; 
        cin>>d;
	} 
	return 0; 

} 
