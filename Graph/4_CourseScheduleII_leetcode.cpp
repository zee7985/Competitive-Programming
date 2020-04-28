//Ques. Course Schedule II - Topological Sort with cycle Detection(Directed Graph)

class Solution {
    
public:
    vector<vector<int>> graph;
    
    bool topoHelper(int u, vector<bool> &visited,vector<bool> &recStack, stack<int> &s) //return cycle                                                                                             aur not
    {
    
        visited[u] = true;
        recStack[u]=true;

        for (int e : graph[u])
        {
            if (!visited[e] && topoHelper(e, visited,recStack,s)){
                
                return true;
            }
            else if(recStack[e]){      //If Already in recursion stack ,then return cycle is there
                return true;
            }
        }   
        s.push(u);
    
    recStack[u]=false;
    return false;
    }


    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        
        vector<int> ans;
         for(int i = 0;i<numCourses;i++) 
        {
            vector<int> v;
            graph.push_back(v);
        }
        
        for(int i=0;i<prerequisites.size();i++)
        {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
            
        vector<bool> visited(graph.size(), false);
        vector<bool> recStack(graph.size(), false);
        stack<int> s;
        for (int i = 0; i < graph.size(); i++)
        {
            if(!visited[i]){
                if(topoHelper(i, visited,recStack, s)) return {};
            }
                
        }

        while (!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
      
};