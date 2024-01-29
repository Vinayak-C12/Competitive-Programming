//Leetcode - Number of Submatrices That Sum to Target- Hard
//https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/description/?envType=daily-question&envId=2024-01-28

class Solution
{
    public:
    Solution()
    {
        cin.tie(NULL);
        cout.tie(NULL);
        ios_base :: sync_with_stdio(false);
    }
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target)
    {
        int ans = 0;
        int n = matrix.size(), m = matrix[0].size();
        for(int left = 0 ; left < m ; left++)
        {
            vector<int>pre(n, 0);
            for(int right = left ; right < m ; right++)
            {
                for(int i = 0 ; i<n; i++)
                {
                    pre[i] += matrix[i][right];
                }

                for(int i = 0 ; i<n;i++)
                {
                    int sum = 0;
                    for(int j = i ; j<n; j++)
                    {
                        sum += pre[j];
                        if(sum == target)
                        {
                            ans += 1;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
