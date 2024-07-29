//Leetcode - Rotten Oranges - Medium
//https://leetcode.com/problems/rotting-oranges/description/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty())
        {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> rotten;
        int days=0,tot=0,rcount=0;
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] != 0)
                {
                    tot++;
                }
                if(grid[i][j] == 2)
                {
                    rotten.push({i,j});
                }
            }
        }
        while(!rotten.empty())
        {
            int k = rotten.size();
            rcount += k;
            while(k--)
            {
                int x = rotten.front().first;
                int y = rotten.front().second;
                rotten.pop();
                for(int i=0;i<4;i++)
                {
                    int nx = x+dx[i];
                    int ny =y+dy[i];
                    if(nx<0 || ny<0 || nx>=m ||ny>=n || grid[nx][ny] != 1)
                    {
                        continue;
                    }
                    else
                    {
                        grid[nx][ny] = 2;
                        rotten.push({nx,ny});
                    }
                }
            }
            if(!rotten.empty())
            {
                days++;
            }
        }
        return rcount == tot? days:-1;
    }
};

/*
Logic:
-> The idea is to use bfs to find the number of days it takes for the oranges to rot
-> First count the total number of oranges and add the indices of the rotten oranges to thr queue
-> Add the rotten oranges count to rcount ie size of queue
-> Next for each rotten orange check in 4 directions if there is a fresh orange present. If yes add it into the queue. And pop the rotten orange that is used
-> Next check if the queue is empty, if it is not then increment the number of days as there are still rotten oranges left for  the next day
-> Next check if the rcount is same as the total orange count, if yes return days as it means that all the oranges have been rotten. If not then some fresh oranges are still left and not all oranges could be rotten and return -1
*/
