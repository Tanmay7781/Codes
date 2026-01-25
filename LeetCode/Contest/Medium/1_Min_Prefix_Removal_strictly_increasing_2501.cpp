#include <vector>
using namespace std;

class Solution
{
public:
    int minimumPrefixLength(vector<int> &nums)
    {
        int n = nums.size();
        int count = n - 1;

        for (int i = n - 1; i > 0; i--)
        {
            if (nums[i] > nums[i - 1])
            {
                count = i - 1;
            }

            else
            {
                break;
            }
        }

        return count;
    }
};