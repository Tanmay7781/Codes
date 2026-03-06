#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void checkcsum(int idx, vector<int>& candidates, int target,
                   vector<int>& ds, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(ds);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;

            if (target < candidates[i])
                break;

            ds.push_back(candidates[i]);
            checkcsum(i + 1, candidates, target - candidates[i], ds, res);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ds;

        sort(candidates.begin(), candidates.end());

        checkcsum(0, candidates, target, ds, res);

        return res;
    }
};