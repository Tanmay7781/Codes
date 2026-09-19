#include <vector>
using namespace std;

class Solution
{
public:
    int f(int ind, int buy, int tr, vector<int> &prices,
          vector<vector<vector<int>>> &dp)
    {
        int n = prices.size();
        if (ind == n)
            return 0;

        if (tr == 2)
            return 0;

        if (dp[ind][buy][tr] != -1)
            return dp[ind][buy][tr];

        int profit = 0;

        if (buy)
        {
            profit = max(-prices[ind] + f(ind + 1, 0, tr, prices, dp),
                         f(ind + 1, 1, tr, prices, dp));
        }
        else
        {
            profit = max(prices[ind] + f(ind + 1, 1, tr + 1, prices, dp),
                         f(ind + 1, 0, tr, prices, dp));
        }

        return dp[ind][buy][tr] = profit;
    }

    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 1, 0, prices, dp);
    }
};