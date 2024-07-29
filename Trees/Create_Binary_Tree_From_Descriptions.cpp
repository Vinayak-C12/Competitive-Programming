//Leetcode - Create Binary Tree From Descriptions - Medium
///**
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
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> um;
        unordered_set<int> children;
        for(auto& arr:descriptions)
        {
            int parent = arr[0],child = arr[1],isleft = arr[2];
            children.insert(child);
            if(um.find(parent) == um.end())
            {
                um[parent] = new TreeNode(parent);
            }
            if(um.find(child) == um.end())
            {
                um[child] = new TreeNode(child);
            }
            if(isleft == 1)
            {
                um[parent]->left = um[child];
            }
            else
            {
                um[parent]->right = um[child];
            }
        }
        int root = -1;
        for(auto&arr :descriptions)
        {
            if(children.find(arr[0]) == children.end())
            {
                root = arr[0];
                break;
            }
        }
        return um[root];
    }
};

/*
Logic:
-> Use a map to store the nodes
-> Keep a set to store all the children
-> Iterate and add the child to the set and create nodes for parent and children if they r not there in the hashmap
-> Then add the child as left or right child of the parent accordingly
-> Next the element that is not present in the set is the root
-> Return the root node 
*/
