//LeetCode - Pascal's Triangle - Easy
//https://leetcode.com/problems/pascals-triangle/description/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<vector<int>> res(numRows);
        for(int i = 0;i < numRows;i++)
        {
            res[i].resize(i+1);
            for(int j = 0; j <= i;j++)
            {
                if(j == 0 || j == i)
                {
                    res[i][j] = 1;
                }
                else
                {
                    res[i][j] = res[i-1][j-1] + res[i-1][j];
                }
            }
        }
        return res;
    }
};
