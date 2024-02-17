//LeetCode - Flood Fill - Easy
//https://leetcode.com/problems/flood-fill/description/

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldcolor = image[sr][sc];
        if(oldcolor == color)
        {
            return image;
        }
        dfs(image,sr,sc,oldcolor,color);
        return image;
    }
private:
    void dfs(vector<vector<int>> &image, int i,int j, int oldcolor, int color)
    {
        int row = image.size();
        int col = image[0].size();
        if(i<0 ||j<0 ||i>=row||j>=col || image[i][j] != oldcolor)
        {
            return ;
        }
        image[i][j] = color;
        dfs(image,i+1,j,oldcolor,color);
        dfs(image,i-1,j,oldcolor,color);
        dfs(image,i,j+1,oldcolor,color);
        dfs(image,i,j-1,oldcolor,color);        
    }
};
