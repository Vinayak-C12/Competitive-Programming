//LeetCode - Rearrange Array elements by Sign - Medium
//https://leetcode.com/problems/rearrange-array-elements-by-sign/description/?envType=daily-question&envId=2024-02-14

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,0);
        int pos = 0;
        int neg = 1;
        for(int i =0;i<n;i++)
        {
            if(nums[i]>=0)
            {
                res[pos] = nums[i];
                pos = pos +2;
            }
            else
            {
                res[neg] = nums[i];
                neg = neg +2;
            }
        }
        return res;
    }
};
