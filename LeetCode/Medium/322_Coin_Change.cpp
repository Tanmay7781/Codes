#include <vector>
using namespace std;

// memoization
class Solution
{
public:
    int f(int ind, int T, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if (T % coins[ind] == 0)
                return T / coins[ind];
            return 1e9;
        }
        if (dp[ind][T] != -1)
            return dp[ind][T];
        int notTake = f(ind - 1, T, coins, dp);
        int take = 1e9;
        if (coins[ind] <= T)
            take = 1 + f(ind, T - coins[ind], coins, dp);

        return dp[ind][T] = min(take, notTake);
    }

    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = f(n - 1, amount, coins, dp);
        return (ans >= 1e9) ? -1 : ans;
    }
};

// tabulation
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int T = 0; T <= amount; T++)
        {
            if (T % coins[0] == 0)
                dp[0][T] = T / coins[0];
            else
                dp[0][T] = 1e9;
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int T = 0; T <= amount; T++)
            {
                int notTake = dp[ind - 1][T];
                int take = 1e9;
                if (coins[ind] <= T)
                    take = 1 + dp[ind][T - coins[ind]];

                dp[ind][T] = min(take, notTake);
            }
        }

        return (dp[n - 1][amount] >= 1e9) ? -1 : dp[n - 1][amount];
    }
};

// tabulation + space optimisation
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        vector<int> prev(amount + 1, 0), cur(amount + 1, 0);

        for (int T = 0; T <= amount; T++)
        {
            if (T % coins[0] == 0)
                prev[T] = T / coins[0];
            else
                prev[T] = 1e9;
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int T = 0; T <= amount; T++)
            {
                int notTake = prev[T];
                int take = 1e9;
                if (coins[ind] <= T)
                    take = 1 + cur[T - coins[ind]];

                cur[T] = min(take, notTake);
            }
            prev = cur;
        }

        return (prev[amount] >= 1e9) ? -1 : prev[amount];
    }
};