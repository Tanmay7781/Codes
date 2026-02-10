#include <string>
using namespace std;

class Solution {
public:
    bool func(int i, int j, string& s) {
        if (i >= j)
            return true;

        if (s[i] != s[j])
            return false;

        return func(i + 1, j - 1, s);
    }

    bool isPalindrome(string s) {

        string clean = "";

        for (char c : s) {
            if (isalnum(c)) {
                clean += tolower(c);
            }
        }

        return func(0, clean.size() - 1, clean);
    }
};