#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int maxReach = 0;
        int currEnd = 0;
        int jumps = 0;

        for(int i=0;i<nums.size()-1;i++)
        {
            maxReach = max(maxReach,i+nums[i]);

            if(i==currEnd)
            {
                jumps++;
                currEnd = maxReach;
            }
        }

        return jumps;
    }
};