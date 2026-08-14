#include <vector>
using namespace std;

class Solution
{
public:
    int f(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp)
    {
        int size = triangle.size();

        if (i == size - 1)
            return triangle[i][j];
        if (dp[i][j] != INT_MAX)
            return dp[i][j];

        int path_sum = triangle[i][j] + min(f(i + 1, j, triangle, dp), f(i + 1, j + 1, triangle, dp));

        return dp[i][j] = path_sum;
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {
        vector<vector<int>> dp(triangle.size());
        for (int i = 0; i < triangle.size(); i++)
        {
            dp[i].resize(triangle[i].size(), INT_MAX);
        }
        return f(0, 0, triangle, dp);
    }
};