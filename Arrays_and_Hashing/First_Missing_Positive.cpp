//Leetcode - First Missing Positive - Hard
//https://leetcode.com/problems/first-missing-positive/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int val=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0)
            {
                nums[i]=0;
            }
        }
        for(int i=0;i<n;i++)
        {
            val=abs(nums[i]);
            if(val>=1&&val<=n)
            {
                if(nums[val-1]>0)
                {
                    nums[val-1]*=-1;
                }
                else if(nums[val-1]==0)
                {
                    nums[val-1]=-(n+1);
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(nums[i-1]>=0)
            {
                return i;
            }
        }
        return n+1;
        
        
    }
};
