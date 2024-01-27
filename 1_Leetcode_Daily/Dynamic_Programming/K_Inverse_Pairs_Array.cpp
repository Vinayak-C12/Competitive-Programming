//Leetcode - K Inverse Pairs Array -  Hard
//https://leetcode.com/problems/k-inverse-pairs-array/description/?envType=daily-question&envId=2024-01-27

//APPROACH - 1 : Using 1D Vector - Beats 77%

class Solution {
private:
int getmax(int p) // Bcoz the k maxes at summation(n-1)
{
    int res = 0;
    for(int i = 1;i<p;i++)
    {
        res += i;
    }
    return res;
}
public:
    int kInversePairs(int n, int k) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int MOD = 1e9 + 7;
        int max = getmax(n);
        if(k == 0)
        {
            return 1;
        }
        if(k>max)
        {
            return 0;
        }
        max = k;
        vector<int> dp(max+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            vector<int> temp(max+1, 0);
            temp[0] = 1;
            int p = 0;
            for(int j = 1; j <= max; j++)// Draw the table to understand the intuition better. Draw all permutations and find the number of inverse pairs in them and tabulate the number of occurences of k inverse pairs. There is a realtion between them in the next iteration in the prev iteration 
            {
               temp[j] = (temp[j-1] + dp[j]) % MOD;
               if(j >= i)
               {
                temp[j] = (temp[j] - dp[j-i] + MOD) % MOD;// MOD is added to make sure that the sum is not negative
               }
            }
            dp = temp;
        }
        return dp[k]%MOD;
    }
};


//APPROACH - 2 : Using 2D Vectors - Beats 64%

class Solution {
private:
int getmax(int p)
{
    int res = 0;
    for(int i = 1;i<p;i++)
    {
        res += i;
    }
    return res;
}
public:
    int kInversePairs(int n, int k) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int MOD = 1e9 + 7;
        int max = getmax(n);
        if(k == 0)
        {
            return 1;
        }
        if(k>max)
        {
            return 0;
        }
        max = k;
        vector<vector<int>> dp(n+1, vector<int> (max+1,0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++)
        {
            dp[i][0] = 1;
            for(int j = 1; j <= max; j++)
            {
               dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % MOD;
               if(j >= i)
               {
                dp[i][j] = (dp[i][j] - dp[i-1][j-i] + MOD) % MOD;
               }
            }
        }
        return dp[n][k]%MOD;
    }
};
