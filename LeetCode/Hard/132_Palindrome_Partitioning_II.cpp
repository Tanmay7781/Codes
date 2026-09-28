#include <vector>
#include <string>
using namespace std;

// memoization
class Solution
{
public:
    int f(int i, string &s, vector<int> &dp)
    {
        int n = s.size();
        if (i == n)
            return 0;
        if (dp[i] != -1)
            return dp[i];

        int mini = INT_MAX;
        string temp = "";

        for (int j = i; j < n; j++)
        {
            temp += s[j];
            if (isPalindrome(temp))
            {
                int cost = 1 + f(j + 1, s, dp);
                mini = min(mini, cost);
            }
        }

        return dp[i] = mini;
    }

    bool isPalindrome(string &str)
    {
        int n = str.size();
        int i = 0, j = n - 1;

        while (i <= j)
        {
            if (str[i] != str[j])
            {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    int minCut(string s)
    {
        int n = s.size();
        vector<int> dp(n, -1);
        return f(0, s, dp) - 1;
    }
};

// tabulation

class Solution
{
public:
    bool isPalindrome(string &str)
    {
        int n = str.size();
        int i = 0, j = n - 1;

        while (i <= j)
        {
            if (str[i] != str[j])
            {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    int minCut(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            string temp = "";
            int mini = INT_MAX;
            for (int j = i; j < n; j++)
            {
                temp += s[j];
                if (isPalindrome(temp))
                {
                    int cost = 1 + dp[j + 1];
                    mini = min(mini, cost);
                }
            }
            dp[i] = mini;
        }
        return dp[0] - 1;
    }
};