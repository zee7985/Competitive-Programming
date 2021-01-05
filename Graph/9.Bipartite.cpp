//BFS
class Solution {
public:
    class partite_pair
    {
    public:
    int vtx = -1;
    int colour = -1;

    partite_pair(int vtx, int colour)
    {
        this->vtx = vtx;
        this->colour = colour;
    }

    partite_pair()
    {
    }
    };
    bool isBipartite(vector<vector<int>>& graph) {
       vector<int> vis(graph.size(),-1);
        list<partite_pair> que;
        partite_pair root(0, 0);
        que.push_back(root);

        bool res = false;

        while (que.size() > 0)
        {
        //remove vertex
        partite_pair rpair = que.front();
        que.pop_front();

        if (vis[rpair.vtx] != -1)
        {
            if (vis[rpair.vtx] != rpair.colour)
            {
                
                res = false;
                break;
            }
            else
            {
                res=true;
            }

            continue;
        }

        vis[rpair.vtx] = rpair.colour;

        for (int e : graph[rpair.vtx])
        {

            if (vis[e] == -1)
            {
                int new_colour = (rpair.colour + 1) % 2;
                partite_pair npair(e, new_colour);
                que.push_back(npair);
            }
        }
    }
    return res;

    }
};




    


// Using DFS
class Solution {
public:

    vector<int> color;
    vector<bool> visited;
    bool bipartite = true;

    void dfs(int cur, vector<vector<int>>& graph, int col)
    {
        visited[cur] = true;
        color[cur] = col;

        for (auto x : graph[cur])
        {
            if (!visited[x]) {
                dfs(x, graph, 3 - col);
            }
            else {
                if (color[x] == col)
                {
                    bipartite = false;
                }
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {

        // Graph is not bipartite if and ony if it contains a cycle of odd length

        int n = graph.size();
        color.resize(n), visited.resize(n);

        int col = 1;
        for (int i = 0; i < n; i++)
        {
            // As graph might have various connected components
            if (!visited[i])
            {
                dfs(i, graph, col);
                if (!bipartite) return false;
            }
        }

        return true;
    }
};
////////////////////////////////////////////////////////////////////////////////////////

// Using BFS
class Solution {
public:

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> visited(n);

        for (int i = 0; i < n; i++)
        {
            if (visited[i]) continue;

            queue<int> q;
            q.push(i);
            visited[i] = 1;

            while (!q.empty())
            {
                auto cur = q.front();
                q.pop();

                for (int nbr : graph[cur])
                {
                    if (!visited[nbr])
                    {
                        visited[nbr] = 3 - visited[cur];    //Assign 2 or 1 to neighbour depending upon curr 
                        q.push(nbr); 
                    }
                    else if (visited[nbr] == visited[cur])
                    {
                        return false;
                    }
                }
            }

        }

        return 1;

    }
};