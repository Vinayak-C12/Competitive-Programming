//Leetcode - Number of Islands - Medium
//https://leetcode.com/problems/number-of-islands/?envType=daily-question&envId=2024-04-19

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        if(grid.empty() || grid[0].empty())
        {
            return 0;
        }
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == '1')
                {
                    count++;
                }
                dfs(grid,i,j);
            }
        }
        return count;
    }
private:
void dfs(vector<vector<char>>& mat, int r, int c)
{
    if(r<0 || r >=mat.size() || c<0 || c >= mat[0].size() || mat[r][c] != '1')
    {
        return;
    }
    mat[r][c] = '0';
    dfs(mat,r+1,c);
    dfs(mat,r-1,c);
    dfs(mat,r,c+1);
    dfs(mat,r,c-1);
}
};
