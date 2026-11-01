#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int preend = INT_MIN;
        int n = intervals.size();
        int rmi = 0;

        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &a, const vector<int> &b)
             {
                 return a[1] < b[1];
             });

        for (int i = 0; i < n; i++)
        {
            if (intervals[i][0] >= preend)
            {
                preend = intervals[i][1];
            }
            else
            {
                rmi++;
            }
        }

        return rmi;
    }
};