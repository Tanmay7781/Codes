#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> freq;
        int res;

        for (int x : nums)
            freq[x]++;

        for (int i = 1; i <= nums.size(); i++) {
            if (freq[i] == 0) {
                return i;
            }
        }

        return nums.size() + 1;
    }
};