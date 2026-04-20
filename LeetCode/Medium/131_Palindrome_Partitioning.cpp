#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        func(0, ans, temp, s);

        return ans;
    }

    void func(int idx, vector<vector<string>>& ans, vector<string>& temp,
              string s) {
        if (idx == s.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            if (IsPalindrome(s, idx, i)) {
                temp.push_back(s.substr(idx, i - idx + 1));
                func(i + 1, ans, temp, s);
                temp.pop_back();
            }
        }
    }

    bool IsPalindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};