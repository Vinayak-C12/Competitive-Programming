//Geeksforgeeks - BFS of a Graph - Medium
//https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> bfs;
        int visited[V] = {0};
        queue<int> q;
        visited[0] = 1;
        q.push(0);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for(auto n:adj[node])
            {
                if(!visited[n])
                {
                    visited[n] = 1;
                    q.push(n);
                }
            }
        }
        return bfs;
    }
};
