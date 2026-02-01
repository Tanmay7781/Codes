#include <set>
#include <string>
using namespace std;

class Solution
{
public:
    int maxDistinct(string s)
    {
        set<int> st;

        for (char x : s)
        {
            st.insert(x);
        }

        return st.size();
    }
};