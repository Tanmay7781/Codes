#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<int>> dist(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

        while (!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dist[row][col] = steps;

            for (int i = 0; i < 4; i++)
            {
                int nr = row + dr[i];
                int nc = col + dc[i];

                if (nr < m && nc < n && nr >= 0 && nc >= 0 &&
                    !visited[nr][nc])
                {
                    q.push({{nr, nc}, steps + 1});
                    visited[nr][nc] = 1;
                }
            }
        }

        return dist;
    }
};
