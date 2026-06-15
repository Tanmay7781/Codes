#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    void bfs(pair<int, int> p, vector<vector<char>> &grid, vector<vector<int>> &visited)
    {
        queue<pair<int, int>> q;
        int i = p.first;
        int j = p.second;
        q.push({i, j});
        visited[i][j] = 1;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        while (!q.empty())
        {
            pair<int, int> curr = q.front();
            q.pop();

            int row = curr.first;
            int col = curr.second;

            for (int k = 0; k < 4; k++)
            {
                int nr = row + dr[k];
                int nc = col + dc[k];

                if (nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size())
                {
                    if (!visited[nr][nc] && grid[nr][nc] == '1')
                    {
                        q.push({nr, nc});
                        visited[nr][nc] = 1;
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    count++;
                    bfs({i, j}, grid, visited);
                }
            }
        }

        return count;
    }
};