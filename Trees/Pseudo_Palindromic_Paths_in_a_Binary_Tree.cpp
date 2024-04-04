//Leetcode - Pseudo Palindromic Paths in a Binary Tree - Medium
//https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/?envType=daily-question&envId=2024-01-24

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
 static const int fast_io = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
private:
    void dfs(TreeNode* root,int palindrome) // DFS function
    {
        if((1<<(root->val))&palindrome)// Cgecking if the palindrome aleady has the value
        {
            palindrome^= (1<<root->val);// XOR used for toggling bits
        }
        else
        {
            palindrome|= (1<<root->val);// If not present just add to the palindrome
        }
        if(root->left == NULL && root->right == NULL)// Base case
        {
            int pop = __builtin_popcount(palindrome);
            if(pop == 0 || pop == 1)// If the number of 1s is 0 or 1 it is a palindrome
            {
                count++;// Increment the count 
            }
            return;
        }
        if(root->left)// Traverse the left subtree
        {
            dfs(root->left,palindrome);
        }
        if(root->right)// Traverse the right subtree
        {
            dfs(root->right,palindrome);
        }
    }
public:
    int count;// It needs to be public memeber to be accesible by the private member
    int pseudoPalindromicPaths (TreeNode* root) {
        count = 0;
        int palindrome = 0;
        palindrome|= (1<<root->val);// Add the first root element 
        if(root->left == NULL && root->right == NULL)// only root present
        {
            return 1;
        }
        if(root->left)// Go left
        {
            dfs(root->left,palindrome);
        }
        if(root->right)// Go right
        {
            dfs(root->right,palindrome);
        }
        return count;
        
    }
};
