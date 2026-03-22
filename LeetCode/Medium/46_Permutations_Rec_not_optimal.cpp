#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void permuteGenerate(vector<int>& nums, vector<int>& ds,
                         vector<vector<int>>& res, vector<bool>& visited) {
        if (ds.size() == nums.size()) {
            res.push_back(ds);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!visited[i]) {
                visited[i] = true;
                ds.push_back(nums[i]);
                permuteGenerate(nums, ds, res, visited);
                ds.pop_back();
                visited[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        vector<bool> visited(nums.size(), false);

        permuteGenerate(nums, ds, res, visited);

        return res;
    }
};
