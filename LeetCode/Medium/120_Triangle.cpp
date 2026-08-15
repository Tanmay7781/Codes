#include <vector>
using namespace std;

// memoization
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

// tabulation
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; i++)
        {
            dp[i].resize(triangle[i].size(), INT_MAX);
        }

        for (int j = 0; j < n; j++)
        {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }

        return dp[0][0];
    }
};

// space optimisation
