#include <vector>
using namespace std;

// memoization
class Solution
{
public:
    int f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
    {

        if (ind == 0)
        {
            if (target == 0 && arr[0] == 0)
                return 2;
            if (target == 0 || target == arr[0])
                return 1;
            return 0;
        }

        if (dp[ind][target] != -1)
            return dp[ind][target];

        int notPick = f(ind - 1, target, arr, dp);
        int pick = 0;
        if (arr[ind] <= target)
            pick = f(ind - 1, target - arr[ind], arr, dp);

        return dp[ind][target] = pick + notPick;
    }

    int perfectSum(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return f(n - 1, target, arr, dp);
    }
};
