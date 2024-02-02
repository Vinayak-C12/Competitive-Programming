//LeetCode - Missing Number - Easy
//https://leetcode.com/problems/missing-number/description/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = nums.size();
        int act_sum = n*(n+1)/2;
        int sum = 0;
        for(auto n : nums)
        {
            sum += n;
        }
        return act_sum - sum;       
    }
};
