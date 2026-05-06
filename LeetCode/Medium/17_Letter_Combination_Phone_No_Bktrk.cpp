#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void traverse(int idx, vector<string>& res, vector<string>& mp,
                  string& digits, string& curr) {
        if (idx == digits.size()) {
            res.push_back(curr);
            return;
        }

        string letters = mp[digits[idx] - '0'];

        for (int i = 0; i < letters.size(); i++) {
            curr.push_back(letters[i]);
            traverse(idx + 1, res, mp, digits, curr);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> mp = {"",    "",    "abc",  "def", "ghi",
                             "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        if (digits.empty())
            return res;
        string curr = "";
        traverse(0, res, mp, digits, curr);
        return res;
    }
};