//Leetcode - Postorder - Easy
//https://leetcode.com/problems/binary-tree-postorder-traversal/description/

class Solution {
private:
    void postorder(TreeNode* root,vector<int> &res)
    {
        if(root != nullptr)
        {
            postorder(root->left,res);
            postorder(root->right,res);
            res.push_back(root->val);
        }
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root,res);
        return res;
    }
};
