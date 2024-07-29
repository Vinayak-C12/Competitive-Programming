//GeeksforGeeks - Print Adjacency List - Easy
//https://www.geeksforgeeks.org/problems/print-adjacency-list-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=print-adjacency-list

class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int,int>>edges) {
        // Code here
        vector<vector<int>> res(V);
        for(auto edge:edges)
        {
            int u = edge.first;
            int v = edge.second;
            res[u].push_back(v);
            res[v].push_back(u);
        }
        return res;
    }
};
