#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> idx;
        vector<int> res;

        int first = firstocc(nums, idx, target);
        int last = lastocc(nums, idx, target);

        res.push_back(first);
        res.push_back(last);

        return res;
    }

    int firstocc(vector<int>& nums, vector<int>& idx, int target) {
        int l = 0, h = nums.size() - 1, mid, f = -1;
        while (l <= h) {
            mid = (l + h) / 2;
            if (target == nums[mid]) {
                f = mid;
                h = mid - 1;
            }

            else if (target < nums[mid]) {
                h = mid - 1;
            }

            else {
                l = mid + 1;
            }
        }

        return f;
    }

    int lastocc(vector<int>& nums, vector<int>& idx, int target) {
        int l = 0, h = nums.size() - 1, mid, ls = -1;
        while (l <= h) {
            mid = (l + h) / 2;
            if (target == nums[mid]) {
                ls = mid;
                l = mid + 1;
            }

            else if (target < nums[mid]) {
                h = mid - 1;
            }

            else {
                l = mid + 1;
            }
        }

        return ls;
    }
};