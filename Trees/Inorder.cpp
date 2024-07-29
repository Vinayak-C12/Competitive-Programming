//Leetcode - Inorder - Easy
//https://leetcode.com/problems/binary-tree-inorder-traversal/description/

class Solution {
private:
    void inorder(TreeNode* root,vector<int> &res)
    {
        if(root != nullptr)
        {
            inorder(root->left,res);
            res.push_back(root->val);
            inorder(root->right,res);
        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root,res);
        return res;
    }
};
