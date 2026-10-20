#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (maxReach >= i) {
                maxReach = max(maxReach, i + nums[i]);
            }
        }

        return (maxReach >= n - 1);
    }
};