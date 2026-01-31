#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string reverseByType(string s)
    {
        vector<int> spclidx;
        vector<int> alphidx;
        string alph = "";
        string spcl = "";

        string res(s.size(), 'a');

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] < 97 || s[i] > 122)
            {
                spcl += s[i];
                spclidx.push_back(i);
            }

            else
            {
                alph += s[i];
                alphidx.push_back(i);
            }
        }

        reverse(spcl.begin(), spcl.end());
        reverse(alph.begin(), alph.end());

        for (int i = 0; i < alphidx.size(); i++)
        {
            res[alphidx[i]] = alph[i];
        }

        for (int i = 0; i < spclidx.size(); i++)
        {
            res[spclidx[i]] = spcl[i];
        }

        return res;
    }
};