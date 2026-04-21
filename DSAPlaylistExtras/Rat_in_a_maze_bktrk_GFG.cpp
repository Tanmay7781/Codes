#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    void func(int i, int j, vector<string> &ans, vector<vector<int>> &maze, int n, vector<vector<int>> &vis, string move)
    {
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(move);
            return;
        }

        // downwards
        if (i + 1 < n && !vis[i + 1][j] && maze[i + 1][j] == 1)
        {
            vis[i][j] = 1;
            func(i + 1, j, ans, maze, n, vis, move + 'D');
            vis[i][j] = 0;
        }

        // left
        if (j - 1 >= 0 && !vis[i][j - 1] && maze[i][j - 1] == 1)
        {
            vis[i][j] = 1;
            func(i, j - 1, ans, maze, n, vis, move + 'L');
            vis[i][j] = 0;
        }

        // right
        if (j + 1 < n && !vis[i][j + 1] && maze[i][j + 1] == 1)
        {
            vis[i][j] = 1;
            func(i, j + 1, ans, maze, n, vis, move + 'R');
            vis[i][j] = 0;
        }

        // upwards
        if (i - 1 >= 0 && !vis[i - 1][j] && maze[i - 1][j] == 1)
        {
            vis[i][j] = 1;
            func(i - 1, j, ans, maze, n, vis, move + 'U');
            vis[i][j] = 0;
        }
    }

    vector<string> ratInMaze(vector<vector<int>> &maze)
    {
        int n = maze.size();

        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        if (maze[0][0] == 1)
            func(0, 0, ans, maze, n, vis, "");

        return ans;
    }
};