#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        set <int> s;
        unordered_map<int,int> freq;

        for(int x:nums) freq[x]++;

        for(int x:nums) if(freq[x]>n/3) s.insert(x);

        return vector<int>(s.begin(),s.end());
    }
};