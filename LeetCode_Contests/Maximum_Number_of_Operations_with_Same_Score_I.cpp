//LeetCode Contest - Biweekly Contest 124 - Feb 17 2024

//https://leetcode.com/contest/biweekly-contest-124/problems/maximum-number-of-operations-with-the-same-score-i/

//3038. Maximum Number of Operations With the Same Score I - Easy

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 1;
        int sum = nums[0] + nums[1];
        for(int i=2;i<n;i = i+2)
        {
            if(nums[i] + nums[i+1] == sum)
            {
                count++;
            }
            else
            {
                break;
            }
        }
        return count;
    }
};
