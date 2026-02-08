#include <vector>
using namespace std;


class Solution {
public:
    int dominantIndices(vector<int>& nums) {

        int totalSum = 0;
        int avgSum;
        int currSize;

        for (int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
        }

        int count = 0;
        int prefixSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            avgSum = totalSum - prefixSum - nums[i];
            currSize = nums.size() - i - 1;

            if (i != nums.size() - 1) {
                double avg = (double)avgSum / currSize;
                if (nums[i] > avg) {
                    count++;
                }
            }
            prefixSum += nums[i];
        }

        return count;
    }
};