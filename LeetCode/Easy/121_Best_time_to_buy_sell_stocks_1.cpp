#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0;
        int profit;
        int minprice = prices[0];

        for (int i = 1; i < prices.size(); i++)
        {
            profit = prices[i] - minprice;

            maxProfit = max(maxProfit, profit);

            minprice = min(minprice, prices[i]);
        }

        return maxProfit;
    }
};