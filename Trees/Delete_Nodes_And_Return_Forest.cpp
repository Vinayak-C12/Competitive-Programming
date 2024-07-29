//Leetcode - Delete Nodes And Return Forest - Medium
//https://leetcode.com/problems/delete-nodes-and-return-forest/description/?envType=daily-question&envId=2024-07-17

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
    bool set[1001] = {};
    void dfs(TreeNode* &root,bool flag,vector<TreeNode*>& res) // Flag is used to indicate if the previous node is to be deleted or not
    {
        if(root == NULL)
        {
            return;
        }
        dfs(root->left,set[root->val],res);
        dfs(root->right,set[root->val],res);
        if(!set[root->val] && flag) // The node is to be deleted and the previous node is to be deleted. So it will be a root. Add it to res
        {
            res.push_back(root);
        }
        if(set[root->val]) // If the node is to be deleted then make it NULL 
        {
            root = NULL;
        }
    }

public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> res;
        for(int num:to_delete)
        {
            set[num] = true;
        }
        dfs(root,true,res);
        return res;
    }
};
