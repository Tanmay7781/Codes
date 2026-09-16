#include <vector>
#include <string>
using namespace std;

// memoization
class Solution
{
public:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if (i < 0)
            return j + 1;
        if (j < 0)
            return i + 1;
        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j])
            return dp[i][j] = f(i - 1, j - 1, s1, s2, dp);

        return dp[i][j] = 1 + min(f(i - 1, j, s1, s2, dp),
                                  min(f(i, j - 1, s1, s2, dp),
                                      f(i - 1, j - 1, s1, s2, dp)));
    }

    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(m - 1, n - 1, word1, word2, dp);
    }
};

// tabulation
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int j = 0; j <= n; j++)
            dp[0][j] = j;
        for (int i = 0; i <= m; i++)
            dp[i][0] = i;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i - 1][j],
                                       min(dp[i][j - 1], dp[i - 1][j - 1]));
            }
        }
        return dp[m][n];
    }
};

// tabulation + space-optimization

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        vector<int> prev(n + 1, 0), cur(n + 1, 0);

        for (int j = 0; j <= n; j++)
            prev[j] = j;

        for (int i = 1; i <= m; i++)
        {
            cur[0] = i;
            for (int j = 1; j <= n; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    cur[j] = prev[j - 1];
                else
                    cur[j] = 1 + min(prev[j], min(cur[j - 1], prev[j - 1]));
            }
            prev = cur;
        }
        return prev[n];
    }
};