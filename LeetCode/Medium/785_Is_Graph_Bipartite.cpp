#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> colored(n, -1);
        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (colored[i] == -1)
            {
                colored[i] = 0;
                q.push(i);
            }

            while (!q.empty())
            {
                int node = q.front();
                q.pop();

                for (auto neighbour : graph[node])
                {
                    if (colored[neighbour] == -1)
                    {
                        colored[neighbour] = !colored[node];
                        q.push(neighbour);
                    }
                    else if (colored[node] == colored[neighbour])
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
