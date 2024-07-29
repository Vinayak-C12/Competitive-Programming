//GeeksforGeeks - DFS of a graph - Easy
//https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

class Solution {
  private:
   void dfs(int node,vector<int> adj[],vector<int> &vis,vector<int> &res)
   {
       vis[node] = 1;
       res.push_back(node);
       for(auto it:adj[node])
       {
           if(!vis[it])
           {
               dfs(it,adj,vis,res);
           }
       }
   }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        vector<int> res;
        dfs(0,adj,vis,res);
        return res;
    }
};


