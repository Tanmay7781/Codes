#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adj(V);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> visited(V, 0);
        int mstWeight = 0;
        pq.push({0, 0});

        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }

        while (!pq.empty())
        {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (visited[node] == 1)
                continue;
            visited[node] = 1;
            mstWeight += wt;

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edgeWt = it.second;

                if (!visited[adjNode])
                {
                    pq.push({edgeWt, adjNode});
                }
            }
        }

        return mstWeight;
    }
};
