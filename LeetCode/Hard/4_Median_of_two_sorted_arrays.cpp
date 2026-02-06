#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1 = nums1.size();
        int s2 = nums2.size();

        vector<int> res(s1 + s2);

        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(),
              res.begin());

        sort(res.begin(), res.end());

        int size = res.size();

        if (size % 2 == 1) {
            return res[size / 2];
        } else {
            return (res[size / 2 - 1] + res[size / 2]) / 2.0;
        }
    }
};