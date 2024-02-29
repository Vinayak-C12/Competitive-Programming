//Leetcode - Find left bottom tree value - Medium
//https://leetcode.com/problems/find-bottom-left-tree-value/?envType=daily-question&envId=2024-02-28

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int last=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int count=q.size();
            for(int i=0;i<count;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(i==0)
                    last=curr->val;     //last leftMost val
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }
        return last;
    }
};
