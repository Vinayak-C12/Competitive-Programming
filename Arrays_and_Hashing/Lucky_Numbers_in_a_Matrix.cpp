//Leetcode -  Lucky Numbers in a Matrix - Easy
//https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/?envType=daily-question&envId=2024-07-19

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        vector<int> rowmin;
        vector<int> colmax;
        for(auto row:matrix)
        {
            rowmin.push_back(*min_element(row.begin(),row.end()));
        }
        for(int i=0;i<n;i++)
        {
            int temp = INT_MIN;
            for(int j=0;j<m;j++)
            {
                if(matrix[j][i]>temp)
                {
                    temp = matrix[j][i];
                }
            }
            colmax.push_back(temp);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j] == rowmin[i] && matrix[i][j] == colmax[j])
                {
                    res.push_back(matrix[i][j]);
                }
            }
        }
        return res;
    }
};
