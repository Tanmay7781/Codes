#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> bfs(vector<vector<int>> &adj)
    {
        queue<int> q;
        vector<int> res;
        vector<int> visited(adj.size(), 0);

        q.push(0);
        visited[0] = 1;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            res.push_back(curr);

            for (auto neighbour : adj[curr])
            {
                if (!visited[neighbour])
                {
                    visited[neighbour] = 1;
                    q.push(neighbour);
                }
            }
        }

        return res;
    }
};