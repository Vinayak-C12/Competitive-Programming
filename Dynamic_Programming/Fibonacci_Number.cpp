//LeetCode - Fibinacci Number - Easy
//https://leetcode.com/problems/fibonacci-number/description/?envType=study-plan-v2&envId=dynamic-programming

class Solution {
public:
    int fib(int n) {
        vector<int> dp(n+1,0);
        if(n == 0 || n == 1)
        {
            return n;
        }
        dp[1] = 1;
        if(n>1)
        {
        for(int i = 2;i<=n;i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        }
        return dp[n];
    }
};
