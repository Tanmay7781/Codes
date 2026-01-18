#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int lastIndex = nums.size() - 1;

        for (int i = 0; i < nums.size(); i++) {
            if (i > maxReach)
                return false;

            if (maxReach >= i) {
                maxReach = max(maxReach, i + nums[i]);
            }
        }

        if (maxReach >= lastIndex)
            return true;

        return false;
    }
};