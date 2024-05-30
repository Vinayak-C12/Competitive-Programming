//Leetcode - Rotate Image - Medium
//https://leetcode.com/problems/rotate-image/description/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};


LOGIC:

If we observe the original matrix and the rotated matrix we see that the first row of the rotated matrix is obtained after taking transpose of the first column of the original matrix and then reversing the first row
->So the approach would be to first take the transpose 
->Then reverse each row of the matrix. This will give the rotated matrix
