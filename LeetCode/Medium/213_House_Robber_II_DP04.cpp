#include <vector>
using namespace std;

//memoization+recursive
class Solution
{
public:
    int maxSum(int idx, int start, int end, vector<int> &nums,
               vector<int> &dp)
    {
        if (idx < start)
            return 0;
        if (idx == start)
            return nums[idx];

        if (dp[idx] != -1)
            return dp[idx];

        int pick = nums[idx] + maxSum(idx - 2, start, end, nums, dp);
        int notPick = 0 + maxSum(idx - 1, start, end, nums, dp);

        return dp[idx] = max(pick, notPick);
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        if (n == 1)
            return nums[0];

        return max(maxSum(n - 2, 0, n - 2, nums, dp1),
                   maxSum(n - 1, 1, n - 1, nums, dp2));
    }
};

//tabulation+spaceoptimization

