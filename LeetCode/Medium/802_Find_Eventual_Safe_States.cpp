#include <vector>
using namespace std;

class Solution
{
public:
    bool dfs(int src, vector<vector<int>> &graph, vector<int> &visited,
             vector<int> &pathVisited, vector<int> &check)
    {
        visited[src] = 1;
        pathVisited[src] = 1;

        for (auto neighbour : graph[src])
        {
            if (!visited[neighbour])
            {
                if (dfs(neighbour, graph, visited, pathVisited, check) ==
                    true)
                {
                    return true;
                }
            }
            else if (pathVisited[neighbour] == 1)
            {
                return true;
            }
        }

        check[src] = 1;
        pathVisited[src] = 0;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int V = graph.size();
        vector<int> visited(V, 0);
        vector<int> pathVisited(V, 0);
        vector<int> check(V, 0);
        vector<int> ans;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                dfs(i, graph, visited, pathVisited, check);
            }
        }

        for (int i = 0; i < V; i++)
        {
            if (check[i] == 1)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};