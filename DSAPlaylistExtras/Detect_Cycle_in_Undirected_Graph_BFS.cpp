#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool detectCycle(int src, vector<vector<int>> &adj, vector<int> &visited)
    {
        queue<pair<int, int>> q;
        visited[src] = 1;
        q.push({src, -1});

        while (!q.empty())
        {
            int currNode = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto adjNode : adj[currNode])
            {
                if (!visited[adjNode])
                {
                    visited[adjNode] = 1;
                    q.push({adjNode, currNode});
                }
                else if (parent != adjNode)
                {
                    return true;
                }
            }
        }

        return false;
    }
    bool isCycle(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        vector<int> visited(V, 0);

        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (detectCycle(i, adj, visited) == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
