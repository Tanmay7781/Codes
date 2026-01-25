#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> rotateElements(vector<int> &nums, int k)
    {
        vector<int> p;
        vector<int> idx;
        vector<int> temp;

        if (k == 0)
            return nums;

        if (nums.size() == 1)
            return nums;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= 0)
            {
                idx.push_back(i);
                p.push_back(nums[i]);
            }
        }

        int n = p.size();

        if (n == 0)
            return nums;

        k %= n;

        for (int i = 0; i < k; i++)
        {
            temp.push_back(p[i]);
        }

        for (int i = k; i < p.size(); i++)
        {
            p[i - k] = p[i];
        }

        for (int i = 0; i < k; i++)
        {
            p[p.size() - k + i] = temp[i];
        }

        for (int i = 0; i < idx.size(); i++)
        {
            nums[idx[i]] = p[i];
        }

        return nums;
    }
};