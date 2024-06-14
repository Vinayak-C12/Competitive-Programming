//Leetcode - Find Peak Element - Medium - Striver
//https://leetcode.com/problems/find-peak-element/description/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 || nums[0]>nums[1])
        {
            return 0;
        }
        if(nums[n-1]>nums[n-2])
        {
            return n-1;
        }
        int l=1,r=n-2;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1])
            {
                return mid;
            }
            else if(nums[mid-1]>nums[mid+1])
            {
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return 0;
    }
};


/*
->Logic:
->Peak element will be greater than neighbouring elements
->Handle the 3 edges cases first ie first element, last element and array of size 1. Search space will be form 1 to n-2
->Check if mid is the peak element
->if not check which of its neighbouring elements is greater and move towards that side as it might lead to peak. Imagine it graphically
*/ 
