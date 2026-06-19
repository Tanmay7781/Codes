#include <utility>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    void bfs(vector<vector<int>> &grid, queue<pair<int, int>> &q, int dr[],
             int dc[], int &time)
    {
        int m = grid.size();
        int n = grid[0].size();

        while (!q.empty())
        {
            int k = q.size();
            bool changed = false;
            for (int i = 0; i < k; i++)
            {
                pair<int, int> curr = q.front();
                q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int nr = curr.first + dr[i];
                    int nc = curr.second + dc[i];

                    if (nr >= 0 && nc >= 0 && nr < m && nc < n &&
                        grid[nr][nc] == 1)
                    {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                        changed = true;
                    }
                }
            }
            if (changed)
            {
                time++;
            }
        }
    }
    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        int time = 0;
        int countaf = 0;
        int m = grid.size();
        int n = grid[0].size();
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }
        bfs(grid, q, dr, dc, time);

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    countaf++;
                }
            }
        }

        if (countaf == 0)
        {
            return time;
        }

        else
        {
            return -1;
        }
    }
};