//Find if path exists in graph - Easy
//https://leetcode.com/problems/find-if-path-exists-in-graph/description/?envType=daily-question&envId=2024-04-21

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> graph;
        for(const auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> visited;
        return dfs(source,destination,graph,visited);
    }
    bool dfs(int node,int destination,unordered_map<int,vector<int>>& graph,unordered_set<int>& visited)
    {
        if(node == destination)
        {
            return true;
        }
        visited.insert(node);
        for(int x:graph[node])
        {
            if(visited.find(x) == visited.end())
            {
                if(dfs(x,destination,graph,visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
};
