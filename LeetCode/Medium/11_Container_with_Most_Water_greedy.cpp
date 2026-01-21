#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size() - 1;
        int area = 0, curr;
        int l = 0;
        int r = n;

        while (l < r) {

            curr = (r - l) * min(height[l], height[r]);

            area = max(area, curr);

            if (height[l] < height[r])
                l++;
            else
                r--;
        }

        return area;
    }
};