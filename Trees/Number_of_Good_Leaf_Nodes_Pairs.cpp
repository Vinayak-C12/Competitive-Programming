//Leetcode - Number of Good Leaf Nodes Pairs - Medium
//https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/description/?envType=daily-question&envId=2024-07-18

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<int> dfs(TreeNode* root,int distance,int &cnt) // Returns a vector with distances to leaf nodes from a node
    {
        if(!root) return {0};
        if(!root->left && !root->right) return {1}; // Leaf node found return the distance to its parent as 1

        vector<int> left = dfs(root->left,distance,cnt); // Distances to left subtree leaf nodes
        vector<int> right = dfs(root->right,distance,cnt); // Distances to right subtree nodes

        for(int x : left){
            for(int y:right){
                if(x>0 && y>0)
                {
                    if(x+y<=distance) cnt++; // Check if the distance is wthin limit and increment count
                }
            }
        }
        vector<int> ans; // Vector to send distances to parent 
        for(int x:left)
        {
            if(x>0 && x<distance) // Checking if the length x is within limits
            {
                ans.push_back(x+1); // If the distance to child is x then for the parent it will be x+1
            }
        }
        for(int y:right) // Same for right leaf node distances
        {
            if(y>0 && y<distance)
            {
                ans.push_back(y+1);
            }
        }
        return ans;
    }
public:
    int countPairs(TreeNode* root, int distance) {
        int cnt = 0;
        dfs(root,distance,cnt);
        return cnt;
    }
};

