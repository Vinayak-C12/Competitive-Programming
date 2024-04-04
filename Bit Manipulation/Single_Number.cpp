//Leetcode - Single Number - Easy
//https://leetcode.com/problems/single-number/?envType=study-plan-v2&envId=top-100-liked

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(auto n:nums)
        {
            ans^=n;
        }
        return ans;
    }
};
