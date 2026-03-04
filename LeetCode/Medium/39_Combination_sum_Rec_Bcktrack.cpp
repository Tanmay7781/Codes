#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void checkcsum(int idx, vector<int>& candidates, int target,
                   vector<vector<int>>& res, vector<int>& ds) {
        if (idx == candidates.size()) {
            if (target == 0) {
                res.push_back(ds);
            }
            return;
        }

        if (candidates[idx] <= target) {
            ds.push_back(candidates[idx]);
            checkcsum(idx, candidates, target - candidates[idx], res, ds);
            ds.pop_back();
        }
        checkcsum(idx + 1, candidates, target, res, ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ds;

        checkcsum(0, candidates, target, res, ds);

        return res;
    }
};