//Leetcode - Set Metrix Zeroes - Medium
//https://leetcode.com/problems/set-matrix-zeroes/description/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_set<int> r,c;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j] == 0)
                {
                    r.insert(i);
                    c.insert(j);
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            if(r.count(i) != 0)
            {
                for(int j=0;j<n;j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int j=0;j<n;j++)
        {
            if(c.count(j) != 0)
            {
                for(int i=0;i<m;i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
