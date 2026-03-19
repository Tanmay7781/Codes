#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void func(int idx, int n, vector<int>& ds, vector<int>& nums,
              vector<vector<int>>& res) {
        if (idx == n) {
            res.push_back(ds);
            return;
        }

        ds.push_back(nums[idx]);
        func(idx + 1, n, ds, nums, res);

        ds.pop_back();
        func(idx + 1, n, ds, nums, res);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;

        func(0, nums.size(), ds, nums, res);

        return res;
    }
};