#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
    {
        vector<int> dist(V, 1e8);
        dist[src] = 0;

        for (int i = 0; i < V; i++)
        {
            for (int k = 0; k < edges.size(); k++)
            {
                int u = edges[k][0];
                int v = edges[k][1];
                int wt = edges[k][2];

                if (dist[u] != 1e8 && dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        for (int k = 0; k < edges.size(); k++)
        {
            int u = edges[k][0];
            int v = edges[k][1];
            int wt = edges[k][2];

            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
                return {-1};
            }
        }

        return dist;
    }
};
