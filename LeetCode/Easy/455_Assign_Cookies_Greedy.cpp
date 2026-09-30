#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m = g.size();
        int n = s.size();

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int j = 0, count = 0, i = 0;

        while (i < m && j<n) {
            if (s[j] >= g[i]) {
                count++;
                i++;
            }
            j++;
            
        }

        return count;
    }
};