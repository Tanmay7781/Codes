#include <vector>
using namespace std;

class Solution {
public:
    int modified_bs(vector<int>& nums, int target,int l,int h)
    {
        
        while(l<=h)
        {
            int mid = (l+h)/2;

            if(nums[mid]==target)
            {
                return mid;
            }

            else if(nums[l]<=nums[mid])
            {
                if(nums[l]<=target && target<=nums[mid])
                {
                    h=mid-1;
                }

                else
                {
                    l=mid+1;
                }
            }

            else
            {
                if(nums[mid]<target && target<=nums[h])
                {
                    l=mid+1;
                }

                else
                {
                    h=mid-1;
                }
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1;

        return modified_bs(nums,target,l,h);
        

    }
};