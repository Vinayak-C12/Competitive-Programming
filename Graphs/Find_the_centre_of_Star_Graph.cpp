//Leetcode - Find Center of Star Graph - Easy
//https://leetcode.com/problems/find-center-of-star-graph/description/?envType=daily-question&envId=2024-06-27

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]?edges[0][0]:edges[0][1];
    }
};
