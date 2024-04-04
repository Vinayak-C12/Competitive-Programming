//Leetcode - Max Nesting Depth of Parenthesis - Easy
//https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int count = 0;
        // int max_num = ge0;
        for(auto c :s)
        {
            if(c == '(')
            {
                count++;
                max_num = max(max_num, count);
            }
            else if(c == ')')
            {
                count--;
            }
        }
        return max_num;
    }
};
