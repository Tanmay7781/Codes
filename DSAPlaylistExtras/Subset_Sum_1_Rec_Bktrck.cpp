#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{

public:
    void func(int idx, int sum, vector<int> &arr, vector<int> &SumSubset, int N)
    {
        if (idx == N)
        {
            SumSubset.push_back(sum);
            return;
        }

        func(idx + 1, sum + arr[idx], arr, SumSubset, N); // pick

        func(idx + 1, sum, arr, SumSubset, N); // not pick
    }

public:
    vector<int> subsetsum(vector<int> &arr, int N)
    {
        vector<int> SumSubset;
        func(0, 0, arr, SumSubset, N);
        sort(SumSubset.begin(), SumSubset.end());
        return SumSubset;
    }
};
