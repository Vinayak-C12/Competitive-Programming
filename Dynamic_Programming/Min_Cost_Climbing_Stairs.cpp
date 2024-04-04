//LeetCode - Min Cost Climbing Stairs - Medium
//https://leetcode.com/problems/min-cost-climbing-stairs/description/?envType=study-plan-v2&envId=dynamic-programming

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,0);
        for(int i=0;i<n;i++)
        {
            if(i<2)
            {
                dp[i] = cost[i];
            }
            else
            {
                dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
            }
        }
        return min(dp[n-1],dp[n-2]);
    }
};
