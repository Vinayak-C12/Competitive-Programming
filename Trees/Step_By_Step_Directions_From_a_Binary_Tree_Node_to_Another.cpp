//Leetcode - Step-By-Step Directions From a Binary Tree Node to Another - Medium
//https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/description/?envType=daily-question&envId=2024-07-16

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
    bool path(TreeNode* root,int n,string &p) // Note that this dfs function return the path in reverse from root to source/dest. Trace the function to see that
    {
        if(root->val == n)
        {
            return true;
        }
        if(root->left && path(root->left,n,p))
        {
            p.push_back('L');
        }
        else if(root->right && path(root->right,n,p))
        {
            p.push_back('R');
        }
        return !p.empty();
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string s = "";
        string d = "";
        path(root,startValue,s);
        path(root,destValue,d); 
        while(!s.empty() && !d.empty() && s.back() == d.back())
        {
            s.pop_back();
            d.pop_back();
        }
        return string(s.size(),'U') + string(rbegin(d),rend(d));
    }
};

/*
Logic:
-> First find the path to source and dest using dfs and this path will be in reverse
-> Then remove the common prefix in s and d ie pop the common characters from the end of s and d as they r in reverse
-> Next the path is obtained by appending U, s.size() times since we r tracing the path back and then reverse of d will be appended to it as it will complete the path
*/

