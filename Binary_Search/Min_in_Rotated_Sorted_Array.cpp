//Leetcode - Search the Minimum in a rotated sorted array
//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int res = nums[0];
        while(l<=r)
        {
            if(nums[l]<nums[r])
            {
                res = min(res,nums[l]);
            }
            
            int mid = (l+r)/2;
            res = min(res,nums[mid]);
            
            if(nums[mid]>=nums[l])
            {
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
        return res;
        
    }
};


class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l=0,r=n-1;
        int res = INT_MAX;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[l]<=nums[r])
            {
                res = min(res,nums[l]);
                break;
            }
            else if(nums[l]<=nums[mid])
            {
                res = min(res, nums[l]);
                l = mid+1;
            }
            else
            {
                res = min(res, nums[mid]);
                r= mid-1;
            }
        }
        return res;
    }
};
/*
->At each index in this array one of the left or right subarrays will be sorted. Use that property to find the min
->if nums[l] < nums[r] that means the whole subarray considered is sorted. So update min and break
-> Else check which subarray is sorted left or right and then find the min in that subarray ie nums[l] if left is sorted or nums[mid] if right is sorted
-> Next eliminate the subarray that is sorted and look for somewhere else
*/
