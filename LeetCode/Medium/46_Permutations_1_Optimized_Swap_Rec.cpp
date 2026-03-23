#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void findPermute(int idx, vector<int>& nums, vector<vector<int>>& res) {
        if (idx == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            findPermute(idx + 1, nums, res);
            swap(nums[idx], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        findPermute(0, nums, res);
        return res;
    }
};