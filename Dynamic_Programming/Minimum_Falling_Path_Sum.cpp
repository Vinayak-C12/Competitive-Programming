//Leetcode - Minimum Falling Path Sum - Medium
//https://leetcode.com/problems/minimum-falling-path-sum/description/?envType=daily-question&envId=2024-01-19

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> res(m,vector<int> (n));
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(i==0)
                {
                    res[i][j] = matrix[i][j];
                }
                else if(j == 0)
                {
                    res[i][j] = min(res[i-1][j]+matrix[i][j],res[i-1][j+1]+matrix[i][j]);
                }
                else if(j == n-1)
                {
                    res[i][j] = min(res[i-1][j]+matrix[i][j],res[i-1][j-1]+matrix[i][j]);
                }
                else
                {
                    int a = min(res[i-1][j-1]+matrix[i][j],res[i-1][j]+matrix[i][j]);
                    res[i][j] = min(a,res[i-1][j+1]+matrix[i][j]);
                }
            }
        }
        return *min_element(res[n-1].begin(),res[n-1].end());
        
    }
};
