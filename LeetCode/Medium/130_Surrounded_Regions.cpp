#include <vector>
using namespace std;

class Solution
{
public:
    void dfs(pair<int, int> rc, vector<vector<char>> &board,
             vector<vector<int>> &visited)
    {
        int row = rc.first;
        int col = rc.second;
        int m = board.size();
        int n = board[0].size();
        visited[row][col] = 1;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int nr = row + dr[i];
            int nc = col + dc[i];

            if (nr >= 0 && nc >= 0 && nr < m && nc < n && !visited[nr][nc] &&
                board[nr][nc] == 'O')
            {
                dfs({nr, nc}, board, visited);
            }
        }
    }
    void solve(vector<vector<char>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1)
                {
                    if (board[i][j] == 'O' && !visited[i][j])
                    {
                        dfs({i, j}, board, visited);
                    }
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visited[i][j] && board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};