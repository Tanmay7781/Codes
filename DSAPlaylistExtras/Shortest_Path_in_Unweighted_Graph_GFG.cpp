#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest)
    {
        vector<vector<int>> adj(V);
        vector<int> visited(V, 0);
        queue<int> q;

        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        q.push(src);
        visited[src] = 1;
        int dist = 0;

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                int curr = q.front();
                q.pop();

                if (curr == dest)
                {
                    return dist;
                }

                for (auto it : adj[curr])
                {
                    if (!visited[it])
                    {
                        q.push(it);
                        visited[it] = 1;
                    }
                }
            }
            dist++;
        }

        return -1;
    }
};
