#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    void dfs(int node, vector<vector<pair<int, int>>> &adj, stack<int> &st, vector<int> &visited)
    {
        visited[node] = 1;

        for (auto it : adj[node])
        {
            int neighbour = it.first;

            if (!visited[neighbour])
            {
                dfs(neighbour, adj, st, visited);
            }
        }

        st.push(node);
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adj(V);
        vector<int> dist(V, INT_MAX);
        vector<int> visited(V, 0);
        stack<int> st;

        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }

        dist[0] = 0;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, st, visited);
            }
        }

        while (!st.empty())
        {
            int curr = st.top();
            st.pop();

            if (dist[curr] == INT_MAX)
                continue;

            for (auto it : adj[curr])
            {
                int nbr = it.first;
                int wt = it.second;

                if (dist[curr] + wt < dist[nbr])
                {
                    dist[nbr] = dist[curr] + wt;
                }
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (dist[i] == INT_MAX)
            {
                dist[i] = -1;
            }
        }

        return dist;
    }
};
