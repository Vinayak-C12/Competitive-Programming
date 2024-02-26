//LeetCode - Find Pivot Index - Easy
//https://leetcode.com/problems/find-pivot-index/description/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        for(int i=1;i<n;i++)
        {
            right += nums[i];
        }
        for(int i=0;i<n;i++)
        {
            if(left == right)
            {
                return i;
            }
            else
            {
                left += nums[i];
                
                if(i == n-1) 
                {
                    right = 0;
                }
                else
                {
                    right -= nums[i+1];
                }
            }
        }
        return -1;
    }
};
