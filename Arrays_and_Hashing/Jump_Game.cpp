//LeetCode - Jump Game - Medium
//https://leetcode.com/problems/jump-game/description/?envType=study-plan-v2&envId=top-interview-150

class Solution {
public:
    bool canJump(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr); 
        int maxjump = nums[0];// this variable contains the max index that can be reached
        for(int i = 0;i<nums.size();i++)
        {
            if(maxjump >= nums.size()-1) // Target Reached
            {
                return true;
            }
            if(nums[i] == 0 && maxjump == i) // Cant proceed further and the max index that can be reached is i and not the last index
            {
                return false;
            }
            if(i + nums[i] > maxjump) // Updating the maxindex
            {
                maxjump = i +nums[i];
            }
        }
        return true;
    }
};
