#include <vector>
using namespace std;

//memoization-recursive
class Solution {
public:
    int maxSum(int idx, vector<int>& nums, vector<int>& dp) {
        if (idx == 0)
            return nums[idx];
        if (idx < 0)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int pick = nums[idx] + maxSum(idx - 2, nums, dp);
        int notPick = 0 + maxSum(idx - 1, nums, dp);

        return dp[idx] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);

        return maxSum(n - 1, nums, dp);
    }
};

//tabulation
