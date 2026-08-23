#include <vector>
using namespace std;

class Solution
{
public:
    int f(int ind, int T, vector<int> &nums, vector<vector<int>> &dp, int sum)
    {
        if (T < -sum || T > sum)
            return 0;
        if (ind == 0)
        {
            int ways = 0;

            if (nums[0] == T)
                ways++;

            if (-nums[0] == T)
                ways++;

            return ways;
        }

        if (dp[ind][T + sum] != -1)
            return dp[ind][T + sum];

        int plus = f(ind - 1, T - nums[ind], nums, dp, sum);
        int minus = f(ind - 1, T + nums[ind], nums, dp, sum);

        return dp[ind][T + sum] = plus + minus;
    }

    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int sum = 0;
        for (int x : nums)
            sum += x;
        if (abs(target) > sum)
            return 0;
        vector<vector<int>> dp(n, vector<int>(2 * sum + 1, -1));

        return f(n - 1, target, nums, dp, sum);
    }
};