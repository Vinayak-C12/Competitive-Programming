//Leetcode - Out of Boundary Paths - Medium
//https://leetcode.com/problems/out-of-boundary-paths/?envType=daily-question&envId=2024-01-26

class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<vector<int>> dp(m, vector<int> (n,0));
        int MOD = 1e9 +7;
        for(int k = 1;k<maxMove+1;k++)
        {
            vector<vector<int>> temp(m,vector<int> (n,0));
            for(int r = 0;r<m;r++)
            {
                for(int c =0;c<n;c++)
                {
                    if(r+1 == m)
                    {
                        temp[r][c] = (temp[r][c] + 1) % MOD;
                    }
                    else
                    {
                        temp[r][c] = (temp[r][c] + dp[r+1][c]) % MOD;
                    }
                    if(r-1 < 0)
                    {
                        temp[r][c] = (temp[r][c] + 1) % MOD;
                    }
                    else
                    {
                        temp[r][c] = (temp[r][c] + dp[r-1][c]) % MOD;
                    }
                    if(c+1 == n)
                    {
                        temp[r][c] = (temp[r][c] + 1) % MOD;
                    }
                    else
                    {
                        temp[r][c] = (temp[r][c] + dp[r][c+1]) % MOD;
                    }
                    if(c-1 < 0)
                    {
                        temp[r][c] = (temp[r][c] + 1) % MOD;
                    }
                    else
                    {
                        temp[r][c] = (temp[r][c] + dp[r][c-1]) % MOD;
                    }
                }
            }
            dp = temp;
        }
        
        return dp[startRow][startColumn];
        
    }
};
