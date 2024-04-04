//Leetcode - House Robber - Medium
//https://leetcode.com/problems/house-robber/description/?envType=daily-question&envId=2024-01-21

class Solution {
public:
    int rob(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        if(nums.empty())
        {
            return 0;
        }
        if(n == 1)
        {
            return dp[0];
        }
        dp[1] = max(nums[0],nums[1]);
        
        if(n == 2)
        {
            return  dp[1];
        }
        for(int i = 2;i<n;i++)
        {
            if(i%2 == 1)
            {
                int a = max(dp[i-3]+nums[i],dp[i-1]);
                dp[i] = max(a, dp[i-2]+nums[i]);
            }
            else
            {
                dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
            }
        }
        return dp[n-1];
        
    }
};

//Solution 2 : More Concise

class Solution {
public:
    int rob(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = nums.size();
        vector<int> dp(n+1,0);
        if(n==1)
        {
            return nums[0];
        }
        dp[1] = nums[0];
        for(int i = 2;i<=n;i++)
        {
            dp[i] = max(dp[i-1],dp[i-2]+nums[i-1]);
        }
        return dp[n];
        
    }
};
