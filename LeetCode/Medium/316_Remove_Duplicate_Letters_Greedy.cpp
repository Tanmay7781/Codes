#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        vector<int> lastidx(26, -1);
        vector<bool> seen(26, false);
        stack<char> st;
        string res = "";

        for (int i = 0; i < s.size(); i++)
        {
            lastidx[s[i] - 'a'] = i;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (seen[s[i] - 'a'])
                continue;

            while (!st.empty() && s[i] < st.top() &&
                   i < lastidx[st.top() - 'a'])
            {
                seen[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(s[i]);
            seen[s[i] - 'a'] = true;
        }

        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};