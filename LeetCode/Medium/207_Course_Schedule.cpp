#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        int V = numCourses;
        int m = prerequisites.size();
        vector<vector<int>> adj(V);
        vector<int> ans;
        vector<int> inDegree(V, 0);
        queue<int> q;

        for (int i = 0; i < m; i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for (int i = 0; i < adj.size(); i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                inDegree[adj[i][j]]++;
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
            ans.push_back(curr);

            for (auto neighbour : adj[curr])
            {
                inDegree[neighbour]--;
                if (inDegree[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }
        }

        if (ans.size() == V)
            return true;

        return false;
    }
};