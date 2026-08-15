#include <vector>
using namespace std;

// memoization
class Solution
{
public:
    bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (target == 0)
            return true;
        if (ind == 0)
            return (arr[ind] == target);

        if (dp[ind][target] != -1)
            return dp[ind][target];

        bool notTake = f(ind - 1, target, arr, dp);
        bool take = false;
        if (target >= arr[ind])
            take = f(ind - 1, target - arr[ind], arr, dp);

        return dp[ind][target] = take || notTake;
    }

    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        return f(n - 1, sum, arr, dp);
    }
};

// tabulation
class Solution
{
public:
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, 0));

        for (int i = 0; i < n; i++)
            dp[i][0] = true;
        dp[0][arr[0]] = true;

        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 1; target <= sum; target++)
            {
                bool notTake = dp[ind - 1][target];
                bool take = false;
                if (target >= arr[ind])
                    take = dp[ind - 1][target - arr[ind]];
                dp[ind][target] = take || notTake;
            }
        }

        return dp[n - 1][sum];
    }
};

//space optimization

