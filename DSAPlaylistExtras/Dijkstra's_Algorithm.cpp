#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        vector<vector<pair<int, int>>> adj(V);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;

        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }

        pq.push({0, src});

        while (!pq.empty())
        {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            for (auto it : adj[u])
            {
                int v = it.first;
                int wt = it.second;
                if (d + wt < dist[v])
                {
                    dist[v] = d + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
};
