#include <vector>
using namespace std;

class Solution
{
public:
    void dfs(int node, vector<int> &visited, vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        visited[node] = 1;

        for (int i = 0; i < n; i++)
        {
            if (isConnected[node][i] == 1 && !visited[i])
            {
                dfs(i, visited, isConnected);
            }
        }
    }

    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int v = isConnected.size();
        int count = 0;
        vector<int> visited(v, 0);

        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                dfs(i, visited, isConnected);
                count++;
            }
        }

        return count;
    }
};