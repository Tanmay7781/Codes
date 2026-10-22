#include <vector>
using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return 0;
        int maxReach = 0;
        int currentEnd = 0;
        int jumps = 0;

        for (int i = 0; i < n; i++) {
            maxReach = max(maxReach, i + nums[i]);

            if (i == currentEnd) {
                jumps++;
                currentEnd = maxReach;
            }

            if (currentEnd >= n - 1)
                break;
        }

        return jumps;
    }
};