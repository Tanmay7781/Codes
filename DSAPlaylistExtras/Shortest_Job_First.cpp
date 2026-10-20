#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:
	int solve(vector<int>& bt) {
		int currentTime = 0;
		int totalWaitingTime = 0;
		int n = bt.size();
		
		sort(bt.begin(), bt.end());
		
		for (int i = 0; i<n; i++) {
			if (i<n - 1) {
				currentTime += bt[i];
				totalWaitingTime += currentTime;
			}
		}
		
		int avgWaitTime = totalWaitingTime/n;
		
		return avgWaitTime;
	}
};
