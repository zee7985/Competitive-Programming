//merge k sorted arrays 
#include <bits/stdc++.h> 
using namespace std; 

// first -value, second - index of array 
// and third - index in the array. 
typedef pair<int, pair<int, int> > ppi; 

vector<int> mergeKArrays(vector<vector<int> > arr) 
{ 
	vector<int> output; 

	// Create a min heap with k heap nodes. 
	priority_queue<ppi, vector<ppi>, greater<ppi> > pq; 

	for (int i = 0; i < arr.size(); i++) 
		pq.push({ arr[i][0], { i, 0 } }); 

	while (!pq.empty()) { 
		ppi curr = pq.top(); 
		pq.pop();  
		int i = curr.second.first; 
		int j = curr.second.second; 

		output.push_back(curr.first); 

		// The next element belongs to same array as 
		// current. 
		if (j + 1 < arr[i].size()) 
			pq.push({ arr[i][j + 1], { i, j + 1 } }); 
	} 

	return output; 
} 

int main() 
{ 
	vector<vector<int> > arr{ { 2, 6, 12 }, 
							{ 1, 9 }, 
							{ 23, 34, 90, 2000 } }; 

	vector<int> output = mergeKArrays(arr); 

	for (auto x : output) 
		cout << x << " "; 

	return 0; 
} 
