//Leetcode - Number of Provinces - Medium
//https://leetcode.com/problems/number-of-provinces/description/

class Solution {
private:
    void dfs(int node,vector<int> list[],vector<int> &vis)
    {
        vis[node] = 1;
        for(auto it:list[node])
        {
            if(!vis[it])
            {
                dfs(it,list,vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> list[n+1];
        vector<int> vis(n+1,0);
        int count = 0;
        for(int i=0;i<n;i++) // Create an adjacency list
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j] == 1 && i!=j)
                {
                    list[i+1].push_back(j+1);
                    list[j+1].push_back(j+1);
                }
            }
        }
        for(int i=1;i<=n;i++) // dfs
        {
            if(!vis[i])
            {
                count++;
                dfs(i,list,vis);
            }
        }
        return count;
    }
};

/*
Logic:
-> The idea behind the solution is that the number if provinces is the number of dfs called
-> Since once we start dfs we cover all the connected nodes so the count of the number of times dfs is called will give us the count of provinces
-> Create an adjacency list and then perform dfs
*/
