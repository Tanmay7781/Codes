#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0 && j == 0)
                    continue;
                if (j == 0)
                    continue;

                if (i == 0) {
                    if (p[j - 1] == '*') {
                        dp[i][j] = dp[i][j - 1];
                    }
                    continue;
                }

                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }

                else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }

                else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};