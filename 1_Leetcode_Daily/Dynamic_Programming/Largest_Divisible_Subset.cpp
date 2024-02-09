//LeetCode - Largest Divisible subset - Medium
//https://leetcode.com/problems/largest-divisible-subset/description/?envType=daily-question&envId=2024-02-09

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(nums.size(),vector<int> ()); // Contains the max subsets staring from that index
        vector<int> res;

        for(int i = nums.size() -1; i>=0;i--)
        {
            dp[i].push_back(nums[i]); // Creating a vector starting at that index
            for(int j = i+1 ; j<nums.size();j++)
            {
                if(nums[j] % nums[i] == 0 && dp[i].size() < dp[j].size() + 1)
                {
                    dp[i] = dp[j];
                    dp[i].push_back(nums[i]);
                }/
            }
            if(dp[i].size() > res.size())
            {
                res = dp[i];
            }
        }
        return res;
    }
};

