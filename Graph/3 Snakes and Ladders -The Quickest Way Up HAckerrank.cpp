Snakes and Ladders: The Quickest Way Up


Markov takes out his Snakes and Ladders game, stares at the board and wonders: "If I can always roll the die to whatever number I want, what would be the least number of rolls to reach the destination?"
Rules The game is played with a cubic die of  6 faces 1 numbered  to 6.
Starting from square 1, land on square 100  with the exact roll of the die. If moving the number rolled would place the player beyond square 100, no move is made.

If a player lands at the base of a ladder, the player must climb the ladder. Ladders go up only.

If a player lands at the mouth of a snake, the player must go down the snake and come out through the tail. Snakes go down only.

Function Description

Complete the quickestWayUp function in the editor below. It should return an integer that represents the minimum number of moves required.

quickestWayUp has the following parameter(s):

ladders: a 2D integer array where each ladders[i] contains the start and end cell numbers of a ladder
snakes: a 2D integer array where each  snakes[i] contains the start and end cell numbers of a snake
Input Format

The first line contains the number of tests, .

For each testcase:
- The first line contains , the number of ladders.
- Each of the next  lines contains two space-separated integers, the start and end of a ladder.
- The next line contains the integer , the number of snakes.
- Each of the next  lines contains two space-separated integers, the start and end of a snake.

Constraints
t<=10
n,m<=15

The board is always  10X10 with squares numbered  to 1 to 100 .
Neither square 1  nor square 100   will be the starting point of a ladder or snake.
A square will have at most one endpoint from either a snake or a ladder.

Output Format

For each of the t test cases, print the least number of rolls to move from start to finish on a separate line. If there is no solution, print -1.

Sample Input

2
3
32 62
42 68
12 98
7
95 13
97 25
93 37
79 27
75 19
49 47
67 17
4
8 52
6 80
26 42
2 72
9
51 19
39 11
37 29
81 3
59 5
79 23
53 7
43 33
77 21 
Sample Output

3
5
Explanation

For the first test:

The player can roll a  5 and a  6 to land at square 12 . There is a ladder to square 98. A roll of 2 ends the traverse in  3 rolls.

For the second test:

The player first rolls  5 and climbs the ladder to square 80  . Three rolls of  6 get to square98  . A final roll of 2  lands on the target square in 5  total rolls.


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        vector<int> numbers(101,0);
        int n; cin>>n;

        for(int i = 0;i<n;i++)
        {
            int u,v;
            cin>>u>>v;

            numbers[u] += (v-u);
        }

        cin>>n;
        for(int i = 0;i<n;i++)
        {
            int u,v;
            cin>>u>>v;

            numbers[u] -= (u-v);
        }

        vector<vector<int>> graph(101);

        for(int i = 1;i<=99;i++)
        {
            for(int j = 1;j<=6;j++)
            {
                int posi = i+j;
                if(i+j>100) continue;
                posi += numbers[posi];

                graph[i].push_back(posi);
            }
        }

        //BFS
        vector<int> dist(101,0);
        vector<int> visited(101,false);

        visited[1] = true;
        queue<int>q;
        q.push(1);
        dist[1] = 0;

        while(!q.empty())
        {
            int cur = q.front();
            q.pop();

            if(cur==100) break;

            for(int ele : graph[cur])
            {
                if(!visited[ele])
                {
                    visited[ele] = true;
                    q.push(ele);
                    dist[ele] = dist[cur] + 1;
                }
            }
        }

        if(!visited[100]) cout<<"-1"<<endl;
        else cout<<dist[100]<<endl;

    }
}



