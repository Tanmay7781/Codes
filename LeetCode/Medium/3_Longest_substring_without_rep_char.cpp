#include <set>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int l = 0, maxLen = 0;

        for (int r = 0; r < s.size(); r++) {
            while (st.count(s[r])) {
                st.erase(s[l]);
                l++;
            }

            st.insert(s[r]);
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};