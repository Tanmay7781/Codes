#include <vector>
#include <algorithm>
using namespace std;

class Solution {
	public:
	int activitySelection(vector<int> &start, vector<int> &finish) {
		int n = start.size();
		int activity = 0;
		int end = -1;
		
		vector<pair<int, int>> activities;
		
		for (int i = 0; i<n; i++) {
			activities.push_back({finish[i], start[i]});
		}
		
		sort(activities.begin(), activities.end());
		
		for (int i = 0; i<n; i++) {
			if (activities[i].second>end) {
				activity++;
				end = activities[i].first;
			}
		}
		
		return activity;
		
	}
};