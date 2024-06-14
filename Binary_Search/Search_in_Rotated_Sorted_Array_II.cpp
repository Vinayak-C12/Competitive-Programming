//Leetcode - Search in Rotated Sorted Array II - Medium - Striver
//https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int l=0,r = n-1;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[mid] == target)
            {
                return true;
            }
            if(nums[l] == nums[mid] && nums[mid] == nums[r]) // Edge case due to the presence of duplicates.Since nums[l] or nums[r] or nums[mid] is not the target just remove them from the search space in the sense skip them and move forward
            {
                l++;
                r--;
                continue;
            }
            if(nums[mid]>=nums[l]) // Position of mid is in left sorted array
            {
                if(target>=nums[l] && target<=nums[mid]) // If the target is in between l and mid
                {
                    r = mid-1;
                }
                else // If not target is to the right
                {
                    l = mid+1;
                }
            }
            else // Position of mid is in right sorted array
            {
                if(target>=nums[mid] && target<=nums[r]) // If the target is in between mid and r
                {
                    l = mid+1;
                }
                else // If not then target is to the left
                {
                    r = mid-1;
                }
            }
        }
        return false;
    }
};
