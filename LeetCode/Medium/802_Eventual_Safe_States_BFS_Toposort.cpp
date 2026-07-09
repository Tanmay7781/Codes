#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int V = graph.size();
        vector<int> inDegree(V, 0);
        vector<vector<int>> RevGraph(V);
        queue<int> q;
        vector<int> ans;

        for (int i = 0; i < graph.size(); i++)
        {
            for (auto it : graph[i])
            {
                RevGraph[it].push_back(i);
                inDegree[i]++;
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            for (auto neighbour : RevGraph[curr])
            {
                inDegree[neighbour]--;
                if (inDegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (inDegree[i] == 0)
            {
                ans.push_back(i);
            }
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};