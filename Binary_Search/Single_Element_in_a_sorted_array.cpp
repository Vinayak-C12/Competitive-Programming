//Leetcode - Single Element in a Sorted Array - Medium - Striver
//https://leetcode.com/problems/single-element-in-a-sorted-array/description/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
        {
            return nums[0];
        }
        if(nums[0] != nums[1])
        {
            return nums[0];
        }
        if(nums[n-1] != nums[n-2])
        {
            return nums[n-1];
        }
        int l=1,r=n-2;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid] != nums[mid+1])
            {
                return nums[mid];
            }
            else if(mid%2 == 0 && nums[mid] == nums[mid+1] || mid%2 == 1 && nums[mid] == nums[mid-1])
            {
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
        return -1;
    }
};


/*
LOGIC:
->This can be done using XOR but it is not log(n)
->Single element will have different elements on either side which is the test condition
->First sort out the edge cases. Then your search space will be from 1 to n-2
->Since the bs must be used we need to be able to identify the halves which we are in
->A single element will always have even number of elements to either side if it. Left partition will have the index as (even,odd) and the right partition will have the index pair as (odd,even)
->Identify the partition using the above rule and move to the right if u r in left partitin and vice-versa
*/
