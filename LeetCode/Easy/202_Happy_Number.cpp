#include <unordered_set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        if(n<0) return false;

        unordered_set<int> seen;

        long long a,b;
        b=(long long) n;

        while(b!=1 && !seen.count(b))
        {   
            seen.insert(b);
            long long d=0;
            while(b>0)
            {
                a=b%10;
                b=b/10;
                d=d+(a*a);
            }
            b=d;
        
        }

        return b==1;
    
    }
};