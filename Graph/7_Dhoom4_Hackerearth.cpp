
//Ques7. Dhoom 4-BFS Hackerearth

        //    input-- 3 147
        //            3 
        //            2  10  7 

        // Why BFS:
        // Samarprit has the key 3 initially. He need to get to 147. 
        // First, he will try with all the three available keys which 
        // are 2, 10 and 7.  
         
        // ## Pass 1 
        // With 2: The merged key becomes   :6. 
        // With 10: The merged key becomes :30. 
        // With 7: The merged key becomes    :21. 
         
        // Now again we have three key which were 2, 10 and 7. 
        // And we have three initial keys which are 6, 30 and 21. 
         
        // ## Pass 2: If 6 is Initial Key 
        // With 2: The merged key becomes   :12. 
        // With 10: The merged key becomes :60. 
        // With 7: The merged key becomes   :42. 
         
        // ## Pass 2: If 30 is Initial Key 
        // With 2: The merged key becomes   :60. 
        // With 10: The merged key becomes :300. 
        // With 7: The merged key becomes   :210. 
         
        // ## Pass 2: If 21 is Initial Key 
        // With 2: The merged key becomes   :42. 
        // With 10: The merged key becomes :210. 
        // With 7: The merged key becomes   :147. 
         
        // We got 147 after pass 2. Hence 2 is the required time. 
        // In every pass we have some initial keys. And we need to traverse 
        // the next level, which is exactly what we do in BFS. 

#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;


 
void solve()
{
	lli key,lock,n,i;
	cin>>key>>lock;
	cin>>n;
	lli a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
		
	
	vector<lli> count(100001,-1);

	
	
	queue<lli>q;
	q.push(key);
	count[key]=0;
	while(!q.empty())
	{
		lli cur = q.front();
		//q.pop();
		if(cur==lock)
		{
			break;
		}
		q.pop();
		for(i=0;i<n;i++)
		{
			lli val = (cur*a[i])%100000;
			if(count[val]==-1)
			{
				q.push(val);
				count[val]=count[cur]+1;
			}
		}
	}
	cout<<count[lock];
}
 
int main()
{
	int t=1;
	//cin>>t;
	while(t--)
	{
		solve();
		cout<<endl;
	}
	return 0;
}
	