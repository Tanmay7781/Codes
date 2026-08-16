#include <vector>
using namespace std;

class Solution
{
public:
    bool f(int ind, int target, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;
        if (ind == 0)
            return (target == nums[ind]);

        if (dp[ind][target] != -1)
            return dp[ind][target];

        bool notPick = f(ind - 1, target, nums, dp);
        bool pick = false;
        if (nums[ind] <= target)
            pick = f(ind - 1, target - nums[ind], nums, dp);

        return dp[ind][target] = pick || notPick;
    }

    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();
        int totalSum = 0;

        for (int x : nums)
            totalSum += x;

        if (totalSum % 2)
            return false;
        int target = totalSum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return f(n - 1, target, nums, dp);
    }
};