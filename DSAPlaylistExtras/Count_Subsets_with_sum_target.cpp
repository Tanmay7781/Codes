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

// tabulation

class Solution
{
public:
    int perfectSum(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        dp[0][0] = (arr[0] == 0) ? 2 : 1;

        if (arr[0] != 0 && arr[0] <= target)
            dp[0][arr[0]] = 1;

        for (int ind = 1; ind < n; ind++)
        {
            for (int sum = 0; sum <= target; sum++)
            {

                int notPick = dp[ind - 1][sum];
                int pick = 0;
                if (arr[ind] <= sum)
                    pick = dp[ind - 1][sum - arr[ind]];

                dp[ind][sum] = pick + notPick;
            }
        }

        return dp[n - 1][target];
    }
};

// space-optimisation

class Solution
{
public:
    int perfectSum(vector<int> &arr, int target)
    {
        int n = arr.size();
        vector<int> prev(target + 1, 0), cur(target + 1, 0);

        prev[0] = (arr[0] == 0) ? 2 : 1;

        if (arr[0] != 0 && arr[0] <= target)
            prev[arr[0]] = 1;

        for (int ind = 1; ind < n; ind++)
        {
            for (int sum = 0; sum <= target; sum++)
            {

                int notPick = prev[sum];
                int pick = 0;
                if (arr[ind] <= sum)
                    pick = prev[sum - arr[ind]];

                cur[sum] = pick + notPick;
            }
            prev = cur;
        }

        return prev[target];
    }
};
