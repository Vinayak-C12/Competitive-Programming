//Leetocode - Spiral Matrix - Medium
//https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<int> res;
        if(matrix.empty()||matrix[0].empty())
        {
            return res;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int l = 0;
        int r = n-1;
        int t = 0;
        int b = m-1;
        
        
        while(l<=r && t<=b)
        {
            for(int i=l;i<=r;i++)
            {
                res.push_back(matrix[t][i]);
            }
            t++;
            for(int i=t;i<=b;i++)
            {
                res.push_back(matrix[i][r]);
            }
            r--;
            if(t<=b)
            {
                for(int i=r;i>=l;i--)
                {
                    res.push_back(matrix[b][i]);
                }
                b--;
            }
            if(l<=r)
            {
                for(int i=b;i>=t;i--)
                {
                    res.push_back(matrix[i][l]);
                }
                l++;
            }
        }
        return res;
        
    }
};
