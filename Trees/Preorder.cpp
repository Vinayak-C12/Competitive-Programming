//Leetcode - Preorder - Easy
//https://leetcode.com/problems/binary-tree-preorder-traversal/description/

class Solution {
private:
    vector<int> res;
    void preorder(TreeNode* root)
    {
        if(root != nullptr)
        {
            res.push_back(root->val);
            preorder(root->left);
            preorder(root->right);
        }
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        preorder(root);
        return res;
    }
};
