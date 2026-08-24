#include <vector>
using namespace std;

// memoization
class Solution
{
public:
    int f(int ind, int T, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (T == 0)
            return 1;
        if (ind == 0)
        {
            if (coins[ind] == T)
                return 1;
            return 0;
        }
        if (dp[ind][T] != -1)
            return dp[ind][T];

        int notPick = f(ind - 1, T, coins, dp);
        int pick = 0;
        if (coins[ind] <= T)
            pick = f(ind, T - coins[ind], coins, dp);

        return dp[ind][T] = pick + notPick;
    }

    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = f(n - 1, amount, coins, dp);

        return (ans) ? ans : 0;
    }
};