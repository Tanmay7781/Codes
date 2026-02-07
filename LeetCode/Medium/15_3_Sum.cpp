#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }

                else if (sum < 0) {
                    l++;
                }

                else {
                    r--;
                }
            }
        }

        return res;
    }
};