#include <vector>
using namespace std;

class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &visited, vector<int> &res)
    {

        visited[node] = 1;
        res.push_back(node);

        for (auto neighbour : adj[node])
        {
            if (!visited[neighbour])
            {
                dfs(neighbour, adj, visited, res);
            }
        }
    }
    vector<int> dfs(vector<vector<int>> &adj)
    {
        vector<int> visited(adj.size(), 0);
        vector<int> res;

        dfs(0, adj, visited, res);

        return res;
    }
};
