//LeetCode - Jump Game II - Medium
//https://leetcode.com/problems/jump-game-ii/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    int jump(vector<int>& nums) {
        for(int i = 1;i<nums.size();i++)
        {
            nums[i] = max(nums[i-1], i + nums[i]);
        }
        int count = 0;
        int idx = 0;
        while(idx<nums.size()-1)
        {
            count++;
            idx = nums[idx];
        }
        return count;
    }
};
