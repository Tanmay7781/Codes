#include <vector>
#include<algorithm>
#include <string>
using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<char> t1;
        vector<char> t2;

        for (char x : s) {
            t1.push_back(x);
        }

        for (char x : t) {
            t2.push_back(x);
        }

        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());

        if (t1 == t2) {
            return true;
        }

        return false;
    }
};