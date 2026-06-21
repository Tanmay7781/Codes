#include <vector>
using namespace std;

class Solution
{
public:
    bool detectCycle(int src, vector<vector<int>> &adj, vector<int> &visited, vector<int> &path_visited)
    {
        visited[src] = 1;
        path_visited[src] = 1;

        for (auto neighbour : adj[src])
        {
            if (!visited[neighbour])
            {
                if (detectCycle(neighbour, adj, visited, path_visited) == true)
                {
                    return true;
                }
            }

            else if (path_visited[neighbour] == 1)
            {
                return true;
            }
        }

        path_visited[src] = 0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(V);
        vector<int> visited(V, 0);
        vector<int> path_visited(V, 0);

        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
        }

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (detectCycle(i, adj, visited, path_visited) == true)
                {
                    return true;
                }
            }
        }

        return false;
    }
};
