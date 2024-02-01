//LeetCode - Subtree of another Tree - Easy
//https://leetcode.com/problems/subtree-of-another-tree/description/

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
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if(subRoot == NULL)
        {
            return true;
        }
        if(root == NULL)
        {
            return false;
        }
        if(sametree(root, subRoot))
        {
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
private:
    bool sametree(TreeNode* root, TreeNode* subtree)
    {
        if(root == NULL && subtree == NULL)
        {
            return true;
        }
        if(root == NULL || subtree == NULL)
        {
            return false;
        }
        if(root->val != subtree->val)
        {
            return false;
        }
        return sametree(root->left,subtree->left) && sametree(root->right, subtree->right);
    }
};
