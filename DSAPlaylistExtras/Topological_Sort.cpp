#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    void dfs(int src, vector<vector<int>> &adj, vector<int> &visited, stack<int> &st)
    {
        visited[src] = 1;

        for (auto it : adj[src])
        {
            if (!visited[it])
            {
                dfs(it, adj, visited, st);
            }
        }

        st.push(src);
    }

    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        vector<int> visited(V, 0);
        vector<int> ans;
        stack<int> st;

        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited, st);
            }
        }

        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
