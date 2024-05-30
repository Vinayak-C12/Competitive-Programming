//Leetcode - Check if Array Is Sorted and Rotated - Easy
//https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i=0;i<n-1;i++) // Checking the number of breaking points. if the number of breaking points is less than or equal to 1 then the array is sorted and rotated
        {
            if(nums[i]>nums[i+1])
            {
                count++;
            }
        }
        if(nums[0]<nums[n-1])// If the array is rotated the the first element needs to be lesser than the last element
        {
            count++;
        }
        return count<=1;// Coz in a sorted array this always true.This can be considered a case of full rotation
    }
};
