//Leetcode - Search Insert Position - Easy
//https://leetcode.com/problems/search-insert-position/description/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int l  = 0;
        int r = nums.size()-1;
        int mid = (l+r)/2;
        while(l<=r)
        {
            
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]<target)
            {
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
            mid = (l+r)/2;
        }
        if(mid == 0 && target<nums[0])
        {
            return 0;
        }
        return mid+1;
        
    }
};
